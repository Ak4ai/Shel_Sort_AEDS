import java.io.*;
import java.util.*;
import java.util.stream.Collectors;
import java.nio.file.*;
import java.nio.charset.StandardCharsets;

public class Sort {

    public static void limparArq() {
        try (PrintWriter writer = new PrintWriter("output.txt")) {
            writer.print("");
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static void swap(int[] arr, int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    public static void shellSort(int[] arr) {
        int n = arr.length;
        for (int gap = n / 2; gap > 0; gap /= 2) {
            for (int i = gap; i < n; i++) {
                int temp = arr[i];
                int j;
                for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                    arr[j] = arr[j - gap];
                }
                arr[j] = temp;
            }
        }
    }

    public static void shellSortHibbard(int[] arr) {
        int n = arr.length;
        List<Integer> gaps = new ArrayList<>();
        for (int k = 1; (1 << k) - 1 < n; k++) {
            gaps.add((1 << k) - 1);
        }
        Collections.reverse(gaps);
        for (int gap : gaps) {
            for (int i = gap; i < n; i++) {
                int temp = arr[i];
                int j;
                for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                    arr[j] = arr[j - gap];
                }
                arr[j] = temp;
            }
        }
    }

    public static void shellSortSedgewick(int[] arr) {
        int n = arr.length;
        List<Integer> gaps = new ArrayList<>();
        for (int k = 0; ; k++) {
            int gap;
            if (k % 2 == 0) {
                gap = 9 * (1 << (2 * k)) - 9 * (1 << k) + 1;
            } else {
                gap = 8 * (1 << k) - 6 * (1 << ((k + 1) / 2)) + 1;
            }
            if (gap > n) break;
            gaps.add(gap);
        }
        Collections.reverse(gaps);
        for (int gap : gaps) {
            for (int i = gap; i < n; i++) {
                int temp = arr[i];
                int j;
                for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                    arr[j] = arr[j - gap];
                }
                arr[j] = temp;
            }
        }
    }

    public static void shellSortTokuda(int[] arr) {
        int n = arr.length;
        List<Integer> gaps = new ArrayList<>();
        for (int k = 1; ; k++) {
            int gap = (int) (9 * (Math.pow(2, k) - 1) / 5);
            if (gap >= n) break;
            gaps.add(gap);
        }
        Collections.reverse(gaps);
        for (int gap : gaps) {
            for (int i = gap; i < n; i++) {
                int temp = arr[i];
                int j;
                for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                    arr[j] = arr[j - gap];
                }
                arr[j] = temp;
            }
        }
    }

    public static void shellSortCiura(int[] arr) {
        int n = arr.length;

        // Generate the Ciura sequence
        int[] ciuraSequence = {1, 4, 10, 23, 57, 132, 301, 701, 1750};

        // Iterate over the Ciura sequence from the largest to the smallest
        for (int i = ciuraSequence.length - 1; i >= 0; i--) {
            int gap = ciuraSequence[i];
            if (gap >= n) {
                continue;
            }

            // Perform the gapped insertion sort for this gap
            for (int j = gap; j < n; j++) {
                int temp = arr[j];
                int k;
                for (k = j; k >= gap && arr[k - gap] > temp; k -= gap) {
                    arr[k] = arr[k - gap];
                }
                arr[k] = temp;
            }
        }
    }

    public static List<Integer> generateKnuthSequence(int size) {
        List<Integer> sequence = new ArrayList<>();
        int k = 1;
        int gap = (int) ((Math.pow(3, k) - 1) / 2);
        while (gap < size) {
            sequence.add(gap);
            k++;
            gap = (int) ((Math.pow(3, k) - 1) / 2);
        }
        return sequence;
    }

    public static void shellSortKnuth(int[] arr) {
        int n = arr.length;
        List<Integer> gaps = generateKnuthSequence(n);
        Collections.reverse(gaps);
        for (int gap : gaps) {
            for (int i = gap; i < n; i++) {
                int temp = arr[i];
                int j;
                for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                    arr[j] = arr[j - gap];
                }
                arr[j] = temp;
            }
        }
    }

    public static List<Integer> gerarVetorWIP(int tam, int max) {
        Random rand = new Random();
        return rand.ints(tam, 0, max + 1).boxed().collect(Collectors.toList());
    }

    public static void salvarVetor(List<Integer> arr, String filename) {
        try (PrintWriter out = new PrintWriter(filename)) {
            for (int num : arr) {
                out.print(num + " ");
            }
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }

    public static List<Integer> lerVetor(String filename, int numElementos, int maxCasas) {
        List<Integer> vec = new ArrayList<>();
        try (BufferedReader br = Files.newBufferedReader(Paths.get(filename), StandardCharsets.UTF_8)) {
            String line;
            int count = 0;
            while ((line = br.readLine()) != null && count < numElementos) {
                String[] numbers = line.split(" ");
                for (String numStr : numbers) {
                    if (count >= numElementos) break;
                    int num = Integer.parseInt(numStr.substring(0, Math.min(numStr.length(), maxCasas)));
                    vec.add(num);
                    count++;
                }
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
        return vec;
    }

    public static void printArray(int[] arr) {
        for (int num : arr) {
            System.out.print(num + " ");
        }
        System.out.println();
    }
}
