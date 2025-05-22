#include <atomic>
#include <print>

class Spinlock
{
private:
    std::atomic_flag m_flag = ATOMIC_FLAG_INIT;

public:
    void lock()
    {
        while (m_flag.test_and_set(std::memory_order_acquire))
        {
        }

        std::println("Spinlock acquired.");
    }

    void unlock()
    {
        m_flag.clear(std::memory_order_release);
        std::println("Spinlock released.");
    }
};

class SpinlockLocker
{
private:
    Spinlock &m_lock;

public:
    explicit SpinlockLocker(Spinlock &lock) : m_lock(lock)
    {
        m_lock.lock();
    }

    ~SpinlockLocker()
    {
        m_lock.unlock();
    }

    SpinlockLocker(const SpinlockLocker &) = delete;
    SpinlockLocker &operator=(const SpinlockLocker &) = delete;
};

int main()
{
    Spinlock lock;
    SpinlockLocker locker(lock);

    std::println("Test");
}
