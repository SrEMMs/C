#include<stdio.h>
#include<time.h>
#define MAX 12

int main(){
    int vet[MAX] = {17, 42, 9, 33, 12, 54, 65, 23, 54, 76, 1, 22};
    int aux, i;
    time_t INICIO, FIM;

    INICIO = time(NULL);
    for(int j = 1; j < MAX; j++){
        aux = vet[j];
        i = j - 1;
        while ((i >= 0) && (vet[i]>aux)){
            vet[i+1] = vet[i];
            i--;
        }
        vet[i+1] = aux;
    }
    for (int j = 0; j < MAX; j++){
        printf("%d ", vet[j]);
    
    }
    FIM = time(NULL);
    printf("\nDemorou %2.f segundos.", difftime(INICIO, FIM) * (-1));
    return 0;
}
