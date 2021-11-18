#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

// Struct gerenciadora do vetor
typedef struct{
    int *array;
    size_t usados;
    size_t tamanho;
}Array;
Array amostras;

// Variáveis de desempenho
struct timeval inicio, fim;
unsigned long long int trocas;
unsigned long long int voltas_i, voltas_j;
unsigned long long int comparacoes;

// Declaração de funções
int  CarregarArquivos(const char *caminho);
void BubbleSort(int *vetor, size_t tamanho);
void InsertionSort(int *vetor, size_t tamanho);
void SelectionSort(int *vetor, size_t tamanho);
void QuickSort(int *vetor,int inicio_vetor, int fim_vetor);
void Estatisticas(unsigned long long int trocas, unsigned long long int voltas_i,
                  unsigned long long int voltas_j, unsigned long long int comparacoes,
                  struct timeval inicio, struct timeval fim);
void Troca(int *x, int *y);
void IniciarArray(Array *a, size_t tamanho);
void InserirArray(Array *a, int elemento);
void LiberarArray(Array *a);
void SalvarDados(int *vetor, int tamanho, const char* metodo);
void Menu();




int main()
{
    setlocale(LC_ALL,"Portuguese");

    // Inicia o vetor
    IniciarArray(&amostras, 1);

    char escolha[1], escolha_vetor[1], tipo[1];

    while(1){
        Menu();
        scanf("%s",escolha);
        system("cls");
        switch (atoi(escolha)) {
            case 1:
                printf("Qual o tamanho do vetor?");
                printf("\n1 - 1K");
                printf("\n2 - 5K");
                printf("\n3 - 10K");
                printf("\n4 - 50K");
                printf("\n5 - 100K");
                printf("\n> ");
                scanf("%s", escolha_vetor);
                system("cls");
                switch (atoi(escolha_vetor)) {
                    // Carregar arquivos
                    case 1:
                        printf("\nTipo vetor: ");
                        printf("\n1 - Aleatório");
                        printf("\n2 - Ordem Crescente");
                        printf("\n3 - Ordem Decrescente");
                        printf("\n> ");
                        scanf("%s", tipo);
                        system("cls");
                        if(atoi(tipo) == 1){
                            CarregarArquivos("amostras\\Aleatorio\\1K.txt");
                        }else if(atoi(tipo) == 2){
                            CarregarArquivos("amostras\\Crescente\\1K.txt");
                        }else if(atoi(tipo) == 3){
                            CarregarArquivos("amostras\\Decrescente\\1K.txt");
                        }
                        printf("\nVetor de 1000 posições carregado!");
                        break;
                    case 2:
                        printf("\n\nTipo vetor: ");
                        printf("\n1 - Aleatório");
                        printf("\n2 - Ordem Crescente");
                        printf("\n3 - Ordem Decrescente");
                        printf("\n> ");
                        scanf("%s", tipo);
                        if(atoi(tipo) == 1){
                            CarregarArquivos("amostras\\Aleatorio\\5K.txt");
                        }else if(atoi(tipo) == 2){
                            CarregarArquivos("amostras\\Crescente\\5K.txt");
                        }else if(atoi(tipo) == 3){
                            CarregarArquivos("amostras\\Decrescente\\5K.txt");
                        }
                        printf("\nVetor de 5.000 posições carregado!");
                        break;
                    case 3:
                        printf("\n\nTipo vetor: ");
                        printf("\n1 - Aleatório");
                        printf("\n2 - Ordem Crescente");
                        printf("\n3 - Ordem Decrescente");
                        printf("\n> ");
                        scanf("%s", tipo);
                        if(atoi(tipo) == 1){
                            CarregarArquivos("amostras\\Aleatorio\\10K.txt");
                        }else if(atoi(tipo) == 2){
                            CarregarArquivos("amostras\\Crescente\\10K.txt");
                        }else if(atoi(tipo) == 3){
                            CarregarArquivos("amostras\\Decrescente\\10K.txt");
                        }
                        printf("\nVetor de 10.000 posições carregado!");
                        break;
                    case 4:
                        printf("\n\nTipo vetor: ");
                        printf("\n1 - Aleatório");
                        printf("\n2 - Ordem Crescente");
                        printf("\n3 - Ordem Decrescente");
                        printf("\n> ");
                        scanf("%s", tipo);
                        if(atoi(tipo) == 1){
                            CarregarArquivos("amostras\\Aleatorio\\50K.txt");
                        }else if(atoi(tipo) == 2){
                            CarregarArquivos("amostras\\Crescente\\50K.txt");
                        }else if(atoi(tipo) == 3){
                            CarregarArquivos("amostras\\Decrescente\\50K.txt");
                        }
                        printf("\nVetor de 50.000 posições carregado!");
                        break;
                    case 5:
                        printf("\n\nTipo vetor: ");
                        printf("\n1 - Aleatório");
                        printf("\n2 - Ordem Crescente");
                        printf("\n3 - Ordem Decrescente");
                        printf("\n> ");
                        scanf("%s", tipo);
                        if(atoi(tipo) == 1){
                            CarregarArquivos("amostras\\Aleatorio\\100K.txt");
                        }else if(atoi(tipo) == 2){
                            CarregarArquivos("amostras\\Crescente\\100K.txt");
                        }else if(atoi(tipo) == 3){
                            CarregarArquivos("amostras\\Decrescente\\100K.txt");
                        }
                        printf("\nVetor de 100.000 posições carregado!");
                        break;
                    default:
                        printf("\nEntrada inválida!");
                }
                break;
                //Exibir vetor
            case 2:
                printf("\nTamanho do vetor: %d\n", amostras.usados);
                for(int i = 0; i < amostras.usados; i++){
                    printf("[%d]: %d\t",i,amostras.array[i]);
                }
                break;
                // Ordenar vetor
            case 3:
                printf("\nSelecione o tipo de ordenação pretendido");
                printf("\n1 - Bubblesort");
                printf("\n2 - Insertionsort");
                printf("\n3 - Selectionsort");
                printf("\n4 - Quicksort");
                printf("\n0 - Sair");
                printf("\n>");
                scanf("%s", &escolha_vetor);
                switch(atoi(escolha_vetor)){
                    case 1:
                        BubbleSort(amostras.array,amostras.usados);
                        SalvarDados(amostras.array, amostras.usados,"dados_ordenados_bubblesort.txt");
                        //LiberarArray(&amostras);
                        break;
                    case 2:
                        InsertionSort(amostras.array,amostras.usados);
                        SalvarDados(amostras.array, amostras.usados,"dados_ordenados_insertionSort.txt");
                        //LiberarArray(&amostras);
                        break;
                    case 3:
                        SelectionSort(amostras.array,amostras.usados);
                        SalvarDados(amostras.array, amostras.usados,"dados_ordenados_selectionSort.txt");
                        LiberarArray(&amostras);
                        break;
                    case 4:
                        voltas_i = 0;
                        voltas_j = 0;
                        comparacoes = 0;
                        trocas = 0;
                        gettimeofday(&inicio,NULL);
                        QuickSort(amostras.array,0,amostras.usados-1);
                        gettimeofday(&fim,NULL);
                        Estatisticas(trocas, voltas_i, voltas_j ,comparacoes,inicio,fim);
                        SalvarDados(amostras.array, amostras.usados,"dados_ordenados_quicksort.txt");
                        //LiberarArray(&amostras);
                        break;
                    case 0:
                        return 0;
                        break;
                    default:
                        printf("\nOpção inválida!");
                    }
                break;
            case 4:
                LiberarArray(&amostras);
                IniciarArray(&amostras, 1);
                break;
            case 0:
                puts("Bye");
                return 0;
            default:
                puts("\nOpção invalida, tente novamente");
        }
    }

    return 0;
}

int CarregarArquivos(const char* caminho)
{
    int aux;
    FILE *arquivo;
    int i = 0;
    if(arquivo = fopen(caminho,"r")){
        puts("Carregando.......");
        while(fscanf(arquivo,"%d",&aux) != EOF){
            if(aux != 0){
                InserirArray(&amostras, aux);
                i++;
            }
        }
        fclose(arquivo);
        return 1;
    }else{
        printf("O arquivo %s não existe ou não pode ser encontrado no diretório da aplicação!", caminho);
        getchar();
        return 0;
    }
}

void BubbleSort(int *vetor, size_t tamanho)
{
    voltas_i = 0;
    voltas_j = 0;
    comparacoes = 0;
    trocas = 0;

    gettimeofday(&inicio,NULL);
    for(int i = 0; i < tamanho; i++, voltas_i++){
        for(int j = i + 1; j < tamanho; j++, comparacoes++, voltas_j++){
            if(vetor[i] > vetor[j]){
                Troca(&vetor[i], &vetor[j]);
                trocas++;
            }
        }
    }
    gettimeofday(&fim,NULL);
    Estatisticas(trocas, voltas_i, voltas_j ,comparacoes,inicio,fim);
}

void InsertionSort(int *vetor, size_t tamanho)
{
    voltas_i = 0;
    voltas_j = 0;
    comparacoes = 0;
    trocas = 0;

    gettimeofday(&inicio,NULL);
    int i, j, tmp;

    for(i = 1; i < tamanho; i++,comparacoes++, voltas_i++)
    {
        tmp = vetor[i];
        for(j = i-1; j >= 0 && tmp < vetor[j]; j--, voltas_j++)
        {
            trocas++;
            vetor[j+1] = vetor[j];
        }
        vetor[j+1] = tmp;
    }
    gettimeofday(&fim,NULL);
    Estatisticas(trocas, voltas_i, voltas_j ,comparacoes,inicio,fim);
}

void SelectionSort(int *vetor, size_t tamanho) {
    voltas_i = 0;
    voltas_j = 0;
    comparacoes = 0;
    trocas = 0;

    gettimeofday(&inicio,NULL);
    int i, j, k, tmp, tr;

    for(i = 0; i < tamanho-1; i++, comparacoes++, voltas_i++)
    {
        tr = 0;
        k = i;
        tmp = vetor[i];
        for(j = i+1; j < tamanho; j++, comparacoes++, voltas_j++)
        {
            if(vetor[j] < tmp)
            {
                k = j;
                tmp = vetor[j];
                tr = 1;
            }
        }
        if(tr)
        {
            vetor[k] = vetor[i];
            vetor[i] = tmp;
            trocas++;
        }
    }

    gettimeofday(&fim,NULL);
    Estatisticas(trocas, voltas_i, voltas_j ,comparacoes,inicio,fim);
}

void QuickSort(int* vetor,int inicio_vetor, int fim_vetor)
{
    int i = 0, j = 0, x = 0, y = 0;
    i = inicio_vetor;
    j = fim_vetor;
    x = vetor[(inicio_vetor + fim_vetor) / 2];

    while(i <= j) {
        while(vetor[i] < x && i < fim_vetor) {
            comparacoes++;
            voltas_i++;
            i++;
        }
        while(vetor[j] > x && j > inicio_vetor) {
            comparacoes++;
            voltas_j++;
            j--;
        }
        if(i <= j) {
            y = vetor[i];
            Troca(&vetor[i],&vetor[j]);
            vetor[j] = y;
            i++;
            j--;
        }
    }

    if(j > inicio_vetor) {
        QuickSort(vetor, inicio_vetor, j);
    }
    if(i < fim_vetor) {
        QuickSort(vetor, i, fim_vetor);
    }
}


void Estatisticas(unsigned long long int trocas, unsigned long long int voltas_i,
                  unsigned long long int voltas_j, unsigned long long int comparacoes,
                  struct timeval inicio, struct timeval fim){
    printf("\nTamanho do vetor: %d", amostras.usados);
    printf ("\nTempo decorrido:  %2.3fms",
            (double) (fim.tv_usec - inicio.tv_usec) / 1000000 +
            (double) (fim.tv_sec - inicio.tv_sec));
    printf("\nNumero de trocas: %i",trocas);
    printf("\nNumero de comparacoes: %i",comparacoes);
    printf("\nNumero de voltas do primeiro laco: %i",voltas_i);
    printf("\nNumero de voltas do segundo laco: %i",voltas_j);
}

void Troca(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
    trocas++;
}

void IniciarArray(Array *a, size_t tamanho){
    a->array = malloc(tamanho * sizeof(int));
    a->usados = 0;
    a->tamanho = tamanho;
}

void InserirArray(Array *a, int elemento){
    if(a->usados == a->tamanho){
        a->tamanho *= 2;
        a->array = realloc(a->array, a->tamanho * sizeof(int));
    }
    a->array[a->usados++] = elemento;
}

void LiberarArray(Array *a){
    free(a->array);
    a->array = NULL;
    a->usados = a->tamanho = 0;
}

void SalvarDados(int *vetor, int tamanho, const char* filename){
    FILE *file;
    file = fopen(filename,"w+");
    if(file == NULL){
        printf("Não foi possivel salvar o arquivo.");
    }
    fprintf(file,"Resultado de ordenação:");
    fprintf(file,"\nTamanho do vetor: %d", amostras.usados);
    fprintf (file,"\nTempo decorrido:  %2.3fms",
            (double) (fim.tv_usec - inicio.tv_usec) / 1000000 +
            (double) (fim.tv_sec - inicio.tv_sec));
    fprintf(file,"\nNumero de trocas: %i",trocas);
    fprintf(file,"\nNumero de comparacoes: %i",comparacoes);
    fprintf(file,"\nNumero de voltas do primeiro laco: %i",voltas_i);
    fprintf(file,"\nNumero de voltas do segundo laco: %i\n",voltas_j);

    for(int i = 0; i < tamanho; i++){
        fprintf(file,"%d\n",vetor[i]);
    }

    printf("\nArquivo salvo no diretório da aplicação");
    fclose(file);
}

void Menu(){
    printf("\n\n1 - Carregar arquivo de dados");
    printf("\n2 - Exibir dados carregados");
    printf("\n3 - Ordenar dados");
    printf("\n4 - Limpar vetor");
    printf("\n0 - Sair\n");
    printf("> ");
}
