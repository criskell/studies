// A mediator is an object that receives all object communications.
// Use cases:
// - Avoid direct dependencies.
// - Centralize the interaction logic between objects.
// - Objects communicate in complex ways.

#include <print>
#include <memory>
#include <vector>
#include <string>

class Mediator;

class Colleague
{
protected:
  Mediator *mediator;

public:
  Colleague(Mediator *m) : mediator(m) {}
  virtual void send(const std::string &msg) = 0;
  virtual void receive(const std::string &msg) = 0;
  virtual ~Colleague() = default;
};

class Mediator
{
public:
  virtual void registerColleague(std::shared_ptr<Colleague> colleague) = 0;
  virtual void broadcast(const std::string &msg, Colleague *sender) = 0;
  virtual ~Mediator() = default;
};

class ChatMediator : public Mediator
{
private:
  std::vector<std::shared_ptr<Colleague>> colleagues;

public:
  void registerColleague(std::shared_ptr<Colleague> colleague) override
  {
    colleagues.push_back(colleague);
  }

  void broadcast(const std::string &msg, Colleague *sender) override
  {
    for (const auto &c : colleagues)
    {
      if (c.get() != sender)
      {
        c->receive(msg);
      }
    }
  }
};

class User : public Colleague
{
private:
  std::string name;

public:
  User(Mediator *m, const std::string &n) : Colleague(m), name(n) {}

  void send(const std::string &msg) override
  {
    std::println("{} sent: {}", name, msg);
    mediator->broadcast(msg, this);
  }

  void receive(const std::string &msg) override
  {
    std::println("{} received: {}", name, msg);
  }
};

int main()
{
  auto chat = std::make_shared<ChatMediator>();

  auto eren = std::make_shared<User>(chat.get(), "Eren");
  auto mikasa = std::make_shared<User>(chat.get(), "Mikasa");
  auto armin = std::make_shared<User>(chat.get(), "Armin");

  chat->registerColleague(eren);
  chat->registerColleague(mikasa);
  chat->registerColleague(armin);

  mikasa->send("EREHHHHHHHHHHHHHHH");
  eren->send("ARMIIHHHHHHH");
}