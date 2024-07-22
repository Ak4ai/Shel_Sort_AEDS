
import java.io.*;
import java.util.*;
import java.util.stream.*;
import java.time.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        PrintWriter outfile = null;
        try {
            outfile = new PrintWriter(new FileOutputStream("output.txt", true));
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }

        System.out.print("Deseja LIMPAR o Arquivo [S/N]: ");
        char resp = Character.toUpperCase(scanner.next().charAt(0));
        if (resp == 'S') {
            Sort.limparArq();
        }

        final int repetitions = 10; // Número de repetições para cada algoritmo

        System.out.print("Deseja imprimir o vetor ordenado no terminal? [S/N]: ");
        char imprimirResp = Character.toUpperCase(scanner.next().charAt(0));
        boolean imprimir = (imprimirResp == 'S');

        System.out.print("Digite o número de elementos que deseja ler: ");
        int numElementos = scanner.nextInt();
        System.out.print("Digite o número máximo de casas (1 a 7) para os números: ");
        int maxCasas = scanner.nextInt();

        outfile.println("[ Elementos = " + numElementos + " ]");

        if (maxCasas < 1) maxCasas = 1;
        if (maxCasas > 7) maxCasas = 7;

        // Ler o vetor do arquivo
        List<Integer> arrList = Sort.lerVetor("semi_random_array.txt", numElementos, maxCasas);
        int[] arr = arrList.stream().mapToInt(i -> i).toArray();

        long[][] durations = new long[6][repetitions]; // Para armazenar as durações de cada algoritmo
        long[] totalDurations = new long[6]; // Para armazenar os tempos totais de cada algoritmo

        // Nomes dos algoritmos
        String[] algorithmNames = {
            "Shell Sort (gaps padrão)",
            "Shell Sort (gaps de Hibbard)",
            "Shell Sort (gaps de Sedgewick)",
            "Shell Sort (gaps de Tokuda)",
            "Shell Sort (gaps de Ciura)",
            "Shell Sort (gaps de Knuth)"
        };

        for (int r = 0; r < repetitions; r++) {
            // Clonar o vetor original para evitar influência de ordenações anteriores
            int[] clonedArr = arr.clone();
            long startTime = System.nanoTime();
            Sort.shellSort(clonedArr);
            long duration = System.nanoTime() - startTime;
            durations[0][r] = duration;
            totalDurations[0] += duration;
            if (imprimir) {
                System.out.print("Shell Sort (gaps padrão): ");
                Sort.printArray(clonedArr);
            }

            clonedArr = arr.clone();
            startTime = System.nanoTime();
            Sort.shellSortHibbard(clonedArr);
            duration = System.nanoTime() - startTime;
            durations[1][r] = duration;
            totalDurations[1] += duration;
            if (imprimir) {
                System.out.print("Shell Sort (gaps de Hibbard): ");
                Sort.printArray(clonedArr);
            }

            clonedArr = arr.clone();
            startTime = System.nanoTime();
            Sort.shellSortSedgewick(clonedArr);
            duration = System.nanoTime() - startTime;
            durations[2][r] = duration;
            totalDurations[2] += duration;
            if (imprimir) {
                System.out.print("Shell Sort (gaps de Sedgewick): ");
                Sort.printArray(clonedArr);
            }

            clonedArr = arr.clone();
            startTime = System.nanoTime();
            Sort.shellSortTokuda(clonedArr);
            duration = System.nanoTime() - startTime;
            durations[3][r] = duration;
            totalDurations[3] += duration;
            if (imprimir) {
                System.out.print("Shell Sort (gaps de Tokuda): ");
                Sort.printArray(clonedArr);
            }

            clonedArr = arr.clone();
            startTime = System.nanoTime();
            Sort.shellSortCiura(clonedArr);
            duration = System.nanoTime() - startTime;
            durations[4][r] = duration;
            totalDurations[4] += duration;
            if (imprimir) {
                System.out.print("Shell Sort (gaps de Ciura): ");
                Sort.printArray(clonedArr);
            }

            clonedArr = arr.clone();
            startTime = System.nanoTime();
            Sort.shellSortKnuth(clonedArr);
            duration = System.nanoTime() - startTime;
            durations[5][r] = duration;
            totalDurations[5] += duration;
            if (imprimir) {
                System.out.print("Shell Sort (gaps de Knuth): ");
                Sort.printArray(clonedArr);
            }
        }

        for (int i = 0; i < algorithmNames.length; i++) {
            long avgDuration = totalDurations[i] / repetitions;
            outfile.println(algorithmNames[i] + ": Média de " + avgDuration + " nanosegundos");
        }

        outfile.close();
        scanner.close();
    }
}
