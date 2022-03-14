#include<stdio.h>
#define QTDE 12

int main(){
    char palavra[QTDE] = "SISTEMASINF";
    char min, aux;

    for (int i = 0; i < QTDE - 1; i++){
        min = i;
        for(int j = i+1; j < QTDE; j++){
            if (palavra[j] < palavra[min]){
                min = j;
            }
        }
        aux = palavra[min];
        palavra[min] = palavra[i];
        palavra[i] = aux;
    }
    for (int i = 0; i < QTDE; i++){
        printf("%c ", palavra[i]);
    }
    return 0;
}
