#include <algorithm>
#include <memory>
#include <print>
#include <vector>

class Observer {
 public:
  virtual void update(int value) = 0;
  virtual ~Observer() = default;
};

// É o cara que muda de estado e notifica os observers.
class Subject {
 public:
  virtual void attach(std::shared_ptr<Observer> observer) = 0;
  virtual void detach(std::shared_ptr<Observer> observer) = 0;
  virtual void notify() = 0;
  virtual ~Subject() = default;
};

class TemperatureSensor : public Subject {
 private:
  int temperature_ = 0;
  std::vector<std::shared_ptr<Observer>> observers_;

 public:
  void setTemperature(int temperature) {
    temperature_ = temperature;
    notify();
  }

  void attach(std::shared_ptr<Observer> observer) override {
    observers_.push_back(observer);
  }

  void detach(std::shared_ptr<Observer> observer) override {
    // std::remove muda a posição dos elementos de forma que os elementos
    // diferentes de observer sejam colocados no início do vetor.
    // ele retorna um iterator que aponta para o início do lixo que sobrou.
    // o erase remove fisicamente os elementos entre o iterador retornado por
    // std::remove e observers_.end()
    observers_.erase(
        std::remove(observers_.begin(), observers_.end(), observer),
        observers_.end());
  }

  void notify() override {
    for (auto& observer : observers_) {
      observer->update(temperature_);
    }
  }
};

class TemperatureDisplay : public Observer {
 private:
  std::string name_;

 public:
  TemperatureDisplay(const std::string& id) : name_(id) {}

  void update(int value) override {
    std::println("[{}] Current temperature: {}", name_, value);
  }
};

int main() {
  auto sensor = std::make_shared<TemperatureSensor>();

  auto display1 = std::make_shared<TemperatureDisplay>("Room");
  auto display2 = std::make_shared<TemperatureDisplay>("Bedroom");

  sensor->attach(display1);
  sensor->attach(display2);

  sensor->setTemperature(25);
  sensor->setTemperature(30);

  sensor->detach(display2);
  sensor->setTemperature(28);
}