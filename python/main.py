import time
import numpy as np
from algoritmos_sort import AlgoritmosSort

def main():
    resp = input("Deseja LIMPAR o Arquivo [S/N]: ").strip().upper()
    if resp == 'S':
        AlgoritmosSort.limpar_arquivo()

    repetitions = 1  # Número de repetições para cada algoritmo

    imprimir_resp = input("Deseja imprimir o vetor ordenado no terminal? [S/N]: ").strip().upper()
    imprimir = (imprimir_resp == 'S')
    
    num_elementos = int(input("Digite o número de elementos que deseja ler: "))
    max_casas = int(input("Digite o número máximo de casas (1 a 7) para os números: "))

    if max_casas < 1: max_casas = 1
    if max_casas > 7: max_casas = 7

    with open("output.txt", "a") as outfile:
        outfile.write(f"[ Elementos = {num_elementos} ]\n")

    # Ler o vetor do arquivo
    arr = AlgoritmosSort.ler_vetor("vetor_gerado.txt", num_elementos, max_casas)
    
    durations = np.zeros((6, repetitions), dtype=np.int64)
    total_durations = np.zeros(6, dtype=np.int64)

    # Nomes dos algoritmos
    algorithm_names = ["Shell Sort (gaps padrão)", "Shell Sort (gaps de Hibbard)", 
                       "Shell Sort (gaps de Sedgewick)", "Shell Sort (gaps de Tokuda)", 
                       "Shell Sort (gaps de Ciura)", "Shell Sort (gaps de Knuth)"]

    algorithms = [AlgoritmosSort.shell_sort, AlgoritmosSort.shell_sort_hibbard, 
                  AlgoritmosSort.shell_sort_sedgewick, AlgoritmosSort.shell_sort_tokuda, 
                  AlgoritmosSort.shell_sort_ciura, AlgoritmosSort.shell_sort_knuth]

    for alg in range(6):
        for i in range(repetitions):
            temp = arr.copy()
            start = time.time_ns()
            algorithms[alg](temp)
            end = time.time_ns()
            duration = end - start
            durations[alg, i] = duration
            total_durations[alg] += duration

        average_duration = total_durations[alg] // repetitions
        with open("output.txt", "a") as outfile:
            outfile.write(f"[ Tempo médio de execução do {algorithm_names[alg]} ] : [ {average_duration} nanosegundos ]\n")

        standard_deviation = np.std(durations[alg])
        print(f"Desvio padrão do {algorithm_names[alg]} : {standard_deviation:.2f} nanosegundos")

    if imprimir:
        opcao = int(input("\nEscolha um algoritmo para testar:\n"
                          "1. Shell Sort (gaps padrão)\n"
                          "2. Shell Sort (gaps de Hibbard)\n"
                          "3. Shell Sort (gaps de Sedgewick)\n"
                          "4. Shell Sort (gaps de Tokuda)\n"
                          "5. Shell Sort (gaps de Ciura)\n"
                          "6. Shell Sort (gaps de Knuth)\n"
                          "Opção: "))
        if 1 <= opcao <= 6:
            temp = arr.copy()
            algorithms[opcao - 1](temp)
            print(f"Array ordenado pelo {algorithm_names[opcao - 1]}:")
            AlgoritmosSort.imprimir_vetor(temp)
        else:
            print("Opção inválida!")

if __name__ == "__main__":
    main()
