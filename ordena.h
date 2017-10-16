#ifndef ORDENA_H_INCLUDED
#define ORDENA_H_INCLUDED
#define MAX_STR 100
#include <time.h>

clock_t tempoInicio, tempoFim;
FILE *gnuplot;
unsigned long  troca=0,comparacao=0;


///---------------------------------------------------------------------------------------
void createFiles(long int n)
{
  long int i;
  srand(time(NULL));   
  char filename[MAX_STR];
  snprintf(filename, MAX_STR, "vetores/%ld", n);
  strcat(filename,"-crescente.txt");

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


  snprintf(filename, MAX_STR, "vetores/%ld",n);
  strcat(filename,"-random.txt");

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
///---------------------------------------------------------------------------------------
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

///----------------------------------------------------------------------------------------
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
    while (fgets(linha,200,arquivo))
    {
        LinhasdoArquivo++;
    }
    fclose(arquivo);
    *tamanho = LinhasdoArquivo;
    //escreve o arquivo o tamanho do vetor
    fprintf( gnuplot, "%d\t\t", LinhasdoArquivo);
    vetor = malloc(sizeof(int) * LinhasdoArquivo);

    arquivo = fopen(nomeArq,"r");
    i = 0;
    while (fgets(linha,200,arquivo))
    {
        //percorrer arquivo para gravar numeros no vetor
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
            {
                comparacao++;
                if(Vetor[k] > Vetor[k + i])
                {
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
        {
            comparacao++;
            if (vetor[j] < vetor[posMenor]) posMenor = j;
        }

        if (posMenor != i)
        {
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
    {
        aux = vetor[i];
        for (j = i - 1; j >= 0 && aux < vetor[j]; --j, comparacao++)
        {
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
        while(vetor[i] < pivo && i < dir) {
            i++;
            comparacao++;
        }
        while(vetor[j] > pivo && j > esq) {
            j--;
            comparacao++;
        }
        if(i <= j) {
            aux = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = aux;
            i++;
            j--;
             troca++;
        }
    }
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

    sprintf(Nome_arquivo, "vetores/%ld-Ordenado.txt", tamanho-1);

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

    //printa no console informações
     //printf("comparacao: %ld\n Trocas %ld\n",comparacao,troca);
     //printf("Tempo: %f\n", (float)(tempoFim - tempoInicio)/CLOCKS_PER_SEC);
}





#endif // ORDENA_H_INCLUDED
