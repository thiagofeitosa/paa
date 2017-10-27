#ifndef ORDENA_H_INCLUDED
#define ORDENA_H_INCLUDED
#define MAX_STR 100
#include <time.h>

clock_t tempoInicio, tempoFim;
FILE *gnuplot;
unsigned long  troca=0,comparacao=0;


///cria todos os arquivos, o parametro é o tamanho do vetor
void createFiles(long int n)
{
    //cria os arquivos de vetores em ordem crescente
  long int i;
  srand(time(NULL));   
  char filename[MAX_STR];
  snprintf(filename, MAX_STR, "vetores/%ld", n);

  strcat(filename,"-crescente.txt");
    //parte de abrir e escrever o txt
  FILE * f;
  f = fopen (filename,"w+");
  if (f != NULL)
  {
    for (i = 0; i < n; i++)
    {
      fprintf(f, "%ld\n ",i+1);
    }

    fclose (f);
  }

  //cria os arquivos de vetores em ordem randomica
  snprintf(filename, MAX_STR, "vetores/%ld",n);
  strcat(filename,"-random.txt");
  //abrir e escrever txt
  FILE * fs;
  fs = fopen (filename,"w+");
  if (fs != NULL)
  {
    for (i = 0; i < n; i++)
    {
      fprintf(fs, "%ld\n ",rand() % (n+1));
    }

    fclose (fs);
  } 
  //cria os arquivos de vetores em ordem descrescente
  snprintf(filename, MAX_STR, "vetores/%ld",n);
  strcat(filename,"-decrescente.txt");

  FILE * fr;
  fr = fopen (filename,"w+");
  if (fs != NULL)
  {
    for (i = n; i > 0; i--)
    {
      fprintf(fr, "%ld\n ",i);
    }

    fclose (fr);
  } 

}

///chama a função de criar os arquivos passando paramentro do tamanho do vetor que se quer
void createAllFiles()
{
  createFiles(100);
  createFiles(1000);
  createFiles(10000);
  createFiles(50000);
  createFiles(100000);
  //createFiles(200000);
  //createFiles(500000);
  //createFiles(1000000);
  printf("Arquivos criados.\n");
}

//função que lê os arquivos do vetor, parametros de nome do arquivo e quantidade de linhas 
//
int *LendoArquivo(char *nomeArq, long int *tamanho)
{
    FILE *arquivo;
    int *vetor;
    long int i, LinhasdoArquivo;

    char linha[200];


    //abre arquivo e descobre quantidade de numeros para o vetor
    arquivo = fopen(nomeArq,"r");

    if (!arquivo)
    {
        printf("Arquivo nao existe\n");
        exit(0);
    }

    LinhasdoArquivo = 0;
    //
    while (fgets(linha,200,arquivo))
    {
        LinhasdoArquivo++;
    }
    fclose(arquivo);
    *tamanho = LinhasdoArquivo;
    //escreve no arquivo o tamanho do vetor
    fprintf( gnuplot, "%d\t\t", LinhasdoArquivo);
    vetor = malloc(sizeof(int) * LinhasdoArquivo);

    arquivo = fopen(nomeArq,"r");
    i = 0;
    while (fgets(linha,200,arquivo))
    {
        //percorrer arquivo para gravar numeros no vetor a ser ordenado
        vetor[i] = atoi(linha);
        i++;
    }

    fclose(arquivo);
    return vetor;
}
///----------------------------------------------------------------------------------------
void BubbleSort(int *vetor, long int n)
{
    unsigned long long int i, j;
    troca = 0;
    comparacao = 0;
    tempoInicio = clock();
    for (j=0; j<n-1; j++)
    {
        for (i=0; i<n-(j+1); i++)
        {
            comparacao++;
            if (vetor[i]>vetor[i+1])
            {
                int aux = vetor[i+1];
                vetor[i+1] = vetor[i];
                vetor[i]= aux;
                troca++;

            }
        }
    }
    tempoFim = clock();
}
///----------------------------------------------------------------------------------------
void shellSort(int *Vetor, long int tamanho)
{
    //pega a chave que é o tamanho-1 do vetor e divide por dois, pra que fique na metade
    long int i = (tamanho - 1) / 2;
    int chave, k, aux;
    troca = 0;
    comparacao = 0;
    tempoInicio = clock();

    while(i != 0)
    {
        do
        {
            chave = 1;
            for(k = 0; k < tamanho - i; ++k)
            {//apenas compara as posições de acordo com as chaves
                comparacao++;
                if(Vetor[k] > Vetor[k + i])
                {//efetua a troca
                    aux = Vetor[k];
                    Vetor[k] = Vetor[k + i];
                    Vetor[k + i] = aux;
                    chave = 0;
                    troca++;
                }
            }
        }
        while(chave == 0);
        i = i / 2;
    }
     tempoFim = clock();
}
///----------------------------------------------------------------------------------------
void selectSort(int *vetor,long int n)
{
    long int i, j, posMenor;
    int aux;
    troca = 0;
    comparacao = 0;

    tempoInicio = clock();
    for (i = 0; i < n - 1; i++)
    {
        posMenor = i;
        for (j = i + 1; j < n; j++)
        {//percorre o vetor pra achar o menor valor e seta ele pra ser trocado
            comparacao++;
            if (vetor[j] < vetor[posMenor]) posMenor = j;
        }

        if (posMenor != i)
        { //troca o de menor valor com a posição [i]
            troca++;
            aux = vetor[i];
            vetor[i] = vetor[posMenor];
            vetor[posMenor] = aux;
        }
    }
    tempoFim = clock();
}
///----------------------------------------------------------------------------------------
void insertionSort(int *vetor, long int n)
{
    long long int i, j;
    int aux;
    troca = 0;
    comparacao = 0;

    tempoInicio = clock();
    for (i = 1; i < n; i++)
    {//compara da segunda posição pra frente com o anterior
        aux = vetor[i];
        for (j = i - 1; j >= 0 && aux < vetor[j]; --j, comparacao++)
        {//troca quando for menor
            vetor[j + 1] = vetor[j];
            troca++;
        }
        vetor[j + 1] = aux;
        troca++;
    }
    tempoFim = clock();
}
//------------------------------------------------------------------------------------------------
void mergee (int *vetor,int v2[],int inicio1, int inicio2,int fim2)
{
    long int n1=inicio1;
    long int n2=inicio2;
    long int fim1=n2-1;
    long int aux=0,i;

    tempoInicio = clock();
    comparacao++;
    while((n1<=fim1) && (n2<=fim2))
    {

        if (vetor[n1]<vetor[n2])
        {
            troca++;
            comparacao++;
            v2[aux++] = vetor[n1++];

        }
        else
        {
            troca++;
            comparacao++;

            v2[aux++] = vetor[n2++];

        }

    }

    while(n1<=fim1)
    {
        v2[aux++] = vetor[n1++];
        troca++;
        comparacao++;
    }
    while(n2<=fim2)
    {
        v2[aux++] = vetor[n2++];
        troca++;
        comparacao++;

    }
    for(i=0; i<aux; i++)
    {
        vetor[i+inicio1]=v2[i];
         troca++;
    }

    tempoFim = clock();
}
void mergeSort (int *vetor, int v2[],long int esq, long int dir)
{
    long int meio,valor,valor2,res;

    if(esq<dir)
    {
        meio=(esq+dir)/2;
        mergeSort(vetor,v2,esq,meio);
        mergeSort(vetor,v2,meio+1,dir);
        mergee(vetor,v2,esq,meio+1,dir);
    }
}
///----------------------------------------------------------------------------------------
void quicksort(int *vetor, int esq, int dir) {

    int i, j, pivo, aux;

    i = esq;
    j = dir;

    tempoInicio = clock();
    pivo = vetor[(esq + dir) / 2]; //Elemento central como pivô

    while(i <= j) {
        while(vetor[i] < pivo && i < dir) {//enquanto i for menor que pivô incrementa i
            i++;
            comparacao++;
        }
        while(vetor[j] > pivo && j > esq) {//enquanto j for maior que pivô decrementa j
            j--;
            comparacao++;
        }
        if(i <= j) {//quando i, "encosta" no j faz se a comparação e se for preciso a troca
            aux = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = aux;
            i++;
            j--;
             troca++;
        }
    }//logo chama se recursivamente a função pra esquerda e depois direita
    if(j > esq) {
        quicksort(vetor, esq, j);
    }
    if(i < dir) {
        quicksort(vetor, i, dir);
    }
    tempoFim = clock();
}


//Essa função grava o vetor ordenando em um arquivo txt
void GravarArquivo(int *vetor, long int tamanho)
{
    long int i;
    FILE *gravar;
    char Nome_arquivo[200];
    //nomeando arquivo
    sprintf(Nome_arquivo, "vetores/%ld-Ordenado.txt", tamanho-1);

    //escrever
    gravar = fopen(Nome_arquivo,"w");
    for (i = 0; i < tamanho; i++)
    {
        fprintf( gravar," %d\n", vetor[i]);
        fflush(gravar);
    }
    fclose(gravar);
}

void printResultados(){
    //grava os resultados de comparações, trocas e tempo de cpu em um arquivo.
    fprintf( gnuplot," %f\t", (float)(tempoFim - tempoInicio)/CLOCKS_PER_SEC);
    fprintf( gnuplot, "%ld\t\t",comparacao);
    fprintf( gnuplot, "%ld\n", troca);

    //printa no console informações, tirado da execução pra poupar espaço no console

     //printf("comparacao: %ld\n Trocas %ld\n",comparacao,troca);
     //printf("Tempo: %f\n", (float)(tempoFim - tempoInicio)/CLOCKS_PER_SEC);
}

void menu(){
    int *VetorArquivo;
    long int tamanho;
    long int vetor2[100000];//vetor auxilixar para verge sort
    int op;
    system ("clear");
    printf("\n");
    printf("Thiago Gonçalves Feitosa.\nTrabalho de Projeto e análise de algorítimos\n");
    do
    {        
        printf("\n\t|----------|      MENU      | ------------|");
        printf("\n\t|-----------------------------------------|");
        printf("\n\t| 1 -----|CRIAR ARQUIVOS .TXT|------------|");
        printf("\n\t| 2 -------| BUBBLE  SORT |---------------|");
        printf("\n\t| 3 -------| SELECT  SORT |---------------|");
        printf("\n\t| 4 -------| INSERT  SORT |---------------|");
        printf("\n\t| 5 -------| QUICK   SORT |---------------|");
        printf("\n\t| 6 -------| MERGE   SORT |---------------|");
        printf("\n\t| 7 -------| SHELL   SORT |---------------|");
        printf("\n\t| 8 -----| REMOVER ARQUIVOS |-------------|");
        printf("\n\t| 0 -------|      SAIR    |---------------|");
        printf("\n\t|-----------------------------------------|\n");
        scanf("\t %d",&op);

        switch(op)
        {
        case 1 :
            createAllFiles();
            break;
        case 2 :
            gnuplot = fopen("relatorios/bubble-sorte-rand.dat", "w");

            printf("Ordenando vetor random com 100 elementos\n");
            fprintf(gnuplot, "#RANDOMICOS\n#Tamanho\t Tempo\t\t Comparacao\t trocas\n");
            VetorArquivo = LendoArquivo("vetores/100-random.txt",&tamanho);
            BubbleSort(VetorArquivo, tamanho);
            GravarArquivo(VetorArquivo, tamanho);
            printResultados();
            ///-----------------------------------------------------------------------
            printf("Ordenando vetor random com 1.000 elementos\n");
            VetorArquivo = LendoArquivo("vetores/1000-random.txt",&tamanho);
            BubbleSort(VetorArquivo, tamanho);
            GravarArquivo(VetorArquivo, tamanho);
            printResultados();
            ///------------------------------------------------------------------------
            printf("Ordenando vetor random com 10.000 elementos\n");
            VetorArquivo = LendoArquivo("vetores/10000-random.txt",&tamanho);
            BubbleSort(VetorArquivo, tamanho);
            GravarArquivo(VetorArquivo, tamanho);
            printResultados();
            ///------------------------------------------------------------------------
            printf("Ordenando vetor random de 50.000 elementos\n");
            VetorArquivo = LendoArquivo("vetores/50000-random.txt",&tamanho);
            BubbleSort(VetorArquivo, tamanho);
            GravarArquivo(VetorArquivo, tamanho);
            printResultados();
            ///------------------------------------------------------------------------
            printf("Ordenando vetor random de 100.000 elementos \n");
            VetorArquivo = LendoArquivo("vetores/100000-random.txt",&tamanho);
            BubbleSort(VetorArquivo, tamanho);
            GravarArquivo(VetorArquivo, tamanho);
            printResultados();
            fclose(gnuplot);
            ///-----------------------------------------------------------------------
            printf("|================================================================|\n");

            gnuplot = fopen("relatorios/bubbleSorte-ord.dat", "w");
            printf("Ordenando vetor crescente com 100\n");
            fprintf(gnuplot, "#ORDENANDOS\n#Tamanho\t Tempo\t\t Comparacao\t trocas\n");
            VetorArquivo = LendoArquivo("vetores/100-crescente.txt",&tamanho);
            BubbleSort(VetorArquivo, tamanho);
            GravarArquivo(VetorArquivo, tamanho);
            printResultados();
            ///-----------------------------------------------------------------------
            printf("Ordenando vetor crescente com 1.000\n");
            VetorArquivo = LendoArquivo("vetores/1000-crescente.txt",&tamanho);
            BubbleSort(VetorArquivo, tamanho);
            GravarArquivo(VetorArquivo, tamanho);
            printResultados();
            ///------------------------------------------------------------------------
            printf("Ordenando vetor crescente com 10.000\n");
            VetorArquivo = LendoArquivo("vetores/10000-crescente.txt",&tamanho);
            BubbleSort(VetorArquivo, tamanho);
            GravarArquivo(VetorArquivo, tamanho);
            printResultados();
            ///------------------------------------------------------------------------
            printf("Ordenando vetor crescente com 50.000\n");
            VetorArquivo = LendoArquivo("vetores/50000-crescente.txt",&tamanho);
            BubbleSort(VetorArquivo, tamanho);
            GravarArquivo(VetorArquivo, tamanho);
            printResultados();
            ///------------------------------------------------------------------------
            printf("Ordenando vetor crescente com 100.000\n");
            VetorArquivo = LendoArquivo("vetores/100000-crescente.txt",&tamanho);
            BubbleSort(VetorArquivo, tamanho);
            GravarArquivo(VetorArquivo, tamanho);
            printResultados();
            fclose(gnuplot);
            ///-----------------------------------------------------------------------
             printf("|================================================================|\n");

             gnuplot = fopen("relatorios/bubbleSorte-inv.dat", "w");
            printf("Ordenando vetor decrescente com 100\n");
            fprintf(gnuplot, "#ORDENANDO INVERSO\n#Tamanho\t Tempo\t\t Comparacao\t trocas\n");
            VetorArquivo = LendoArquivo("vetores/100-decrescente.txt",&tamanho);
            BubbleSort(VetorArquivo, tamanho);
            GravarArquivo(VetorArquivo, tamanho);
            printResultados();
            ///-----------------------------------------------------------------------
            printf("Ordenando vetor decrescente com 1.000\n");
            VetorArquivo = LendoArquivo("vetores/1000-decrescente.txt",&tamanho);
            BubbleSort(VetorArquivo, tamanho);
            GravarArquivo(VetorArquivo, tamanho);
            printResultados();
            ///------------------------------------------------------------------------
            printf("Ordenando vetor decrescente com 10.000\n");
            VetorArquivo = LendoArquivo("vetores/10000-decrescente.txt",&tamanho);
            BubbleSort(VetorArquivo, tamanho);
            GravarArquivo(VetorArquivo, tamanho);
            printResultados();
            ///------------------------------------------------------------------------
            printf("Ordenando vetor decrescente com 50.000\n");
            VetorArquivo = LendoArquivo("vetores/50000-decrescente.txt",&tamanho);
            BubbleSort(VetorArquivo, tamanho);
            GravarArquivo(VetorArquivo, tamanho);
            printResultados();
            ///------------------------------------------------------------------------
            printf("Ordenando vetor decrescente com 100.000\n");
            VetorArquivo = LendoArquivo("vetores/100000-decrescente.txt",&tamanho);
            BubbleSort(VetorArquivo, tamanho);
            GravarArquivo(VetorArquivo, tamanho);
            printResultados();
            fclose(gnuplot);
            ///-----------------------------------------------------------------------

            system("gnuplot -bg gray90 script_gnuplot/plota.gnu");

            break;

        case 3:

            gnuplot = fopen("relatorios/Select-sort-rand.dat", "w");

            printf("Ordenando vetor random com 100 elementos\n");
            fprintf(gnuplot, "#RANDOMICOS\n#Tamanho\t Tempo\t\t Comparacao\t trocas\n");
            VetorArquivo = LendoArquivo("vetores/100-random.txt",&tamanho);
            selectSort(VetorArquivo, tamanho);
            GravarArquivo(VetorArquivo, tamanho);
            printResultados();
            ///-----------------------------------------------------------------------
            printf("Ordenando vetor random com 1.000 elementos\n");
            VetorArquivo = LendoArquivo("vetores/1000-random.txt",&tamanho);
            selectSort(VetorArquivo, tamanho);
            GravarArquivo(VetorArquivo, tamanho);
            printResultados();
            ///------------------------------------------------------------------------
            printf("Ordenando vetor random com 10.000 elementos\n");
            VetorArquivo = LendoArquivo("vetores/10000-random.txt",&tamanho);
            selectSort(VetorArquivo, tamanho);
            GravarArquivo(VetorArquivo, tamanho);
            printResultados();
            ///------------------------------------------------------------------------
            printf("Ordenando vetor random de 50.000 elementos\n");
            VetorArquivo = LendoArquivo("vetores/50000-random.txt",&tamanho);
            selectSort(VetorArquivo, tamanho);
            GravarArquivo(VetorArquivo, tamanho);
            printResultados();
            ///------------------------------------------------------------------------
            printf("Ordenando vetor random de 100.000 elementos \n");
            VetorArquivo = LendoArquivo("vetores/100000-random.txt",&tamanho);
            selectSort(VetorArquivo, tamanho);
            GravarArquivo(VetorArquivo, tamanho);
            printResultados();
            fclose(gnuplot);
            ///-----------------------------------------------------------------------
            printf("|================================================================|\n");

            gnuplot = fopen("relatorios/Select-sort-ord.dat", "w");
            printf("Ordenando vetor crescente com 100\n");
            fprintf(gnuplot, "#ORDENANDOS\n#Tamanho\t Tempo\t\t Comparacao\t trocas\n");
            VetorArquivo = LendoArquivo("vetores/100-crescente.txt",&tamanho);
            selectSort(VetorArquivo, tamanho);
            GravarArquivo(VetorArquivo, tamanho);
            printResultados();
            ///-----------------------------------------------------------------------
            printf("Ordenando vetor crescente com 1.000\n");
            VetorArquivo = LendoArquivo("vetores/1000-crescente.txt",&tamanho);
            selectSort(VetorArquivo, tamanho);
            GravarArquivo(VetorArquivo, tamanho);
            printResultados();
            ///------------------------------------------------------------------------
            printf("Ordenando vetor crescente com 10.000\n");
            VetorArquivo = LendoArquivo("vetores/10000-crescente.txt",&tamanho);
            selectSort(VetorArquivo, tamanho);
            GravarArquivo(VetorArquivo, tamanho);
            printResultados();
            ///------------------------------------------------------------------------
            printf("Ordenando vetor crescente com 50.000\n");
            VetorArquivo = LendoArquivo("vetores/50000-crescente.txt",&tamanho);
            selectSort(VetorArquivo, tamanho);
            GravarArquivo(VetorArquivo, tamanho);
            printResultados();
            ///------------------------------------------------------------------------
            printf("Ordenando vetor crescente com 100.000\n");
            VetorArquivo = LendoArquivo("vetores/100000-crescente.txt",&tamanho);
            selectSort(VetorArquivo, tamanho);
            GravarArquivo(VetorArquivo, tamanho);
            printResultados();
            fclose(gnuplot);
            ///-----------------------------------------------------------------------
             printf("|================================================================|\n");

             gnuplot = fopen("relatorios/Select-sort-inv.dat", "w");
            printf("Ordenando vetor decrescente com 100\n");
            fprintf(gnuplot, "#ORDENANDO INVERSO\n#Tamanho\t Tempo\t\t Comparacao\t trocas\n");
            VetorArquivo = LendoArquivo("vetores/100-decrescente.txt",&tamanho);
            selectSort(VetorArquivo, tamanho);
            GravarArquivo(VetorArquivo, tamanho);
            printResultados();
            ///-----------------------------------------------------------------------
            printf("Ordenando vetor decrescente com 1.000\n");
            VetorArquivo = LendoArquivo("vetores/1000-decrescente.txt",&tamanho);
            selectSort(VetorArquivo, tamanho);
            GravarArquivo(VetorArquivo, tamanho);
            printResultados();
            ///------------------------------------------------------------------------
            printf("Ordenando vetor decrescente com 10.000\n");
            VetorArquivo = LendoArquivo("vetores/10000-decrescente.txt",&tamanho);
            selectSort(VetorArquivo, tamanho);
            GravarArquivo(VetorArquivo, tamanho);
            printResultados();
            ///------------------------------------------------------------------------
            printf("Ordenando vetor decrescente com 50.000\n");
            VetorArquivo = LendoArquivo("vetores/50000-decrescente.txt",&tamanho);
            selectSort(VetorArquivo, tamanho);
            GravarArquivo(VetorArquivo, tamanho);
            printResultados();
            ///------------------------------------------------------------------------
            printf("Ordenando vetor decrescente com 100.000\n");
            VetorArquivo = LendoArquivo("vetores/100000-decrescente.txt",&tamanho);
            selectSort(VetorArquivo, tamanho);
            GravarArquivo(VetorArquivo, tamanho);
            printResultados();
            fclose(gnuplot);
            ///-----------------------------------------------------------------------

            system("gnuplot -bg gray90 script_gnuplot/plota2.gnu");
            break;
        case 4:

            gnuplot = fopen("relatorios/Insert-sort-rand.dat", "w");

            printf("Ordenando vetor random com 100 elementos\n");
            fprintf(gnuplot, "#RANDOMICOS\n#Tamanho\t Tempo\t\t Comparacao\t trocas\n");
            VetorArquivo = LendoArquivo("vetores/100-random.txt",&tamanho);
            insertionSort(VetorArquivo, tamanho);
            GravarArquivo(VetorArquivo, tamanho);
            printResultados();
            ///-----------------------------------------------------------------------
            printf("Ordenando vetor random com 1.000 elementos\n");
            VetorArquivo = LendoArquivo("vetores/1000-random.txt",&tamanho);
            insertionSort(VetorArquivo, tamanho);
            GravarArquivo(VetorArquivo, tamanho);
            printResultados();
            ///------------------------------------------------------------------------
            printf("Ordenando vetor random com 10.000 elementos\n");
            VetorArquivo = LendoArquivo("vetores/10000-random.txt",&tamanho);
            insertionSort(VetorArquivo, tamanho);
            GravarArquivo(VetorArquivo, tamanho);
            printResultados();
            ///------------------------------------------------------------------------
            printf("Ordenando vetor random de 50.000 elementos\n");
            VetorArquivo = LendoArquivo("vetores/50000-random.txt",&tamanho);
            insertionSort(VetorArquivo, tamanho);
            GravarArquivo(VetorArquivo, tamanho);
            printResultados();
            ///------------------------------------------------------------------------
            printf("Ordenando vetor random de 100.000 elementos \n");
            VetorArquivo = LendoArquivo("vetores/100000-random.txt",&tamanho);
            insertionSort(VetorArquivo, tamanho);
            GravarArquivo(VetorArquivo, tamanho);
            printResultados();
            fclose(gnuplot);
            ///-----------------------------------------------------------------------
            printf("|================================================================|\n");

            gnuplot = fopen("relatorios/Insert-sort-ord.dat", "w");

            printf("Ordenando vetor crescente com 100\n");
            fprintf(gnuplot, "#ORDENANDOS\n#Tamanho\t Tempo\t\t Comparacao\t trocas\n");
            VetorArquivo = LendoArquivo("vetores/100-crescente.txt",&tamanho);
            insertionSort(VetorArquivo, tamanho);
            GravarArquivo(VetorArquivo, tamanho);
            printResultados();
            ///-----------------------------------------------------------------------
            printf("Ordenando vetor crescente com 1.000\n");
            VetorArquivo = LendoArquivo("vetores/1000-crescente.txt",&tamanho);
            insertionSort(VetorArquivo, tamanho);
            GravarArquivo(VetorArquivo, tamanho);
            printResultados();
            ///------------------------------------------------------------------------
            printf("Ordenando vetor crescente com 10.000\n");
            VetorArquivo = LendoArquivo("vetores/10000-crescente.txt",&tamanho);
            insertionSort(VetorArquivo, tamanho);
            GravarArquivo(VetorArquivo, tamanho);
            printResultados();
            ///------------------------------------------------------------------------
            printf("Ordenando vetor crescente com 50.000\n");
            VetorArquivo = LendoArquivo("vetores/50000-crescente.txt",&tamanho);
            insertionSort(VetorArquivo, tamanho);
            GravarArquivo(VetorArquivo, tamanho);
            printResultados();
            ///------------------------------------------------------------------------
            printf("Ordenando vetor crescente com 100.000\n");
            VetorArquivo = LendoArquivo("vetores/100000-crescente.txt",&tamanho);
            insertionSort(VetorArquivo, tamanho);
            GravarArquivo(VetorArquivo, tamanho);
            printResultados();
            fclose(gnuplot);
            ///-----------------------------------------------------------------------

            printf("|================================================================|\n");

            gnuplot = fopen("relatorios/Insert-sort-inv.dat", "w");

            printf("Ordenando vetor decrescente com 100\n");
            fprintf(gnuplot, "#ORDENANDO INVERSO\n#Tamanho\t Tempo\t\t Comparacao\t trocas\n");
            VetorArquivo = LendoArquivo("vetores/100-decrescente.txt",&tamanho);
            insertionSort(VetorArquivo, tamanho);
            GravarArquivo(VetorArquivo, tamanho);
            printResultados();
            ///-----------------------------------------------------------------------
            printf("Ordenando vetor decrescente com 1.000\n");
            VetorArquivo = LendoArquivo("vetores/1000-decrescente.txt",&tamanho);
            insertionSort(VetorArquivo, tamanho);
            GravarArquivo(VetorArquivo, tamanho);
            printResultados();
            ///------------------------------------------------------------------------
            printf("Ordenando vetor decrescente com 10.000\n");
            VetorArquivo = LendoArquivo("vetores/10000-decrescente.txt",&tamanho);
            insertionSort(VetorArquivo, tamanho);
            GravarArquivo(VetorArquivo, tamanho);
            printResultados();
            ///------------------------------------------------------------------------
            printf("Ordenando vetor decrescente com 50.000\n");
            VetorArquivo = LendoArquivo("vetores/50000-decrescente.txt",&tamanho);
            insertionSort(VetorArquivo, tamanho);
            GravarArquivo(VetorArquivo, tamanho);
            printResultados();
            ///------------------------------------------------------------------------
            printf("Ordenando vetor decrescente com 100.000\n");
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
            printf("Ordenando vetor random com 100 elementos\n");
            fprintf(gnuplot, "#RANDOMICOS\n#Tamanho\t Tempo\t\t Comparacao\t trocas\n");
            VetorArquivo = LendoArquivo("vetores/100-random.txt",&tamanho);
            quicksort(VetorArquivo,0,tamanho-1);
            printResultados();
            GravarArquivo(VetorArquivo, tamanho);
            ///-----------------------------------------------------------------------
            printf("Ordenando vetor random com 1.000 elementos\n");
            VetorArquivo = LendoArquivo("vetores/1000-random.txt",&tamanho);
            quicksort(VetorArquivo,0,tamanho-1);
            GravarArquivo(VetorArquivo, tamanho);
             printResultados();
            ///------------------------------------------------------------------------
            printf("Ordenando vetor random com 10.000 elementos\n");
            VetorArquivo = LendoArquivo("vetores/10000-random.txt",&tamanho);
            quicksort(VetorArquivo,0,tamanho-1);
            printResultados();
            GravarArquivo(VetorArquivo, tamanho);
            ///------------------------------------------------------------------------
            printf("Ordenando vetor random de 50.000 elementos\n");
            VetorArquivo = LendoArquivo("vetores/50000-random.txt",&tamanho);
            quicksort(VetorArquivo,0,tamanho-1);
            printResultados();
            GravarArquivo(VetorArquivo, tamanho);
            ///------------------------------------------------------------------------
            printf("Ordenando vetor random de 100.000 elementos \n");
            VetorArquivo = LendoArquivo("vetores/100000-random.txt",&tamanho);
            quicksort(VetorArquivo,0,tamanho-1);
            printResultados();
            GravarArquivo(VetorArquivo, tamanho);
            fclose(gnuplot);
            ///-----------------------------------------------------------------------

            printf("|================================================================|\n");

            gnuplot = fopen("relatorios/quick-sort-ord.dat", "w");
            printf("Ordenando vetor crescente com 100\n");
            fprintf(gnuplot, "#ORDENANDOS\n#Tamanho\t Tempo\t\t Comparacao\t trocas\n");
            VetorArquivo = LendoArquivo("vetores/100-crescente.txt",&tamanho);
            quicksort(VetorArquivo,0,tamanho-1);
            printResultados();
            GravarArquivo(VetorArquivo, tamanho);

            ///-----------------------------------------------------------------------
            printf("Ordenando vetor crescente com 1.000\n");
            VetorArquivo = LendoArquivo("vetores/1000-crescente.txt",&tamanho);
            quicksort(VetorArquivo,0,tamanho-1);
            printResultados();
            GravarArquivo(VetorArquivo, tamanho);
            ///------------------------------------------------------------------------
            printf("Ordenando vetor crescente com 10.000\n");
            VetorArquivo = LendoArquivo("vetores/10000-crescente.txt",&tamanho);;
            quicksort(VetorArquivo,0,tamanho-1);
            printResultados();
            GravarArquivo(VetorArquivo, tamanho);
            ///------------------------------------------------------------------------
            printf("Ordenando vetor crescente com 50.000\n");
            VetorArquivo = LendoArquivo("vetores/50000-crescente.txt",&tamanho);
            quicksort(VetorArquivo,0,tamanho-1);
            printResultados();
            GravarArquivo(VetorArquivo, tamanho);
            ///------------------------------------------------------------------------
            printf("Ordenando vetor crescente com 100.000\n");
            VetorArquivo = LendoArquivo("vetores/100000-crescente.txt",&tamanho);
            quicksort(VetorArquivo,0,tamanho-1);
            printResultados();
            GravarArquivo(VetorArquivo, tamanho);
            fclose(gnuplot);
            ///-----------------------------------------------------------------------
            printf("|================================================================|\n");

            gnuplot = fopen("relatorios/quick-sort-inv.dat", "w");
            printf("Ordenando vetor decrescente com 100\n");
            fprintf(gnuplot, "#ORDENANDO INVERSO\n#Tamanho\t Tempo\t\t Comparacao\t trocas\n");
            VetorArquivo = LendoArquivo("vetores/100-decrescente.txt",&tamanho);
            quicksort(VetorArquivo,0,tamanho-1);
            printResultados();
            GravarArquivo(VetorArquivo, tamanho);
            ///-----------------------------------------------------------------------
            printf("Ordenando vetor decrescente com 1.000\n");
            VetorArquivo = LendoArquivo("vetores/1000-decrescente.txt",&tamanho);
            quicksort(VetorArquivo,0,tamanho-1);
            printResultados();
            GravarArquivo(VetorArquivo, tamanho);
            ///------------------------------------------------------------------------
            printf("Ordenando vetor decrescente com 10.000\n");
            VetorArquivo = LendoArquivo("vetores/10000-decrescente.txt",&tamanho);
            quicksort(VetorArquivo,0,tamanho-1);
            printResultados();
            GravarArquivo(VetorArquivo, tamanho);
            ///------------------------------------------------------------------------
            printf("Ordenando vetor decrescente com 50.000\n");
            VetorArquivo = LendoArquivo("vetores/50000-decrescente.txt",&tamanho);
            quicksort(VetorArquivo,0,tamanho-1);
            printResultados();
            GravarArquivo(VetorArquivo, tamanho);
            ///------------------------------------------------------------------------
            printf("Ordenando vetor decrescente com 100.000\n");
            VetorArquivo = LendoArquivo("vetores/100000-decrescente.txt",&tamanho);
            quicksort(VetorArquivo,0,tamanho-1);
            printResultados();
            GravarArquivo(VetorArquivo, tamanho);
            fclose(gnuplot);
            ///-----------------------------------------------------------------------

            system("gnuplot -bg gray90 script_gnuplot/plota4.gnu");


            break;
        case 6:
            gnuplot = fopen("relatorios/merge-sort-rand.dat", "w");
             printf("Ordenando vetor random com 100 elementos\n");
            fprintf(gnuplot, "#RANDOMICOS\n#Tamanho\t Tempo\t\t Comparacao\t trocas\n");
            VetorArquivo = LendoArquivo("vetores/100-random.txt",&tamanho);
            mergeSort(VetorArquivo,vetor2,0,tamanho);
            printResultados();
            GravarArquivo(VetorArquivo, tamanho);
            ///-----------------------------------------------------------------------
            printf("Ordenando vetor random com 1.000 elementos\n");
            VetorArquivo = LendoArquivo("vetores/1000-random.txt",&tamanho);
             mergeSort(VetorArquivo,vetor2,0,tamanho);
            printResultados();
            GravarArquivo(VetorArquivo, tamanho);
            ///------------------------------------------------------------------------
            printf("Ordenando vetor random com 10.000 elementos\n");
            VetorArquivo = LendoArquivo("vetores/10000-random.txt",&tamanho);
             mergeSort(VetorArquivo,vetor2,0,tamanho);
            printResultados();
            GravarArquivo(VetorArquivo, tamanho);
            ///------------------------------------------------------------------------
            printf("Ordenando vetor random de 50.000 elementos\n");
            VetorArquivo = LendoArquivo("vetores/50000-random.txt",&tamanho);
             mergeSort(VetorArquivo,vetor2,0,tamanho);
            printResultados();
            GravarArquivo(VetorArquivo, tamanho);
            ///------------------------------------------------------------------------
            printf("Ordenando vetor random de 100.000 elementos \n");
            VetorArquivo = LendoArquivo("vetores/100000-random.txt",&tamanho);
            mergeSort(VetorArquivo,vetor2,0,tamanho);
            printResultados();
            GravarArquivo(VetorArquivo, tamanho);
            fclose(gnuplot);
            ///-----------------------------------------------------------------------
            printf("|================================================================|\n");

            gnuplot = fopen("relatorios/merge-sort-ord.dat", "w");
            printf("Ordenando vetor crescente com 100\n");
            fprintf(gnuplot, "#ORDENANDOS\n#Tamanho\t Tempo\t\t Comparacao\t trocas\n");
            VetorArquivo = LendoArquivo("vetores/100-crescente.txt",&tamanho);
             mergeSort(VetorArquivo,vetor2,0,tamanho);
            printResultados();
            GravarArquivo(VetorArquivo, tamanho);

            ///-----------------------------------------------------------------------
            printf("Ordenando vetor crescente com 1.000\n");
            VetorArquivo = LendoArquivo("vetores/1000-crescente.txt",&tamanho);
             mergeSort(VetorArquivo,vetor2,0,tamanho);
            printResultados();
            GravarArquivo(VetorArquivo, tamanho);
            ///------------------------------------------------------------------------
            printf("Ordenando vetor crescente com 10.000\n");
            VetorArquivo = LendoArquivo("vetores/10000-crescente.txt",&tamanho);
             mergeSort(VetorArquivo,vetor2,0,tamanho);
            printResultados();
            GravarArquivo(VetorArquivo, tamanho);
            ///------------------------------------------------------------------------
            printf("Ordenando vetor crescente com 50.000\n");
            VetorArquivo = LendoArquivo("vetores/50000-crescente.txt",&tamanho);
             mergeSort(VetorArquivo,vetor2,0,tamanho);
            printResultados();
            GravarArquivo(VetorArquivo, tamanho);
            ///------------------------------------------------------------------------
            printf("Ordenando vetor crescente com 100.000\n");
            VetorArquivo = LendoArquivo("vetores/100000-crescente.txt",&tamanho);
             mergeSort(VetorArquivo,vetor2,0,tamanho);
            printResultados();
            GravarArquivo(VetorArquivo, tamanho);
            fclose(gnuplot);
            ///-----------------------------------------------------------------------
            printf("|================================================================|\n");

            gnuplot = fopen("relatorios/merge-sort-inv.dat", "w");
            printf("Ordenando vetor decrescente com 100\n");
            fprintf(gnuplot, "#ORDENANDO INVERSO\n#Tamanho\t Tempo\t\t Comparacao\t trocas\n");
            VetorArquivo = LendoArquivo("vetores/100-decrescente.txt",&tamanho);
             mergeSort(VetorArquivo,vetor2,0,tamanho);
            printResultados();
            GravarArquivo(VetorArquivo, tamanho);

            ///-----------------------------------------------------------------------
            printf("Ordenando vetor decrescente com 1.000\n");
            VetorArquivo = LendoArquivo("vetores/1000-decrescente.txt",&tamanho);
            mergeSort(VetorArquivo,vetor2,0,tamanho);
            printResultados();
            GravarArquivo(VetorArquivo, tamanho);
            ///------------------------------------------------------------------------
            printf("Ordenando vetor decrescente com 10.000\n");
            VetorArquivo = LendoArquivo("vetores/10000-decrescente.txt",&tamanho);
            mergeSort(VetorArquivo,vetor2,0,tamanho);
            printResultados();
            GravarArquivo(VetorArquivo, tamanho);
            ///------------------------------------------------------------------------
            printf("Ordenando vetor decrescente com 50.000\n");
            VetorArquivo = LendoArquivo("vetores/50000-decrescente.txt",&tamanho);
            mergeSort(VetorArquivo,vetor2,0,tamanho);
            printResultados();
            GravarArquivo(VetorArquivo, tamanho);
            ///------------------------------------------------------------------------
            printf("Ordenando vetor decrescente com 100.000\n");
            VetorArquivo = LendoArquivo("vetores/100000-decrescente.txt",&tamanho);
            mergeSort(VetorArquivo,vetor2,0,tamanho);
            printResultados();
            GravarArquivo(VetorArquivo, tamanho);
            fclose(gnuplot);
            ///-----------------------------------------------------------------------

            system("gnuplot -bg gray90 script_gnuplot/plota5.gnu");
            break;
        case 7:

            gnuplot = fopen("relatorios/shell-sort-rand.dat", "w");

            printf("Ordenando vetor random com 100 elementos\n");
            fprintf(gnuplot, "#RANDOMICOS\n#Tamanho\t Tempo\t\t Comparacao\t trocas\n");
            VetorArquivo = LendoArquivo("vetores/100-random.txt",&tamanho);
            shellSort(VetorArquivo,tamanho);
            GravarArquivo(VetorArquivo, tamanho);
            printResultados();
            ///-----------------------------------------------------------------------
            printf("Ordenando vetor random com 1.000 elementos\n");
            VetorArquivo = LendoArquivo("vetores/1000-random.txt",&tamanho);
            shellSort(VetorArquivo,tamanho);
            GravarArquivo(VetorArquivo, tamanho);
            printResultados();
            ///------------------------------------------------------------------------
            printf("Ordenando vetor random com 10.000 elementos\n");
            VetorArquivo = LendoArquivo("vetores/10000-random.txt",&tamanho);
            shellSort(VetorArquivo,tamanho);
            GravarArquivo(VetorArquivo, tamanho);
            printResultados();
            ///------------------------------------------------------------------------
            printf("Ordenando vetor random de 50.000 elementos\n");
            VetorArquivo = LendoArquivo("vetores/50000-random.txt",&tamanho);
            shellSort(VetorArquivo,tamanho);
            GravarArquivo(VetorArquivo, tamanho);
            printResultados();
            ///------------------------------------------------------------------------
            printf("Ordenando vetor random de 100.000 elementos \n");
            VetorArquivo = LendoArquivo("vetores/100000-random.txt",&tamanho);
            shellSort(VetorArquivo,tamanho);
            GravarArquivo(VetorArquivo, tamanho);
            printResultados();
            fclose(gnuplot);
            ///-----------------------------------------------------------------------
            printf("|================================================================|\n");

            gnuplot = fopen("relatorios/shell-sort-ord.dat", "w");
            printf("Ordenando vetor crescente com 100\n");
            fprintf(gnuplot, "#ORDENANDOS\n#Tamanho\t Tempo\t\t Comparacao\t trocas\n");
            VetorArquivo = LendoArquivo("vetores/100-crescente.txt",&tamanho);
            shellSort(VetorArquivo,tamanho);
            GravarArquivo(VetorArquivo, tamanho);
            printResultados();
            ///-----------------------------------------------------------------------
            printf("Ordenando vetor crescente com 1.000\n");
            VetorArquivo = LendoArquivo("vetores/1000-crescente.txt",&tamanho);
            shellSort(VetorArquivo,tamanho);
            GravarArquivo(VetorArquivo, tamanho);
            printResultados();
            ///------------------------------------------------------------------------
            printf("Ordenando vetor crescente com 10.000\n");
            VetorArquivo = LendoArquivo("vetores/10000-crescente.txt",&tamanho);
            shellSort(VetorArquivo,tamanho);
            GravarArquivo(VetorArquivo, tamanho);
            printResultados();
            ///------------------------------------------------------------------------
            printf("Ordenando vetor crescente com 50.000\n");
            VetorArquivo = LendoArquivo("vetores/50000-crescente.txt",&tamanho);
            shellSort(VetorArquivo,tamanho);
            GravarArquivo(VetorArquivo, tamanho);
            printResultados();
            ///------------------------------------------------------------------------
            printf("Ordenando vetor crescente com 100.000\n");
            VetorArquivo = LendoArquivo("vetores/100000-crescente.txt",&tamanho);
            shellSort(VetorArquivo,tamanho);
            GravarArquivo(VetorArquivo, tamanho);
            printResultados();
            fclose(gnuplot);
            ///-----------------------------------------------------------------------
             printf("|================================================================|\n");

             gnuplot = fopen("relatorios/shell-sort-inv.dat", "w");
            printf("Ordenando vetor decrescente com 100\n");
            fprintf(gnuplot, "#ORDENANDO INVERSO\n#Tamanho\t Tempo\t\t Comparacao\t trocas\n");
            VetorArquivo = LendoArquivo("vetores/100-decrescente.txt",&tamanho);
            shellSort(VetorArquivo,tamanho);
            GravarArquivo(VetorArquivo, tamanho);
            printResultados();
            ///-----------------------------------------------------------------------
            printf("Ordenando vetor decrescente com 1.000\n");
            VetorArquivo = LendoArquivo("vetores/1000-decrescente.txt",&tamanho);
            shellSort(VetorArquivo,tamanho);
            GravarArquivo(VetorArquivo, tamanho);
            printResultados();
            ///------------------------------------------------------------------------
            printf("Ordenando vetor decrescente com 10.000\n");
            VetorArquivo = LendoArquivo("vetores/10000-decrescente.txt",&tamanho);
            shellSort(VetorArquivo,tamanho);
            GravarArquivo(VetorArquivo, tamanho);
            printResultados();
            ///------------------------------------------------------------------------
            printf("Ordenando vetor decrescente com 50.000\n");
            VetorArquivo = LendoArquivo("vetores/50000-decrescente.txt",&tamanho);
            shellSort(VetorArquivo,tamanho);
            GravarArquivo(VetorArquivo, tamanho);
            printResultados();
            ///------------------------------------------------------------------------
            printf("Ordenando vetor decrescente com 100.000\n");
            VetorArquivo = LendoArquivo("vetores/100000-decrescente.txt",&tamanho);
            shellSort(VetorArquivo,tamanho);
            GravarArquivo(VetorArquivo, tamanho);
            printResultados();
            fclose(gnuplot);
            ///-----------------------------------------------------------------------

            system("gnuplot -bg gray90 script_gnuplot/plota6.gnu");
            break;
        case 8:
            system("rm vetores/*.txt");
            printf("arquivos .txt removidos");
        case 0:

            break;
        }
    }
    while(op!=0);
     system("gnuplot -bg gray90 script_gnuplot/plota7.gnu");
    return 1;
}



#endif // ORDENA_H_INCLUDED
