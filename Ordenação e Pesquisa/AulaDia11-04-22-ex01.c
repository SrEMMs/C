#include<stdio.h>
#include<stdlib.h>
#define MAX 5

int main(){
    int num[MAX] = {5, 50, 20, 4, 3, 2};
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

    for (size_t i = 0; i < MAX; i++){
        printf("%d ", num[i]);
    }
    printf("\n");
}
