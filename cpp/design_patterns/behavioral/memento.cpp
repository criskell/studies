#include <print>
#include <string>
#include <vector>

// Armazena o estado do Originator
class Memento
{
  std::string state;
  friend class Originator;

public:
  Memento(const std::string &s) : state(s) {}
};

class Originator
{
  std::string state;

public:
  void setState(const std::string &s)
  {
    state = s;
    std::println("Current state: {}", state);
  }

  Memento save()
  {
    return Memento(state);
  }

  void restore(const Memento &memento)
  {
    state = memento.state;
    std::println("State restored to: {}", state);
  }
};

// Armazena os mementos
class Caretaker
{
  std::vector<Memento> history;

public:
  void addMemento(const Memento &m)
  {
    history.push_back(m);
  }

  Memento getMemento(int index)
  {
    return history.at(index);
  }

  int getHistorySize() const
  {
    return history.size();
  }
};

int main()
{
  Originator originator;
  Caretaker caretaker;

  originator.setState("Estado #1");
  caretaker.addMemento(originator.save());

  originator.setState("Estado #2");
  caretaker.addMemento(originator.save());

  originator.setState("Estado #3");
  caretaker.addMemento(originator.save());

  originator.restore(caretaker.getMemento(0));
  originator.restore(caretaker.getMemento(1));
  originator.restore(caretaker.getMemento(2));
}