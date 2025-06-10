// The State pattern allows us to change the behavior of an object as its internal state changes.
// It will appear as if the object has changed class.

#include <print>
#include <memory>
#include <string>

class State;
class Context;

// State Interface
class State
{
public:
  virtual ~State() = default;
  virtual void handle(Context &context) = 0;
  virtual std::string name() const = 0;
};

// Context that changes state.
class Context
{
private:
  std::shared_ptr<State> current_state;

public:
  Context(std::shared_ptr<State> state) : current_state(state) {}

  void set_state(std::shared_ptr<State> state)
  {
    current_state = state;
  }

  void request()
  {
    current_state->handle(*this);
  }

  void show_state()
  {
    std::println("Current state: {}", current_state->name());
  }
};

// Concrete states

class PlayingState : public State
{
public:
  void handle(Context &context) override;
  std::string name() const override { return "Playing"; }
};

class PausedState : public State
{
public:
  void handle(Context &context) override;
  std::string name() const override { return "Paused"; }
};

class StoppedState : public State
{
public:
  void handle(Context &context) override;
  std::string name() const override { return "Stopped"; }
};

void PlayingState::handle(Context &context)
{
  std::println("Pausing music...");
  context.set_state(std::make_shared<PausedState>());
}

void PausedState::handle(Context &context)
{
  std::println("Resuming playback...");
  context.set_state(std::make_shared<PlayingState>());
}

void StoppedState::handle(Context &context)
{
  std::println("Starting playback...");
  context.set_state(std::make_shared<PlayingState>());
}

int main()
{
  auto stopped = std::make_shared<StoppedState>();
  Context player(stopped);

  player.show_state();
  player.request();
  player.show_state();
  player.request();
  player.show_state();
  player.request();
  player.show_state();
}
