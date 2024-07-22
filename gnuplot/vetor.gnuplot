set terminal pngcairo size 1024,768 enhanced font 'Verdana,10'
set output 'comparacaovetores.png'

set title 'Comparação de Métodos de Gaps Frente a Tipos de Vetores'
set xlabel 'Tipo de Vetor'
set ylabel 'Tempo de Execução (nanosegundos)'

set key outside
set grid

set style data histograms
set style fill solid 1.00 border -1
set boxwidth 0.9

set xtics nomirror rotate by -45
set xtics ("Vetor Aleatório" 0, "Vetor Semi-Aleatório" 1, "Vetor Ordenado" 2, "Vetor Ordenado Inverso" 3)

plot 'dadosvetor.txt' using 2:xtic(1) title 'Knuth', \
     '' using 3 title 'Hibbard', \
     '' using 4 title 'Padrão', \
     '' using 5 title 'Tokuda', \
     '' using 6 title 'Sedgewick', \
     '' using 7 title 'Ciura'
