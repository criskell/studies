#include <mutex>
#include <print>

class Logger {
 public:
  Logger(const Logger&) = delete;
  Logger& operator=(const Logger&) = delete;

  static Logger& getInstance() {
    // Tem storage duration static
    static Logger instance;
    return instance;
  }

  void log(const std::string& message) {
    std::lock_guard<std::mutex> lock(m_lock);
    std::println("log: {}", message);
  }

 private:
  Logger() {}
  std::mutex m_lock;
};

int main() {
  Logger::getInstance().log("olá");
  Logger::getInstance().log("tudo certo?");
}