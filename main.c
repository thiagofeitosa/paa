#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ordena.h"


int main()
{

    int *VetorArquivo;
    long int tamanho;
    long int vetor2[100000];//vetor auxilixar para verge sort
    int op;
    printf("\n");
    printf("Thiago Gonçalves Feitosa.\nTrabalho de Projeto e análise de algorítimos\n");
    do
    {
        //system ("clear");
        
        printf("\n\t|----------|      MENU      | ------------|");
        printf("\n\t|-----------------------------------------|");
        printf("\n\t| 1 -----|CRIAR ARQUIVOS .TXT|------------|");
        printf("\n\t| 2 -------| BUBBLE  SORT |---------------|");
        printf("\n\t| 3 -------| SELECT  SORT |---------------|");
        printf("\n\t| 4 -------| INSERT  SORT |---------------|");
        printf("\n\t| 5 -------| QUICK   SORT |---------------|");
        printf("\n\t| 6 -------| MERGE   SORT |---------------|");
        printf("\n\t| 7 -------| SHELL   SORT |---------------|");
        printf("\n\t| 0 -------|      SAIR    |---------------|");
        printf("\n\t|-----------------------------------------|\n");
        scanf("\t %d",&op);

        switch(op)
        {
        case 1 :
            createAllFiles();
            break;
        case 2 :

            gnuplot = fopen("relatorios/bubble-sorte-rond.dat", "w");

            printf("Ordenando vetor com 100 elementos\n");
            fprintf(gnuplot, "#RANDOMICOS\n#Tamanho\t Tempo\t\t Comparacao\t trocas\n");
            VetorArquivo = LendoArquivo("vetores/100-random.txt",&tamanho);
            BubbleSort(VetorArquivo, tamanho);
            GravarArquivo(VetorArquivo, tamanho);
            printResultados();
            ///-----------------------------------------------------------------------
            printf("Ordenando vetor com 1.000 elementos\n");
            VetorArquivo = LendoArquivo("vetores/1000-random.txt",&tamanho);
            BubbleSort(VetorArquivo, tamanho);
            GravarArquivo(VetorArquivo, tamanho);
            printResultados();
            ///------------------------------------------------------------------------
            printf("Ordenando vetor com 10.000 elementos\n");
            VetorArquivo = LendoArquivo("vetores/10000-random.txt",&tamanho);
            BubbleSort(VetorArquivo, tamanho);
            GravarArquivo(VetorArquivo, tamanho);
            printResultados();
            ///------------------------------------------------------------------------
            printf("Ordenando vetor de 50.000 elementos\n");
            VetorArquivo = LendoArquivo("vetores/50000-random.txt",&tamanho);
            BubbleSort(VetorArquivo, tamanho);
            GravarArquivo(VetorArquivo, tamanho);
            printResultados();
            ///------------------------------------------------------------------------
            printf("Ordenando vetor de 100.000 elementos \n");
            VetorArquivo = LendoArquivo("vetores/100000-random.txt",&tamanho);
            BubbleSort(VetorArquivo, tamanho);
            GravarArquivo(VetorArquivo, tamanho);
            printResultados();
            fclose(gnuplot);
            ///-----------------------------------------------------------------------
            printf("|================================================================|\n");

            gnuplot = fopen("relatorios/bubbleSorte-ord.dat", "w");
            printf("Vetor ja ordenado com 100\n");
            fprintf(gnuplot, "#ORDENANDOS\n#Tamanho\t Tempo\t\t Comparacao\t trocas\n");
            VetorArquivo = LendoArquivo("vetores/100-crescente.txt",&tamanho);
            BubbleSort(VetorArquivo, tamanho);
            GravarArquivo(VetorArquivo, tamanho);
            printResultados();
            ///-----------------------------------------------------------------------
            printf("Vetor ja ordenado com 1.000\n");
            VetorArquivo = LendoArquivo("vetores/1000-crescente.txt",&tamanho);
            BubbleSort(VetorArquivo, tamanho);
            GravarArquivo(VetorArquivo, tamanho);
            printResultados();
            ///------------------------------------------------------------------------
            printf("Vetor ja ordenado com 10.000\n");
            VetorArquivo = LendoArquivo("vetores/10000-crescente.txt",&tamanho);
            BubbleSort(VetorArquivo, tamanho);
            GravarArquivo(VetorArquivo, tamanho);
            printResultados();
            ///------------------------------------------------------------------------
            printf("Vetor ja ordenado com 50.000\n");
            VetorArquivo = LendoArquivo("vetores/50000-crescente.txt",&tamanho);
            BubbleSort(VetorArquivo, tamanho);
            GravarArquivo(VetorArquivo, tamanho);
            printResultados();
            ///------------------------------------------------------------------------
            printf("Vetor ja ordenado com 100.000\n");
            VetorArquivo = LendoArquivo("vetores/100000-crescente.txt",&tamanho);
            BubbleSort(VetorArquivo, tamanho);
            GravarArquivo(VetorArquivo, tamanho);
            printResultados();
            fclose(gnuplot);
            ///-----------------------------------------------------------------------
             printf("|================================================================|\n");

             gnuplot = fopen("relatorios/bubbleSorte-inv.dat", "w");
            printf("Vetor ordenando inverso com 100\n");
            fprintf(gnuplot, "#ORDENANDO INVERSO\n#Tamanho\t Tempo\t\t Comparacao\t trocas\n");
            VetorArquivo = LendoArquivo("vetores/100-decrescente.txt",&tamanho);
            BubbleSort(VetorArquivo, tamanho);
            GravarArquivo(VetorArquivo, tamanho);
            printResultados();
            ///-----------------------------------------------------------------------
            printf("Vetor ordenando inverso com 1.000\n");
            VetorArquivo = LendoArquivo("vetores/1000-decrescente.txt",&tamanho);
            BubbleSort(VetorArquivo, tamanho);
            GravarArquivo(VetorArquivo, tamanho);
            printResultados();
            ///------------------------------------------------------------------------
            printf("Vetor ordenando inverso com 10.000\n");
            VetorArquivo = LendoArquivo("vetores/10000-decrescente.txt",&tamanho);
            BubbleSort(VetorArquivo, tamanho);
            GravarArquivo(VetorArquivo, tamanho);
            printResultados();
            ///------------------------------------------------------------------------
            printf("Vetor ordenando inverso com 50.000\n");
            VetorArquivo = LendoArquivo("vetores/50000-decrescente.txt",&tamanho);
            BubbleSort(VetorArquivo, tamanho);
            GravarArquivo(VetorArquivo, tamanho);
            printResultados();
            ///------------------------------------------------------------------------
            printf("Vetor ordenando inverso com 100.000\n");
            VetorArquivo = LendoArquivo("vetores/100000-decrescente.txt",&tamanho);
            BubbleSort(VetorArquivo, tamanho);
            GravarArquivo(VetorArquivo, tamanho);
            printResultados();
            fclose(gnuplot);
            ///-----------------------------------------------------------------------

            system("gnuplot -bg gray90 script_gnuplot/plota.gnu");

            break;

        case 3:

            gnuplot = fopen("relatorios/Select-sort-rond.dat", "w");

            printf("Ordenando vetor com 100 elementos\n");
            fprintf(gnuplot, "#RANDOMICOS\n#Tamanho\t Tempo\t\t Comparacao\t trocas\n");
            VetorArquivo = LendoArquivo("vetores/100-random.txt",&tamanho);
            selectSort(VetorArquivo, tamanho);
            GravarArquivo(VetorArquivo, tamanho);
            printResultados();
            ///-----------------------------------------------------------------------
            printf("Ordenando vetor com 1.000 elementos\n");
            VetorArquivo = LendoArquivo("vetores/1000-random.txt",&tamanho);
            selectSort(VetorArquivo, tamanho);
            GravarArquivo(VetorArquivo, tamanho);
            printResultados();
            ///------------------------------------------------------------------------
            printf("Ordenando vetor com 10.000 elementos\n");
            VetorArquivo = LendoArquivo("vetores/10000-random.txt",&tamanho);
            selectSort(VetorArquivo, tamanho);
            GravarArquivo(VetorArquivo, tamanho);
            printResultados();
            ///------------------------------------------------------------------------
            printf("Ordenando vetor de 50.000 elementos\n");
            VetorArquivo = LendoArquivo("vetores/50000-random.txt",&tamanho);
            selectSort(VetorArquivo, tamanho);
            GravarArquivo(VetorArquivo, tamanho);
            printResultados();
            ///------------------------------------------------------------------------
            printf("Ordenando vetor de 100.000 elementos \n");
            VetorArquivo = LendoArquivo("vetores/100000-random.txt",&tamanho);
            selectSort(VetorArquivo, tamanho);
            GravarArquivo(VetorArquivo, tamanho);
            printResultados();
            fclose(gnuplot);
            ///-----------------------------------------------------------------------
            printf("|================================================================|\n");

            gnuplot = fopen("relatorios/Select-sort-ord.dat", "w");
            printf("Vetor ja ordenado com 100\n");
            fprintf(gnuplot, "#ORDENANDOS\n#Tamanho\t Tempo\t\t Comparacao\t trocas\n");
            VetorArquivo = LendoArquivo("vetores/100-crescente.txt",&tamanho);
            selectSort(VetorArquivo, tamanho);
            GravarArquivo(VetorArquivo, tamanho);
            printResultados();
            ///-----------------------------------------------------------------------
            printf("Vetor ja ordenado com 1.000\n");
            VetorArquivo = LendoArquivo("vetores/1000-crescente.txt",&tamanho);
            selectSort(VetorArquivo, tamanho);
            GravarArquivo(VetorArquivo, tamanho);
            printResultados();
            ///------------------------------------------------------------------------
            printf("Vetor ja ordenado com 10.000\n");
            VetorArquivo = LendoArquivo("vetores/10000-crescente.txt",&tamanho);
            selectSort(VetorArquivo, tamanho);
            GravarArquivo(VetorArquivo, tamanho);
            printResultados();
            ///------------------------------------------------------------------------
            printf("Vetor ja ordenado com 50.000\n");
            VetorArquivo = LendoArquivo("vetores/50000-crescente.txt",&tamanho);
            selectSort(VetorArquivo, tamanho);
            GravarArquivo(VetorArquivo, tamanho);
            printResultados();
            ///------------------------------------------------------------------------
            printf("Vetor ja ordenado com 100.000\n");
            VetorArquivo = LendoArquivo("vetores/100000-crescente.txt",&tamanho);
            selectSort(VetorArquivo, tamanho);
            GravarArquivo(VetorArquivo, tamanho);
            printResultados();
            fclose(gnuplot);
            ///-----------------------------------------------------------------------
             printf("|================================================================|\n");

             gnuplot = fopen("relatorios/Select-sort-inv.dat", "w");
            printf("Vetor ordenando inverso com 100\n");
            fprintf(gnuplot, "#ORDENANDO INVERSO\n#Tamanho\t Tempo\t\t Comparacao\t trocas\n");
            VetorArquivo = LendoArquivo("vetores/100-decrescente.txt",&tamanho);
            selectSort(VetorArquivo, tamanho);
            GravarArquivo(VetorArquivo, tamanho);
            printResultados();
            ///-----------------------------------------------------------------------
            printf("Vetor ordenando inverso com 1.000\n");
            VetorArquivo = LendoArquivo("vetores/1000-decrescente.txt",&tamanho);
            selectSort(VetorArquivo, tamanho);
            GravarArquivo(VetorArquivo, tamanho);
            printResultados();
            ///------------------------------------------------------------------------
            printf("Vetor ordenando inverso com 10.000\n");
            VetorArquivo = LendoArquivo("vetores/10000-decrescente.txt",&tamanho);
            selectSort(VetorArquivo, tamanho);
            GravarArquivo(VetorArquivo, tamanho);
            printResultados();
            ///------------------------------------------------------------------------
            printf("Vetor ordenando inverso com 50.000\n");
            VetorArquivo = LendoArquivo("vetores/50000-decrescente.txt",&tamanho);
            selectSort(VetorArquivo, tamanho);
            GravarArquivo(VetorArquivo, tamanho);
            printResultados();
            ///------------------------------------------------------------------------
            printf("Vetor ordenando inverso com 100.000\n");
            VetorArquivo = LendoArquivo("vetores/100000-decrescente.txt",&tamanho);
            selectSort(VetorArquivo, tamanho);
            GravarArquivo(VetorArquivo, tamanho);
            printResultados();
            fclose(gnuplot);
            ///-----------------------------------------------------------------------

            system("gnuplot -bg gray90 script_gnuplot/plota2.gnu");
            break;
        case 4:

            gnuplot = fopen("relatorios/Insert-sort-rond.dat", "w");

            printf("Ordenando vetor com 100 elementos\n");
            fprintf(gnuplot, "#RANDOMICOS\n#Tamanho\t Tempo\t\t Comparacao\t trocas\n");
            VetorArquivo = LendoArquivo("vetores/100-random.txt",&tamanho);
            insertionSort(VetorArquivo, tamanho);
            GravarArquivo(VetorArquivo, tamanho);
            printResultados();
            ///-----------------------------------------------------------------------
            printf("Ordenando vetor com 1.000 elementos\n");
            VetorArquivo = LendoArquivo("vetores/1000-random.txt",&tamanho);
            insertionSort(VetorArquivo, tamanho);
            GravarArquivo(VetorArquivo, tamanho);
            printResultados();
            ///------------------------------------------------------------------------
            printf("Ordenando vetor com 10.000 elementos\n");
            VetorArquivo = LendoArquivo("vetores/10000-random.txt",&tamanho);
            insertionSort(VetorArquivo, tamanho);
            GravarArquivo(VetorArquivo, tamanho);
            printResultados();
            ///------------------------------------------------------------------------
            printf("Ordenando vetor de 50.000 elementos\n");
            VetorArquivo = LendoArquivo("vetores/50000-random.txt",&tamanho);
            insertionSort(VetorArquivo, tamanho);
            GravarArquivo(VetorArquivo, tamanho);
            printResultados();
            ///------------------------------------------------------------------------
            printf("Ordenando vetor de 100.000 elementos \n");
            VetorArquivo = LendoArquivo("vetores/100000-random.txt",&tamanho);
            insertionSort(VetorArquivo, tamanho);
            GravarArquivo(VetorArquivo, tamanho);
            printResultados();
            fclose(gnuplot);
            ///-----------------------------------------------------------------------
            printf("|================================================================|\n");

            gnuplot = fopen("relatorios/Insert-sort-ord.dat", "w");

            printf("Vetor ja ordenado com 100\n");
            fprintf(gnuplot, "#ORDENANDOS\n#Tamanho\t Tempo\t\t Comparacao\t trocas\n");
            VetorArquivo = LendoArquivo("vetores/100-crescente.txt",&tamanho);
            insertionSort(VetorArquivo, tamanho);
            GravarArquivo(VetorArquivo, tamanho);
            printResultados();
            ///-----------------------------------------------------------------------
            printf("Vetor ja ordenado com 1.000\n");
            VetorArquivo = LendoArquivo("vetores/1000-crescente.txt",&tamanho);
            insertionSort(VetorArquivo, tamanho);
            GravarArquivo(VetorArquivo, tamanho);
            printResultados();
            ///------------------------------------------------------------------------
            printf("Vetor ja ordenado com 10.000\n");
            VetorArquivo = LendoArquivo("vetores/10000-crescente.txt",&tamanho);
            insertionSort(VetorArquivo, tamanho);
            GravarArquivo(VetorArquivo, tamanho);
            printResultados();
            ///------------------------------------------------------------------------
            printf("Vetor ja ordenado com 50.000\n");
            VetorArquivo = LendoArquivo("vetores/50000-crescente.txt",&tamanho);
            insertionSort(VetorArquivo, tamanho);
            GravarArquivo(VetorArquivo, tamanho);
            printResultados();
            ///------------------------------------------------------------------------
            printf("Vetor ja ordenado com 100.000\n");
            VetorArquivo = LendoArquivo("vetores/100000-crescente.txt",&tamanho);
            insertionSort(VetorArquivo, tamanho);
            GravarArquivo(VetorArquivo, tamanho);
            printResultados();
            fclose(gnuplot);
            ///-----------------------------------------------------------------------
             printf("|================================================================|\n");

            gnuplot = fopen("relatorios/Insert-sort-inv.dat", "w");

            printf("Vetor ordenando inverso com 100\n");
            fprintf(gnuplot, "#ORDENANDO INVERSO\n#Tamanho\t Tempo\t\t Comparacao\t trocas\n");
            VetorArquivo = LendoArquivo("vetores/100-decrescente.txt",&tamanho);
            insertionSort(VetorArquivo, tamanho);
            GravarArquivo(VetorArquivo, tamanho);
            printResultados();
            ///-----------------------------------------------------------------------
            printf("Vetor ordenando inverso com 1.000\n");
            VetorArquivo = LendoArquivo("vetores/1000-decrescente.txt",&tamanho);
            insertionSort(VetorArquivo, tamanho);
            GravarArquivo(VetorArquivo, tamanho);
            printResultados();
            ///------------------------------------------------------------------------
            printf("Vetor ordenando inverso com 10.000\n");
            VetorArquivo = LendoArquivo("vetores/10000-decrescente.txt",&tamanho);
            insertionSort(VetorArquivo, tamanho);
            GravarArquivo(VetorArquivo, tamanho);
            printResultados();
            ///------------------------------------------------------------------------
            printf("Vetor ordenando inverso com 50.000\n");
            VetorArquivo = LendoArquivo("vetores/50000-decrescente.txt",&tamanho);
            insertionSort(VetorArquivo, tamanho);
            GravarArquivo(VetorArquivo, tamanho);
            printResultados();
            ///------------------------------------------------------------------------
            printf("Vetor ordenando inverso com 100.000\n");
            VetorArquivo = LendoArquivo("vetores/100000-decrescente.txt",&tamanho);
            insertionSort(VetorArquivo, tamanho);
            GravarArquivo(VetorArquivo, tamanho);
            printResultados();
            fclose(gnuplot);
            ///-----------------------------------------------------------------------
            system("gnuplot -bg gray90 script_gnuplot/plota3.gnu");
            break;
        case 5:

             gnuplot = fopen("relatorios/quick-sort-rand.dat", "w");
             printf("Ordenando vetor com 100 elementos\n");
            fprintf(gnuplot, "#RANDOMICOS\n#Tamanho\t Tempo\t\t Comparacao\t trocas\n");
            VetorArquivo = LendoArquivo("vetores/100-random.txt",&tamanho);
            quicksort(VetorArquivo,0,tamanho-1);
           // MostarVetor(VetorArquivo,tamanho);
            printResultados();
            //GravarArquivo(VetorArquivo, tamanho);
            ///-----------------------------------------------------------------------
            printf("Ordenando vetor com 1.000 elementos\n");
            VetorArquivo = LendoArquivo("vetores/1000-random.txt",&tamanho);
            quicksort(VetorArquivo,0,tamanho-1);
            //GravarArquivo(VetorArquivo, tamanho);
             printResultados();
            ///------------------------------------------------------------------------
            printf("Ordenando vetor com 10.000 elementos\n");
            VetorArquivo = LendoArquivo("vetores/10000-random.txt",&tamanho);
            quicksort(VetorArquivo,0,tamanho-1);
            printResultados();
            GravarArquivo(VetorArquivo, tamanho);
            ///------------------------------------------------------------------------
            printf("Ordenando vetor de 50.000 elementos\n");
            VetorArquivo = LendoArquivo("vetores/50000-random.txt",&tamanho);
            quicksort(VetorArquivo,0,tamanho-1);
            printResultados();
            //GravarArquivo(VetorArquivo, tamanho);
            ///------------------------------------------------------------------------
            printf("Ordenando vetor de 100.000 elementos \n");
            VetorArquivo = LendoArquivo("vetores/100000-random.txt",&tamanho);
            quicksort(VetorArquivo,0,tamanho-1);
            printResultados();
            //GravarArquivo(VetorArquivo, tamanho);
            fclose(gnuplot);
            ///-----------------------------------------------------------------------
            printf("|================================================================|\n");

            gnuplot = fopen("relatorios/quick-sort-ord.dat", "w");
            printf("Vetor ja ordenado com 100\n");
            fprintf(gnuplot, "#ORDENANDOS\n#Tamanho\t Tempo\t\t Comparacao\t trocas\n");
            VetorArquivo = LendoArquivo("vetores/100-crescente.txt",&tamanho);
            quicksort(VetorArquivo,0,tamanho-1);
            printResultados();
            //GravarArquivo(VetorArquivo, tamanho);

            ///-----------------------------------------------------------------------
            printf("Vetor ja ordenado com 1.000\n");
            VetorArquivo = LendoArquivo("vetores/1000-crescente.txt",&tamanho);
            quicksort(VetorArquivo,0,tamanho-1);
            printResultados();
            //GravarArquivo(VetorArquivo, tamanho);
            ///------------------------------------------------------------------------
            printf("Vetor ja ordenado com 10.000\n");
            VetorArquivo = LendoArquivo("vetores/10000-crescente.txt",&tamanho);;
            quicksort(VetorArquivo,0,tamanho-1);
            printResultados();
            //GravarArquivo(VetorArquivo, tamanho);
            ///------------------------------------------------------------------------
            printf("Vetor ja ordenado com 50.000\n");
            VetorArquivo = LendoArquivo("vetores/50000-crescente.txt",&tamanho);
            quicksort(VetorArquivo,0,tamanho-1);
            printResultados();
            //GravarArquivo(VetorArquivo, tamanho);
            ///------------------------------------------------------------------------
            printf("Vetor ja ordenado com 100.000\n");
            VetorArquivo = LendoArquivo("vetores/100000-crescente.txt",&tamanho);
            quicksort(VetorArquivo,0,tamanho-1);
            printResultados();
            //GravarArquivo(VetorArquivo, tamanho);
            fclose(gnuplot);
            ///-----------------------------------------------------------------------
             printf("|================================================================|\n");

             gnuplot = fopen("relatorios/quick-sort-inv.dat", "w");
            printf("Vetor ordenando inverso com 100\n");
            fprintf(gnuplot, "#ORDENANDO INVERSO\n#Tamanho\t Tempo\t\t Comparacao\t trocas\n");
            VetorArquivo = LendoArquivo("vetores/100-decrescente.txt",&tamanho);
            quicksort(VetorArquivo,0,tamanho-1);
            printResultados();
           // GravarArquivo(VetorArquivo, tamanho);
            ///-----------------------------------------------------------------------
            printf("Vetor ordenando inverso com 1.000\n");
            VetorArquivo = LendoArquivo("vetores/1000-decrescente.txt",&tamanho);
            quicksort(VetorArquivo,0,tamanho-1);
            printResultados();
            //GravarArquivo(VetorArquivo, tamanho);
            ///------------------------------------------------------------------------
            printf("Vetor ordenando inverso com 10.000\n");
            VetorArquivo = LendoArquivo("vetores/10000-decrescente.txt",&tamanho);
            quicksort(VetorArquivo,0,tamanho-1);
            printResultados();
           // GravarArquivo(VetorArquivo, tamanho);
            ///------------------------------------------------------------------------
            printf("Vetor ordenando inverso com 50.000\n");
            VetorArquivo = LendoArquivo("vetores/50000-decrescente.txt",&tamanho);
            quicksort(VetorArquivo,0,tamanho-1);
            printResultados();
          //  GravarArquivo(VetorArquivo, tamanho);
            ///------------------------------------------------------------------------
            printf("Vetor ordenando inverso com 100.000\n");
            VetorArquivo = LendoArquivo("vetores/100000-decrescente.txt",&tamanho);
            quicksort(VetorArquivo,0,tamanho-1);
            printResultados();
           // GravarArquivo(VetorArquivo, tamanho);
            fclose(gnuplot);
            ///-----------------------------------------------------------------------

            system("gnuplot -bg gray90 script_gnuplot/plota4.gnu");


            break;
        case 6:
            gnuplot = fopen("relatorios/merge-sort-rand.dat", "w");
             printf("Ordenando vetor com 100 elementos\n");
            fprintf(gnuplot, "#RANDOMICOS\n#Tamanho\t Tempo\t\t Comparacao\t trocas\n");
            VetorArquivo = LendoArquivo("vetores/100-random.txt",&tamanho);
            mergeSort(VetorArquivo,vetor2,0,tamanho);
            printResultados();
            MostarVetor(VetorArquivo,tamanho);
            //GravarArquivo(VetorArquivo, tamanho);
            ///-----------------------------------------------------------------------
            printf("Ordenando vetor com 1.000 elementos\n");
            VetorArquivo = LendoArquivo("vetores/1000-random.txt",&tamanho);
             mergeSort(VetorArquivo,vetor2,0,tamanho);
            printResultados();
            //GravarArquivo(VetorArquivo, tamanho);
            ///------------------------------------------------------------------------
            printf("Ordenando vetor com 10.000 elementos\n");
            VetorArquivo = LendoArquivo("vetores/10000-random.txt",&tamanho);
             mergeSort(VetorArquivo,vetor2,0,tamanho);
            printResultados();
            //GravarArquivo(VetorArquivo, tamanho);
            ///------------------------------------------------------------------------
            printf("Ordenando vetor de 50.000 elementos\n");
            VetorArquivo = LendoArquivo("vetores/50000-random.txt",&tamanho);
             mergeSort(VetorArquivo,vetor2,0,tamanho);
            printResultados();
           // GravarArquivo(VetorArquivo, tamanho);
            ///------------------------------------------------------------------------
            printf("Ordenando vetor de 100.000 elementos \n");
            VetorArquivo = LendoArquivo("vetores/100000-random.txt",&tamanho);
            mergeSort(VetorArquivo,vetor2,0,tamanho);
            printResultados();
           // GravarArquivo(VetorArquivo, tamanho);
            fclose(gnuplot);
            ///-----------------------------------------------------------------------
            printf("|================================================================|\n");

            gnuplot = fopen("relatorios/merge-sort-ord.dat", "w");
            printf("Vetor ja ordenado com 100\n");
            fprintf(gnuplot, "#ORDENANDOS\n#Tamanho\t Tempo\t\t Comparacao\t trocas\n");
            VetorArquivo = LendoArquivo("vetores/100-crescente.txt",&tamanho);
             mergeSort(VetorArquivo,vetor2,0,tamanho);
            printResultados();
            //GravarArquivo(VetorArquivo, tamanho);

            ///-----------------------------------------------------------------------
            printf("Vetor ja ordenado com 1.000\n");
            VetorArquivo = LendoArquivo("vetores/1000-crescente.txt",&tamanho);
             mergeSort(VetorArquivo,vetor2,0,tamanho);
           printResultados();
           // GravarArquivo(VetorArquivo, tamanho);
            ///------------------------------------------------------------------------
            printf("Vetor ja ordenado com 10.000\n");
            VetorArquivo = LendoArquivo("vetores/10000-crescente.txt",&tamanho);
             mergeSort(VetorArquivo,vetor2,0,tamanho);
            printResultados();
            //GravarArquivo(VetorArquivo, tamanho);
            ///------------------------------------------------------------------------
            printf("Vetor ja ordenado com 50.000\n");
            VetorArquivo = LendoArquivo("vetores/50000-crescente.txt",&tamanho);
             mergeSort(VetorArquivo,vetor2,0,tamanho);
           printResultados();
           // GravarArquivo(VetorArquivo, tamanho);
            ///------------------------------------------------------------------------
            printf("Vetor ja ordenado com 100.000\n");
            VetorArquivo = LendoArquivo("vetores/100000-crescente.txt",&tamanho);
             mergeSort(VetorArquivo,vetor2,0,tamanho);
           printResultados();
           // GravarArquivo(VetorArquivo, tamanho);
            fclose(gnuplot);
            ///-----------------------------------------------------------------------
             printf("|================================================================|\n");

             gnuplot = fopen("relatorios/merge-sort-inv.dat", "w");
            printf("Vetor ordenando inverso com 100\n");
            fprintf(gnuplot, "#ORDENANDO INVERSO\n#Tamanho\t Tempo\t\t Comparacao\t trocas\n");
            VetorArquivo = LendoArquivo("vetores/100-decrescente.txt",&tamanho);
             mergeSort(VetorArquivo,vetor2,0,tamanho);
           printResultados();
           // GravarArquivo(VetorArquivo, tamanho);

            ///-----------------------------------------------------------------------
            printf("Vetor ordenando inverso com 1.000\n");
            VetorArquivo = LendoArquivo("vetores/1000-decrescente.txt",&tamanho);
             mergeSort(VetorArquivo,vetor2,0,tamanho);
          printResultados();
          //  GravarArquivo(VetorArquivo, tamanho);
            ///------------------------------------------------------------------------
            printf("Vetor ordenando inverso com 10.000\n");
            VetorArquivo = LendoArquivo("vetores/10000-decrescente.txt",&tamanho);
             mergeSort(VetorArquivo,vetor2,0,tamanho);
           printResultados();
           // GravarArquivo(VetorArquivo, tamanho);
            ///------------------------------------------------------------------------
            printf("Vetor ordenando inverso com 50.000\n");
            VetorArquivo = LendoArquivo("vetores/50000-decrescente.txt",&tamanho);
             mergeSort(VetorArquivo,vetor2,0,tamanho);
            printResultados();
            //GravarArquivo(VetorArquivo, tamanho);
            ///------------------------------------------------------------------------
            printf("Vetor ordenando inverso com 100.000\n");
            VetorArquivo = LendoArquivo("vetores/100000-decrescente.txt",&tamanho);
             mergeSort(VetorArquivo,vetor2,0,tamanho);
           printResultados();
           // GravarArquivo(VetorArquivo, tamanho);
            fclose(gnuplot);
            ///-----------------------------------------------------------------------

            system("gnuplot -bg gray90 script_gnuplot/plota5.gnu");
            break;
        case 7:

            gnuplot = fopen("relatorios/shell-sort-rond.dat", "w");

            printf("Ordenando vetor com 100 elementos\n");
            fprintf(gnuplot, "#RANDOMICOS\n#Tamanho\t Tempo\t\t Comparacao\t trocas\n");
            VetorArquivo = LendoArquivo("vetores/100-random.txt",&tamanho);
            shellSort(VetorArquivo,tamanho);
            GravarArquivo(VetorArquivo, tamanho);
            printResultados();
            ///-----------------------------------------------------------------------
            printf("Ordenando vetor com 1.000 elementos\n");
            VetorArquivo = LendoArquivo("vetores/1000-random.txt",&tamanho);
            shellSort(VetorArquivo,tamanho);
            GravarArquivo(VetorArquivo, tamanho);
            printResultados();
            ///------------------------------------------------------------------------
            printf("Ordenando vetor com 10.000 elementos\n");
            VetorArquivo = LendoArquivo("vetores/10000-random.txt",&tamanho);
            shellSort(VetorArquivo,tamanho);
            GravarArquivo(VetorArquivo, tamanho);
            printResultados();
            ///------------------------------------------------------------------------
            printf("Ordenando vetor de 50.000 elementos\n");
            VetorArquivo = LendoArquivo("vetores/50000-random.txt",&tamanho);
            shellSort(VetorArquivo,tamanho);
            GravarArquivo(VetorArquivo, tamanho);
            printResultados();
            ///------------------------------------------------------------------------
            printf("Ordenando vetor de 100.000 elementos \n");
            VetorArquivo = LendoArquivo("vetores/100000-random.txt",&tamanho);
            shellSort(VetorArquivo,tamanho);
            GravarArquivo(VetorArquivo, tamanho);
            printResultados();
            fclose(gnuplot);
            ///-----------------------------------------------------------------------
            printf("|================================================================|\n");

            gnuplot = fopen("relatorios/shell-sort-ord.dat", "w");
            printf("Vetor ja ordenado com 100\n");
            fprintf(gnuplot, "#ORDENANDOS\n#Tamanho\t Tempo\t\t Comparacao\t trocas\n");
            VetorArquivo = LendoArquivo("vetores/100-crescente.txt",&tamanho);
            shellSort(VetorArquivo,tamanho);
            GravarArquivo(VetorArquivo, tamanho);
            printResultados();
            ///-----------------------------------------------------------------------
            printf("Vetor ja ordenado com 1.000\n");
            VetorArquivo = LendoArquivo("vetores/1000-crescente.txt",&tamanho);
            shellSort(VetorArquivo,tamanho);
            GravarArquivo(VetorArquivo, tamanho);
            printResultados();
            ///------------------------------------------------------------------------
            printf("Vetor ja ordenado com 10.000\n");
            VetorArquivo = LendoArquivo("vetores/10000-crescente.txt",&tamanho);
            shellSort(VetorArquivo,tamanho);
            GravarArquivo(VetorArquivo, tamanho);
            printResultados();
            ///------------------------------------------------------------------------
            printf("Vetor ja ordenado com 50.000\n");
            VetorArquivo = LendoArquivo("vetores/50000-crescente.txt",&tamanho);
            shellSort(VetorArquivo,tamanho);
            GravarArquivo(VetorArquivo, tamanho);
            printResultados();
            ///------------------------------------------------------------------------
            printf("Vetor ja ordenado com 100.000\n");
            VetorArquivo = LendoArquivo("vetores/100000-crescente.txt",&tamanho);
            shellSort(VetorArquivo,tamanho);
            GravarArquivo(VetorArquivo, tamanho);
            printResultados();
            fclose(gnuplot);
            ///-----------------------------------------------------------------------
             printf("|================================================================|\n");

             gnuplot = fopen("relatorios/shell-sort-inv.dat", "w");
            printf("Vetor ordenando inverso com 100\n");
            fprintf(gnuplot, "#ORDENANDO INVERSO\n#Tamanho\t Tempo\t\t Comparacao\t trocas\n");
            VetorArquivo = LendoArquivo("vetores/100-decrescente.txt",&tamanho);
            shellSort(VetorArquivo,tamanho);
            GravarArquivo(VetorArquivo, tamanho);
            printResultados();
            ///-----------------------------------------------------------------------
            printf("Vetor ordenando inverso com 1.000\n");
            VetorArquivo = LendoArquivo("vetores/1000-decrescente.txt",&tamanho);
            shellSort(VetorArquivo,tamanho);
            GravarArquivo(VetorArquivo, tamanho);
            printResultados();
            ///------------------------------------------------------------------------
            printf("Vetor ordenando inverso com 10.000\n");
            VetorArquivo = LendoArquivo("vetores/10000-decrescente.txt",&tamanho);
            shellSort(VetorArquivo,tamanho);
            GravarArquivo(VetorArquivo, tamanho);
            printResultados();
            ///------------------------------------------------------------------------
            printf("Vetor ordenando inverso com 50.000\n");
            VetorArquivo = LendoArquivo("vetores/50000-decrescente.txt",&tamanho);
            shellSort(VetorArquivo,tamanho);
            GravarArquivo(VetorArquivo, tamanho);
            printResultados();
            ///------------------------------------------------------------------------
            printf("Vetor ordenando inverso com 100.000\n");
            VetorArquivo = LendoArquivo("vetores/100000-decrescente.txt",&tamanho);
            shellSort(VetorArquivo,tamanho);
            GravarArquivo(VetorArquivo, tamanho);
            printResultados();
            fclose(gnuplot);
            ///-----------------------------------------------------------------------

            system("gnuplot -bg gray90 script_gnuplot/plota6.gnu");
            break;
        case 0:

            //printf("Finalizado\n");
            break;
        }
    }
    while(op!=0);
     system("gnuplot -bg gray90 script_gnuplot/plota7.gnu");
    return 1;
}
