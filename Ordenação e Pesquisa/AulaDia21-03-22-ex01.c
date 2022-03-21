#include<stdio.h>
#define QTDE 6

int main(){
    int vet[QTDE] = {40, 38, 50, 20, 11, 18};
    int aux, i;

    for(int j = 1; j < QTDE; j++){
        aux = vet[j];
        i = j - 1;
        while ((i >= 0) && (vet[i]>aux)){
            vet[i+1] = vet[i];
            i--;
        }
        vet[i+1] = aux;
    }
    for (int j = 0; j < QTDE; j++){
        printf("%d ", vet[j]);
    
    }
    
    return 0;
}
