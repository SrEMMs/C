#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void selection_sort(int num[], int tam){
    int i, j, min, swap;
    for (i = 0; i < (tam-1); i++){
        min = i;
        for (j = (i+1); j < tam; j++){
            if(num[j] < num[min]){
                min = j;
            }
        }
        if(i != min){
            swap = num[i];
            num[i] = num[min];
            num[min] = swap;
        }
    }
    
}

int main(){
    int vetor[12] = {17, 42, 9, 33, 12, 54, 65, 23, 54, 76, 1, 22};
    time_t INICIO, FIM;

    INICIO = time(NULL);
    selection_sort(vetor,12);
    for (int i = 0; i < 12; i++){
        printf("%d ",vetor[i]);
    }
    FIM = time(NULL);
    printf("\nDemorou %2.f segundos.\n", difftime(INICIO, FIM) * (-1));
    system("pause");
    return 0;    
}