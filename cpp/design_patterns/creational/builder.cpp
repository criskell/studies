#include <memory>
#include <print>
#include <string>

class Person {
 public:
  std::string name;
  int age = 0;
  std::string city;
  std::string occupation;

  void print() const {
    std::println("Person(name={}, age={}, city={}, occupation={})", name, age,
                 city, occupation);
  }
};

class PersonBuilder {
 private:
  std::unique_ptr<Person> person;

 public:
  PersonBuilder() : person(std::make_unique<Person>()) {}

  PersonBuilder& setName(const std::string& name) {
    person->name = name;
    return *this;
  }

  PersonBuilder& setAge(int age) {
    person->age = age;
    return *this;
  }

  PersonBuilder& setCity(const std::string& city) {
    person->city = city;
    return *this;
  }

  PersonBuilder& setOccupation(const std::string& occupation) {
    person->occupation = occupation;
    return *this;
  }

  std::unique_ptr<Person> build() { return std::move(person); }
};

int main() {
  auto person = PersonBuilder()
                    .setName("criskell")
                    .setAge(20)
                    .setCity("São Paulo")
                    .setOccupation("Software Engineer")
                    .build();

  person->print();
}