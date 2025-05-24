public class LazySingletonHolderIdiom {
    public static void main(String[] args) {
        LazySingleton.getInstance().test();
    }
}

// Em arquivos com múltiplas classes, só deve haver uma classe pública e essa o nome dessa
// classe deve coincidir com o nome do arquivo.
// As outras classes devem serem package-private (sem modificador de acesso)
// ou private/protected se forem internas de outra classe.
class LazySingleton {
    private LazySingleton() {}

    public void test() {
        System.out.println("Olá!");
    }

    public static LazySingleton getInstance() {
        return SINGLETON_LOADER.singleton;
    }

    // O Java só carrega e inicializa essa classe "SINGLETON_LOADER" uma vez.
    // O classloader da JVM garante que a inicialização seja thread-safe, livre de race conditions.
    // Essa é uma forma de se ter lazy singletons sem usar synchronized
    // (no método getInstance, que levaria a perca de desempenho, pois todos os acessos devem serem sincronizados, mesmo
    // quando a instância já foi inicializada)
    // e sem double-checked locking que faz uma verificação dentro do método com synchronized.
    private static class SINGLETON_LOADER {
        static final LazySingleton singleton = new LazySingleton();
    }
}