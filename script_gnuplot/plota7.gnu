# ----------------------------------------------------------
# Arquivo de comandos GnuPlot para a plotagem da curva de 
# Complexidade de Tempo do Algoritmo Bubblesort (Ordenacao
# Por Bolha). 
#
# Este programa GnuPlot seta uma janela grafica e le varios
# arquivos de dados.
# ----------------------------------------------------------
set title "Plot de comparação de tempo de todos algorítimos"
#
#Seta tamanho da janela automaticamente de acordo com os dados
set autoscale

set style data linespoints


set xlabel "Tamanho do Conjunto de Dados"
set ylabel "Tempo"
#
#Seta posicao em coordenadas dos dados, onde vao aparecer os titulos
#Ist voce DEVE adaptar aos seus dados
set key default
#
#Seta grade
set grid

plot \
	"relatorios/shell-sort-rand.dat" title "Shell Sort" w linespoints,\
    "relatorios/bubble-sorte-rand.dat" title "Bubble Sort" w linespoints, \
    "relatorios/Select-sort-rand.dat" title "Select Sort" w linespoints,\
	"relatorios/Insert-sort-rand.dat" title "Insert Sort" w linespoints,\
	"relatorios/merge-sort-rand.dat" title "Merge Sort" w linespoints,\
	"relatorios/quick-sort-rand.dat" title "Quick Sort" w linespoints

pause -1 
