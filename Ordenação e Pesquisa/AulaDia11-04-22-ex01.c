#include<stdio.h>
#include<stdlib.h>
#define MAX 17

int main(){
    int num[MAX] = {48, 70, 90, 110, 28, 13, 14, 1, 66, 200, 43, 42, 15, 18, 17, 62, 55};
    int h=1, valor, j;

    do{
        h = (3*h) + 1;
    } while (h < MAX);

    do{
        h /= 3;
        for(int i = 0; i < MAX; i++){
            valor = num[i];
            j = i - h;
            while ((j >= 0) && (valor < num[j])){
                num[j + h] = num[j];
                j -= h;
            }
            num[j+h] = valor;
        }
    } while (h > 1);

    for (int i = 0; i < MAX; i++){
        printf("%d ", num[i]);
    }
    printf("\n");
}
