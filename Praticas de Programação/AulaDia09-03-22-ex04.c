#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void esperar(int segundos);

int main(void){
    int x;

    printf("Eu sei contar!!! Veja:\n");
    for (x=1; x <= 8; x++){
        printf("%d\n",x);
        esperar(5); /*Espera 1 segundo ate ir o proximo numero*/
    }
    return 0;
}

void esperar(int segundos){
    clock_t cicloFinal;
    cicloFinal = clock() + segundos * CLOCKS_PER_SEC;
    while (clock() < cicloFinal);    
}