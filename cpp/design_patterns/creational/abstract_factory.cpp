#include <memory>
#include <print>

// Abstract Products
class Button {
 public:
  virtual void render() = 0;
  virtual ~Button() {}
};

class ScrollBar {
 public:
  virtual void scroll() = 0;
  virtual ~ScrollBar() {}
};

// Abstract Factory
class GUIFactory {
 public:
  virtual std::unique_ptr<Button> createButton() = 0;
  virtual std::unique_ptr<ScrollBar> createScrollBar() = 0;
  virtual ~GUIFactory() {}
};

// Concrete products: Light
class LightButton : public Button {
 public:
  void render() override { std::println("Light button rendered."); }
};

class LightScrollBar : public ScrollBar {
 public:
  void scroll() override { std::println("Light scrollbar activated."); }
};

// Concrete products: Dark
class DarkButton : public Button {
 public:
  void render() override { std::println("Dark button rendered."); }
};

class DarkScrollBar : public ScrollBar {
 public:
  void scroll() override { std::println("Dark scrollbar activated."); }
};

// Concrete factories
class LightFactory : public GUIFactory {
 public:
  std::unique_ptr<Button> createButton() override {
    return std::make_unique<LightButton>();
  }

  std::unique_ptr<ScrollBar> createScrollBar() override {
    return std::make_unique<LightScrollBar>();
  }
};

class DarkFactory : public GUIFactory {
 public:
  std::unique_ptr<Button> createButton() override {
    return std::make_unique<DarkButton>();
  }

  std::unique_ptr<ScrollBar> createScrollBar() override {
    return std::make_unique<DarkScrollBar>();
  }
};

void renderUI(std::unique_ptr<GUIFactory> factory) {
  auto button = factory->createButton();
  auto scrollBar = factory->createScrollBar();

  button->render();
  scrollBar->scroll();
}

int main() {
  std::unique_ptr<GUIFactory> factory;

  std::string theme = "dark";

  if (theme == "dark") {
    factory = std::make_unique<DarkFactory>();
  } else {
    factory = std::make_unique<LightFactory>();
  }

  renderUI(std::move(factory));
}