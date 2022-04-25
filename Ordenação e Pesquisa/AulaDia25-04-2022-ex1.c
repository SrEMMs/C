#include<stdio.h>
#define MAX 10

void quick (int vetor[MAX], int inicio, int fim){
    int pivo, aux, i, j, meio;

    //inicio do processo de particao
    i = inicio;
    j = fim;
    meio = (i+j) / 2;
    pivo = vetor[meio];

    printf("%d\n", pivo);
    
    do{
        while (vetor[i] < pivo)
            i = i + 1;
        while (vetor[j] > pivo)
            j = j - 1;
        if (i <= j){
            aux = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = aux;
            i = i + 1;
            j = j - 1;
        }
    } while (j > i);
    //fim do processo de particao

    if(inicio < j){
        quick(vetor, inicio, j);
    }
    if(i < fim){
        quick(vetor, i, fim);
    }
} 


main(){
    int vetor[MAX] = {50, 100, 12, 42, 18, 23, 5, 51, 13, 16};

    quick(vetor, 0 , MAX-1);
    for (int i = 0; i < MAX; i++){
        printf("%d ", vetor[i]);
    }
    printf("\n");
    
}