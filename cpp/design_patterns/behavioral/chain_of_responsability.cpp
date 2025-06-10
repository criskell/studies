#include <print>
#include <memory>
#include <string>

class Handler
{
public:
  virtual ~Handler() = default;

  void setNext(std::shared_ptr<Handler> next)
  {
    next_handler = next;
  }

  virtual std::string handle(const std::string &request)
  {
    if (next_handler)
    {
      return next_handler->handle(request);
    }

    return "Request not handled.";
  }

private:
  std::shared_ptr<Handler> next_handler = nullptr;
};

class LevelOneSupport : public Handler
{
public:
  std::string handle(const std::string &request) override
  {
    if (request == "level1")
    {
      return "Resolved by level 1 support.";
    }

    return Handler::handle(request);
  }
};

class LevelTwoSupport : public Handler
{
public:
  std::string handle(const std::string &request) override
  {
    if (request == "level2")
    {
      return "Resolved by level 2 support.";
    }

    return Handler::handle(request);
  }
};

int main()
{
  auto level1 = std::make_shared<LevelOneSupport>();
  auto level2 = std::make_shared<LevelTwoSupport>();

  level1->setNext(level2);

  std::println("{}", level1->handle("level1"));
  std::println("{}", level1->handle("level2"));
  std::println("{}", level1->handle("other"));
}