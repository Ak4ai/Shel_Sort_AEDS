import random
import math

class AlgoritmosSort:

    @staticmethod
    def limpar_arquivo():
        with open("output.txt", "w") as outfile:
            pass

    @staticmethod
    def shell_sort(arr):
        n = len(arr)
        gap = n // 2
        while gap > 0:
            for i in range(gap, n):
                temp = arr[i]
                j = i
                while j >= gap and arr[j - gap] > temp:
                    arr[j] = arr[j - gap]
                    j -= gap
                arr[j] = temp
            gap //= 2

    @staticmethod
    def shell_sort_hibbard(arr):
        n = len(arr)
        gaps = [(2 ** k) - 1 for k in range(1, int(math.log2(n)) + 1)]
        gaps.reverse()
        for gap in gaps:
            for i in range(gap, n):
                temp = arr[i]
                j = i
                while j >= gap and arr[j - gap] > temp:
                    arr[j] = arr[j - gap]
                    j -= gap
                arr[j] = temp

    @staticmethod
    def shell_sort_sedgewick(arr):
        n = len(arr)
        gaps = []
        k = 0
        while True:
            gap = 9 * (2 ** k) - 9 * (2 ** (k // 2)) + 1 if k % 2 == 0 else 8 * (2 ** k) - 6 * (2 ** ((k + 1) // 2)) + 1
            if gap >= n:
                break
            gaps.append(gap)
            k += 1
        gaps.reverse()
        for gap in gaps:
            for i in range(gap, n):
                temp = arr[i]
                j = i
                while j >= gap and arr[j - gap] > temp:
                    arr[j] = arr[j - gap]
                    j -= gap
                arr[j] = temp

    @staticmethod
    def shell_sort_tokuda(arr):
        n = len(arr)
        gaps = []
        k = 1
        while True:
            gap = int(9 * (2 ** k - 1) / 5)
            if gap >= n:
                break
            gaps.append(gap)
            k += 1
        gaps.reverse()
        for gap in gaps:
            for i in range(gap, n):
                temp = arr[i]
                j = i
                while j >= gap and arr[j - gap] > temp:
                    arr[j] = arr[j - gap]
                    j -= gap
                arr[j] = temp

    @staticmethod
    def shell_sort_incerpi(arr):
        n = len(arr)
        gaps = []
        k = 1
        while True:
            gap = int(2 ** (k // 2))
            if gap >= n:
                break
            gaps.append(gap)
            k += 1
        gaps.reverse()
        for gap in gaps:
            for i in range(gap, n):
                temp = arr[i]
                j = i
                while j >= gap and arr[j - gap] > temp:
                    arr[j] = arr[j - gap]
                    j -= gap
                arr[j] = temp

    @staticmethod
    def shell_sort_knuth(arr):
        n = len(arr)
        gaps = []
        k = 1
        while True:
            gap = (3 ** k - 1) // 2
            if gap >= n:
                break
            gaps.append(gap)
            k += 1
        gaps.reverse()
        for gap in gaps:
            for i in range(gap, n):
                temp = arr[i]
                j = i
                while j >= gap and arr[j - gap] > temp:
                    arr[j] = arr[j - gap]
                    j -= gap
                arr[j] = temp

    @staticmethod
    def gerar_vetor(tam, max_val):
        return [random.randint(0, max_val) for _ in range(tam)]

    @staticmethod
    def salvar_vetor(arr, filename):
        with open(filename, "w") as outfile:
            outfile.write(" ".join(map(str, arr)) + "\n")

    @staticmethod
    def ler_vetor(filename, num_elementos, max_casas):
        vec = []
        with open(filename, "r") as infile:
            for line in infile:
                for num_str in line.split():
                    num = int(num_str[:max_casas])
                    vec.append(num)
                    if len(vec) == num_elementos:
                        return vec
        return vec

    @staticmethod
    def imprimir_vetor(arr):
        print(" ".join(map(str, arr)))
