package Naousados;
import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;

public class ExportSortedArrayToFile {

    public static void main(String[] args) {
        int size = 1000000;
        int[] sortedArray = createSortedArray(size);
        exportArrayToFile(sortedArray, "sorted_array.txt");
    }

    private static int[] createSortedArray(int size) {
        int[] array = new int[size];
        for (int i = 0; i < size; i++) {
            array[i] = i + 1;
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
