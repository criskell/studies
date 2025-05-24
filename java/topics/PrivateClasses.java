
public class PrivateClasses {

    public static void main(String[] args) {
        Externa.usarInterna();
    }
}

class Externa {

    private static class Interna {

        static void saudacao() {
            System.out.println("Olá da classe interna!");
        }
    }

    public static void usarInterna() {
        Interna.saudacao();
    }
}
