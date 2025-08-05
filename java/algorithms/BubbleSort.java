
public class BubbleSort {

    public static void main(String[] args) {
        int[] numbers = {5, 2, 9, 6, 3, 3};
        printArray(numbers);

        bubbleSort(numbers);
        printArray(numbers);
    }

    private static void bubbleSort(int[] array) {
        int length = array.length;
        boolean swapped = true;

        for (int i = 0; i < length - 1; i++) {
            for (int j = 0; j < length - 1 - i; j++) {
                if (array[j] > array[j + 1]) {
                    array[j] ^= array[j + 1];
                    array[j + 1] ^= array[j];
                    array[j] ^= array[j + 1];
                    swapped = true;
                }
            }

            if (!swapped) {
                break;
            }
        }
    }

    private static void printArray(int[] arr) {
        for (int value : arr) {
            System.out.println(value + " ");
        }

        System.out.println();
    }
}
