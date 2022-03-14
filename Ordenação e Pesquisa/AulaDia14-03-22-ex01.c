#include<stdio.h>
#define QTDE 6

int main(){
    int vector[QTDE] = {12, 6, 8, 10, 9, 11};
    int min, aux;

    for (int i = 0; i < QTDE; i++){
        min = i;
        for(int j = i+1; j < QTDE; j++){
            if (vector[j] < vector[min]){
                min = j;
            }
        }
        aux = vector[min];
        vector[min] = vector[i];
        vector[i] = aux;
    }
    for (int i = 0; i < QTDE; i++){
        printf("%d ", vector[i]);
    }
    return 0;
}
