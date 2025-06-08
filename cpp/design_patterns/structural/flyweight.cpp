#include <print>
#include <unordered_map>
#include <memory>
#include <string>
#include <vector>

// Casos de uso
// - Separação entre estado intrínseco e extrínseco.
// - Redução do uso de memória.
// - Ideal para objetos repetidos.

// Flyweight (estado intrínseco / estado compartilhado)
class TreeType
{
public:
  TreeType(const std::string &name, const std::string &color) : m_name(name), m_color(color) {}

  void draw(int x, int y)
  {
    std::println("Drawing tree. x={}, y={}, name={}, color={}", x, y, m_name, m_color);
  }

private:
  std::string m_name;
  std::string m_color;
};

// Flyweight Factory
// Garante o reuso de flyweights.
class TreeFactory
{
public:
  static std::shared_ptr<TreeType> getTreeType(const std::string &name, const std::string &color)
  {
    std::string key = name + "_" + color;

    if (m_types.find(key) == m_types.end())
    {
      m_types[key] = std::make_shared<TreeType>(name, color);
    }

    return m_types[key];
  }

private:
  // Declara o membro estático.
  static std::unordered_map<std::string, std::shared_ptr<TreeType>> m_types;
};

// Define o membro estático.
// - Informa o linker onde está o membro estático.
// - Reserva memória real.
std::unordered_map<std::string, std::shared_ptr<TreeType>> TreeFactory::m_types;

// Context (estado extrínseco)
class Tree
{
public:
  Tree(int x, int y, std::shared_ptr<TreeType> type) : m_x(x), m_y(y), m_type(type) {}

  void draw() const
  {
    m_type->draw(m_x, m_y);
  }

private:
  int m_x, m_y;
  std::shared_ptr<TreeType> m_type;
};

// Client
int main()
{
  std::vector<Tree> forest;

  // emplace_back constrói o objeto diretamente no vetor.
  forest.emplace_back(10, 20, TreeFactory::getTreeType("Carvalho", "Verde"));
  forest.emplace_back(15, 25, TreeFactory::getTreeType("Carvalho", "Verde"));
  forest.emplace_back(20, 40, TreeFactory::getTreeType("Pinheiro", "Verde-Escuro"));

  for (const auto &tree : forest)
  {
    tree.draw();
  }
}