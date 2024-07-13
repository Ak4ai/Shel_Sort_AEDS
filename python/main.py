import numpy as np
import time
import math

class AlgoritmosSort:
    
    @staticmethod
    def shell_sort(arr, gaps):
        n = len(arr)
        for gap in gaps:
            for i in range(gap, n):
                temp = arr[i]
                j = i
                while j >= gap and arr[j - gap] > temp:
                    arr[j] = arr[j - gap]
                    j -= gap
                arr[j] = temp
    
    @staticmethod
    def generate_gaps(method, size):
        if method == "hibbard":
            gaps = [(1 << k) - 1 for k in range(1, size.bit_length())]
        elif method == "sedgewick":
            gaps = []
            k = 0
            while True:
                if k % 2 == 0:
                    gap = 9 * (1 << (2 * k)) - 9 * (1 << k) + 1
                else:
                    gap = 8 * (1 << k) - 6 * (1 << ((k + 1) // 2)) + 1
                if gap >= size:
                    break
                gaps.append(gap)
                k += 1
        elif method == "tokuda":
            gaps = []
            k = 1
            while True:
                gap = int(9 * (pow(2, k) - 1) / 5)
                if gap >= size:
                    break
                gaps.append(gap)
                k += 1
        elif method == "incerpi":
            gaps = [int(pow(2, k // 2)) for k in range(1, 2 * size.bit_length())]
        elif method == "knuth":
            gaps = []
            k = 1
            while True:
                gap = (pow(3, k) - 1) // 2
                if gap >= size:
                    break
                gaps.append(gap)
                k += 1
        else:  # Default shell sort
            gaps = [size // 2]
            while gaps[-1] > 0:
                gaps.append(gaps[-1] // 2)
            gaps = gaps[:-1]  # Remove the último 0
        return list(reversed(gaps))

def measure_sort_times(arr, repetitions=1000):
    algorithms = ["default", "hibbard", "sedgewick", "tokuda", "incerpi", "knuth"]
    durations = {alg: [] for alg in algorithms}
    total_durations = {alg: 0 for alg in algorithms}

    for alg in algorithms:
        gaps = AlgoritmosSort.generate_gaps(alg, len(arr))
        for _ in range(repetitions):
            temp = arr.copy()
            start_time = time.time_ns()
            AlgoritmosSort.shell_sort(temp, gaps)
            end_time = time.time_ns()
            duration = end_time - start_time
            durations[alg].append(duration)
            total_durations[alg] += duration

        avg_duration = total_durations[alg] / repetitions
        with open("output.txt", "a") as outfile:
            outfile.write(f"[ Tempo médio de execução do Shell Sort ({alg}) ] : [ {avg_duration} nanosegundos ]\n")
        
        sum_square_diff = sum((x - avg_duration) ** 2 for x in durations[alg])
        std_dev = math.sqrt(sum_square_diff / repetitions)
        print(f"Desvio padrão do Shell Sort ({alg}) : {std_dev} nanosegundos")

def read_vector(filename, num_elements, max_digits):
    vec = []
    with open(filename, "r") as file:
        lines = file.readlines()
        for line in lines:
            if len(vec) >= num_elements:
                break
            numbers = line.strip().split()
            for num_str in numbers:
                if len(vec) >= num_elements:
                    break
                num = int(num_str[:max_digits])
                vec.append(num)
    return vec

def print_array(arr):
    print(" ".join(map(str, arr)))

if __name__ == "__main__":
    resp = input("Deseja LIMPAR o Arquivo [S/N]: ").strip().upper()
    if resp == 'S':
        open("output.txt", "w").close()

    repetitions = 1  # Número de repetições para cada algoritmo
    
    imprimir_resp = input("Deseja imprimir o vetor ordenado no terminal? [S/N]: ").strip().upper()
    imprimir = (imprimir_resp == 'S')

    num_elementos = int(input("Digite o número de elementos que deseja ler: "))
    max_casas = int(input("Digite o número máximo de casas (1 a 7) para os números: "))

    if max_casas < 1:
        max_casas = 1
    if max_casas > 7:
        max_casas = 7

    arr = read_vector("vetor_gerado.txt", num_elementos, max_casas)
    measure_sort_times(arr, repetitions)

    if imprimir:
        opcao = int(input("\nEscolha um algoritmo para testar:\n"
                          "1. Shell Sort (gaps padrão)\n"
                          "2. Shell Sort (gaps de Hibbard)\n"
                          "3. Shell Sort (gaps de Sedgewick)\n"
                          "4. Shell Sort (gaps de Tokuda)\n"
                          "5. Shell Sort (gaps de Incerpi)\n"
                          "6. Shell Sort (gaps de Knuth)\n"
                          "Opção: "))
        algorithm_methods = ["default", "hibbard", "sedgewick", "tokuda", "incerpi", "knuth"]
        if 1 <= opcao <= 6:
            selected_algorithm = algorithm_methods[opcao - 1]
            gaps = AlgoritmosSort.generate_gaps(selected_algorithm, len(arr))
            temp = arr.copy()
            AlgoritmosSort.shell_sort(temp, gaps)
            print(f"Array ordenado pelo Shell Sort ({selected_algorithm}):")
            print_array(temp)
        else:
            print("Opção inválida!")
