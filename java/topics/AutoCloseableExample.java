
public class AutoCloseableExample {

    public static void main(String[] args) {
        try (MyResource resource = new MyResource()) {
            resource.use();
        } catch (Exception e) {
            e.printStackTrace();
        } finally {
            System.out.println("Finally block executed.");
        }
    }
}

class MyResource implements AutoCloseable {

    public void use() {
        System.out.println("Using the resource.");
    }

    @Override
    public void close() throws Exception {
        System.out.println("Resource is being closed.");
    }
}
