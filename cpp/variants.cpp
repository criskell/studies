#include <algorithm>
#include <print>
#include <string>
#include <variant>
#include <vector>

using VariedVector = std::
    variant<std::vector<int>, std::vector<std::string>, std::vector<float>>;

int main() {
  // Alternativa mais segura que union.
  // Armazena um valor que pode ser de vários tipos diferentes, mas só um por
  // vez.
  std::variant<int, float, std::string> v;

  v = 42;
  std::println("{}", std::get<int>(v));

  v = std::string("hello");
  std::println("{}", std::get<std::string>(v));

  if (std::holds_alternative<int>(v)) {
    std::println("É um inteiro.");
  }

  if (std::holds_alternative<std::string>(v)) {
    std::println("É uma string.");
  }

  // auto&& é uma forwarding reference
  // quando usado em funções genéricas (ex.: lambdas) significa
  // receber qualquer tipo de argumento: valor, referência, constante,
  // temporário (rvalues). preservando suas características principais. o &&
  // permite que o compilador deduza se o tipo é rvalue o lvalue. auto arg -
  // recebe uma cópia (ou move) do argumento auto& arg - recebe referência
  // lvalue auto&& arg - recebe qualquer coisa
  std::visit(
      [](auto&& arg) {
        std::println("Valor sem se preocupar com o tipo do variant: {}", arg);
      },
      v);

  std::variant<std::vector<int>, std::vector<std::string>> myData;

  myData = std::vector<int>{1, 2, 3};

  std::visit(
      [](const auto& vector) {
        std::println("Vetor contém: ");

        for (const auto& element : vector) {
          std::println(" {}", element);
        }
      },
      myData);

  myData = std::vector<std::string>{"oi", "criskell"};

  std::visit(
      [](const auto& vector) {
        std::println("Vetor agora contém: ");

        for (const auto& element : vector) {
          std::println(" {}", element);
        }
      },
      myData);

  std::vector<VariedVector> list;

  list.push_back(std::vector<int>{1, 2, 3});
  list.push_back(std::vector<std::string>{"oi", "tudo", "bem"});
  list.push_back(std::vector<float>{1.1f, 2.2f, 3.3f});

  for (const auto& item : list) {
    std::visit(
        [](const auto& vector) {
          std::println("O vetor tem tipo: {}:", typeid(vector[0]).name());

          for (const auto& element : vector) {
            std::println(" {}", element);
          }
        },
        item);

    std::println(
        "----------------------------------------------------------------");
  }
}