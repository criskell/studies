
import java.util.concurrent.atomic.AtomicInteger;

public class AtomicCounterExample {

    public static void main(String[] args) throws InterruptedException {
        AtomicCounter counter = new AtomicCounter();

        Runnable task = () -> {
            for (int i = 0; i < 1000; i++) {
                counter.increment();
            }
        };

        Thread thread1 = new Thread(task);
        Thread thread2 = new Thread(task);
        Thread thread3 = new Thread(task);

        thread1.start();
        thread2.start();
        thread3.start();

        thread1.join();
        thread2.join();
        thread3.join();

        System.out.println("Final value with atomic counter: " + counter.getValue());
    }
}

class AtomicCounter {

    // AtomicInteger é uma classe que permite operações atômicas em inteiros.
    // Ela garante thread safety sem a necessidade de locks (o que é mais rápido!).
    private final AtomicInteger count = new AtomicInteger(0);

    public int increment() {
        return count.incrementAndGet();
    }

    public int getValue() {
        return count.get();
    }
}
