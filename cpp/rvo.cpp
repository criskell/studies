#include <print>

struct MyClass {
  MyClass() { std::println("Default constructor"); }
  MyClass(const MyClass&) { std::println("Copy constructor"); }
  // MyClass(MyClass&&) { std::println("Move constructor"); }
  ~MyClass() { std::println("Destructor"); }
};

MyClass create() {
  MyClass x;
  return x;

  // Faz copy ellision.
  // return MyClass();
}

int main() {
  // RVO basicamente permita que o compilador evita a criação de objetos
  // temporários mesmo que sua criação tenha efeitos coláterais.
  // Evita a criação da cópia do objeto temporário no destino. Copy Ellision +
  // RVO. Testa compilando -fno-elide-constructors e sem.
  MyClass obj = create();
}