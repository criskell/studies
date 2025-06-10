// Allow two incompatible interfaces to work together.
// The adapter converts the interface of one class into the one that the client expects.
// Use cases:
// - Integrate third-party APIs without modifying code.
// - Integrate legacy API.
// - Reusing an existing class, but its interface is not compatible with the rest of the system.

#include <print>
#include <string>
#include <memory>
#include <algorithm>

// Interface expected by the client.
class Target
{
public:
  virtual ~Target() = default;
  virtual std::string request() const
  {
    return "Target: default behaviour";
  }
};

// Existing class with incompatible interface.
class Adaptee
{
public:
  std::string specificRequest() const
  {
    std::string text = "Specific Adaptee";
    std::reverse(text.begin(), text.end());
    return text;
  }
};

// Adapter
// Converts adaptee to target.
class Adapter : public Target
{
private:
  Adaptee *adaptee;

public:
  Adapter(Adaptee *a) : adaptee(a) {}

  std::string request() const override
  {
    std::string reversed = adaptee->specificRequest();
    std::reverse(reversed.begin(), reversed.end());
    return "Adapter: (translated) " + reversed;
  }
};

int main()
{
  Adaptee *legacy = new Adaptee();
  Target *adapter = new Adapter(legacy);

  std::println("Customer: {}", adapter->request());

  delete adapter;
  delete legacy;
}