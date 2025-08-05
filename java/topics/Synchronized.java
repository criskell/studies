
public class Synchronized {

    public static void main(String[] args) throws InterruptedException {
        // Counter counter = new Counter();
        SafeCounter counter = new SafeCounter();

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

        System.out.println("Final value: " + counter.getValue());
    }
}

class Counter {

    private int value = 0;

    public void increment() {
        value++;
    }

    public int getValue() {
        return value;
    }
}

class SafeCounter {

    private int value = 0;

    // Somente uma thread pode acessar este método por vez.
    // Funciona adquirindo um bloqueio no objeto atual.
    public synchronized void increment() {
        value++;
    }

    public int getValue() {
        return value;
    }
}
