# ----------------------------------------------------------
# Arquivo de comandos GnuPlot para a plotagem da curva de 
# Complexidade de Tempo do Algoritmo Bubblesort (Ordenacao
# Por Bolha). 
#
# Este programa GnuPlot seta uma janela grafica e le varios
# arquivos de dados.
# ----------------------------------------------------------
set title "Plot de Complexidade de Tempo para Quick Sort"
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
	"relatorios/quick-sort-rand.dat" title "Randomicos" w linespoints,\
        "relatorios/quick-sort-ord.dat" title "Ordenados" w linespoints, \
        "relatorios/quick-sort-inv.dat" title "Invertidos" w linespoints

pause -1