/**
 * Quando usar o Command pattern?
 *
 * - Desaclopar quem solicita uma ação de quem a executa.
 * - Encapsular uma ação como objeto.
 * - Fila de comandos e desfazer/refazer.
 */

#include <memory>
#include <print>
#include <vector>

// Receiver
// Sabe como executar as ações.
class Light {
 public:
  void turnOn() { std::println("Light turned on."); }
  void turnOff() { std::println("Light turned off."); }
};

// Command Interface
// Encapsula as ações.
class Command {
 public:
  virtual void execute() = 0;
  virtual ~Command() = default;
};

// Concrete Commands
class TurnOnCommand : public Command {
 private:
  std::shared_ptr<Light> light_;

 public:
  TurnOnCommand(std::shared_ptr<Light> light) : light_(light) {}

  void execute() override { light_->turnOn(); }
};

class TurnOffCommand : public Command {
 private:
  std::shared_ptr<Light> light_;

 public:
  TurnOffCommand(std::shared_ptr<Light> light) : light_(light) {}

  void execute() override { light_->turnOff(); }
};

// Invoker
// Ativa os comandos.
class RemoteControl {
 private:
  std::vector<std::shared_ptr<Command>> commands_;

 public:
  void addCommand(std::shared_ptr<Command> command) {
    commands_.push_back(command);
  }

  void executeCommands() {
    for (auto& command : commands_) {
      command->execute();
    }

    commands_.clear();
  }
};

// Client
// Configura tudo
int main() {
  auto light = std::make_shared<Light>();

  auto turnOn = std::make_shared<TurnOnCommand>(light);
  auto turnOff = std::make_shared<TurnOffCommand>(light);

  RemoteControl remote;

  remote.addCommand(turnOn);
  remote.addCommand(turnOff);

  remote.executeCommands();
}