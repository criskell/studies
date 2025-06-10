// The Bridge pattern allows the abstraction and implementation to both evolve independently.
// The goal is to decouple the abstraction from its implementation.
// Example:
//  - Remote control (abstraction)
//  - TV (implementation)
// The remote may work with different brands of TV without knowing how each one works.
// New TVs can be created without having to change all the remote controls.

// Use when you want to avoid a massive number of subclasses due to combining multiple dimension (types of controls x types of devices).

#include <print>
#include <memory>

// Implementor interface
// Implementation interface
class Device
{
public:
  virtual ~Device() = default;
  virtual void power_on() = 0;
  virtual void power_off() = 0;
  virtual void set_volume(int level) = 0;
};

// Concrete implementor 1
// Specific interface implementation
class TV : public Device
{
public:
  void power_on() override
  {
    std::println("TV: On");
  }

  void power_off() override
  {
    std::println("TV: Off");
  }

  void set_volume(int level) override
  {
    std::println("TV: Volume adjusted to {}", level);
  }
};

// Concrete implementor 2
// Specific interface implementation
class Radio : public Device
{
public:
  void power_on() override
  {
    std::println("Radio: On");
  }

  void power_off() override
  {
    std::println("Radio: Off");
  }

  void set_volume(int level) override
  {
    std::println("Radio: Volume adjusted to {}", level);
  }
};

// Abstraction
// Interface or base class that defines the high level of logic.
class RemoteControl
{
protected:
  std::shared_ptr<Device> device;

public:
  RemoteControl(std::shared_ptr<Device> d) : device(d) {}
  virtual ~RemoteControl() = default;

  virtual void toggle_power()
  {
    device->power_on();
  }

  virtual void volume_up()
  {
    device->set_volume(10);
  }
};

// Refined abstraction
// Specialized version of abstraction.
class AdvancedRemote : public RemoteControl
{
public:
  AdvancedRemote(std::shared_ptr<Device> d) : RemoteControl(d) {}

  void mute()
  {
    device->set_volume(0);
    std::println("Remote: Mute enabled");
  }
};

// Usage
int main()
{
  auto tv = std::make_shared<TV>();
  auto radio = std::make_shared<Radio>();

  AdvancedRemote remote_tv(tv);
  remote_tv.toggle_power();
  remote_tv.volume_up();
  remote_tv.mute();

  std::println("\n---");

  RemoteControl remote_radio(radio);
  remote_radio.toggle_power();
  remote_radio.volume_up();
}