package basics;

public class BasicTypes {
    public static void main(String[] args) {
        byte x = 10;

        // Podemos utilizar sequências de escape unicode podem serem utilizadas em
        // outras partes
        // do programa, incluindo variáveis.
        byte \u1F60F = 10;

        // As strings e chars no java são codificadas com utf 16.

        // Sequências de escape:
        // - \b: backspace
        // - \t: tab
        // - \n: newline
        // - \f: form feed
        // - \r: carriage return
        // - \'
        // - \\: backslash
        // - \"

        // Podemos ter um literal `null` que pode ser utilizado para qualquer tipo de
        // referência.
        // `null` pode ser atribuído a qualquer variável menos as de tipo primitivo.

        // Class literals tormam a forma de `<typename>.class`.
        // Exemplo: `String.class` refere-se ao objeto que representa o próprio tipo,
        // sendo da classe `Class`.

        // Underscores podem serem utilizados para agrupar dígitos em números.
        long myPhoneNumber = 123_456_789L;
        int allowed = 1_________________________________________________2;
    }
}