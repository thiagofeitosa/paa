# ----------------------------------------------------------
# Arquivo de comandos GnuPlot para a plotagem da curva de 
# Complexidade de Tempo do Algoritmo Bubblesort (Ordenacao
# Por Bolha). 
#
# Este programa GnuPlot seta uma janela grafica e le varios
# arquivos de dados.
# ----------------------------------------------------------
set title "Plot de Complexidade de Tempo para Shell Sort"
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
	"relatorios/shell-sort-rond.dat" title "Shell Sort" w linespoints,\
        "relatorios/bubble-sorte-rond.dat" title "Bubble Sort" w linespoints, \
        "relatorios/Select-sort-rond.dat" title "Select Sort" w linespoints,\
	"relatorios/Insert-sort-rond.dat" title "Insert Sort" w linespoints,\
	"relatorios/merge-sort-rand.dat" title "Merge Sort" w linespoints,\
	"relatorios/quick-sort-rand.dat" title "Quick Sort" w linespoints
	
	
#
# Para que voce possa chamar o gnuplot diretamente de dentro de seu 
# programa em C usando o comando system(). Se voce nao colocar uma
# pausa no final de seu plot, a janela fecha imediatamente apos 
# ter sido desenhada.
pause -1 "Tecle enter para continuar com outro Algoritmo"
