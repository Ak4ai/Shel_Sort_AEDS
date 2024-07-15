set terminal pngcairo size 1024,768 enhanced font 'Verdana,10'
set output 'grafico.png'

set title 'Gráfico Detalhado das Linhas e Elementos'
set xlabel 'Coluna 1'
set ylabel 'Valores'

set key outside
set grid

set logscale y

set logscale x

set xtics ("10" 10, "100" 100, "1000" 1000, "10000" 10000, "100000" 100000, "1000000" 1000000)

plot 'dados.txt' using 1:2 with linespoints title 'Coluna 2', \
     'dados.txt' using 1:3 with linespoints title 'Coluna 3', \
     'dados.txt' using 1:4 with linespoints title 'Coluna 4', \
     'dados.txt' using 1:5 with linespoints title 'Coluna 5', \
     'dados.txt' using 1:6 with linespoints title 'Coluna 6', \
     'dados.txt' using 1:7 with linespoints title 'Coluna 7'
