package Naousados;
import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Random;

public class ExportSemiRandomArrayToFile {

    public static void main(String[] args) {
        int size = 1000001; // De 0 a 1.000.000, portanto 1.000.001 posições
        int[] semiRandomArray = createSemiRandomArray(size);
        exportArrayToFile(semiRandomArray, "semi_random_array.txt");
    }

    private static int[] createSemiRandomArray(int size) {
        int[] array = new int[size];
        
        // Preencher o array com números ordenados de 0 a 1.000.000
        for (int i = 0; i < size; i++) {
            array[i] = i;
        }
        
        // Trocar 10% dos elementos com posições aleatórias
        Random random = new Random();
        int numSwaps = size / 10;
        for (int i = 0; i < numSwaps; i++) {
            int index1 = random.nextInt(size);
            int index2 = random.nextInt(size);
            int temp = array[index1];
            array[index1] = array[index2];
            array[index2] = temp;
        }
        
        return array;
    }

    private static void exportArrayToFile(int[] array, String filename) {
        try (BufferedWriter writer = new BufferedWriter(new FileWriter(filename))) {
            for (int i = 0; i < array.length; i++) {
                writer.write(array[i] + (i < array.length - 1 ? " " : ""));
            }
            System.out.println("Array exported successfully to " + filename);
        } catch (IOException e) {
            System.err.println("An error occurred while exporting the array: " + e.getMessage());
        }
    }
}
