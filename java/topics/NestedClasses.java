
public class NestedClasses {

    public static void main(String[] args) {
        NestedClasses externalObj = new NestedClasses();
        NestedClasses.Internal internalObj = externalObj.new Internal("WTF");
        internalObj.hi();

        // Cria uma classe anônima que implementa a interface Runnable. 
        Runnable r = new Runnable() {
            @Override
            public void run() {
                System.out.println("Olá!");
            }
        };

        r.run();

        class LocalClass {

            void greet() {
                System.out.println("eita");
            }
        }

        new LocalClass().greet();
    }

    public class Internal {

        private final String message;

        Internal(String message) {
            this.message = message;
        }

        void hi() {
            System.out.println(message);
        }
    }
}
