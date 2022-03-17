#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    char nome[50];
    int i=0;
    time_t inicio, fim;

    inicio = time(NULL);
    printf("Informe seu nome: ");
    fgets(nome, 50, stdin);

    for (int i = 0; i < 50; i++){
        printf("%s", nome);
    }
    fim = time(NULL);
    printf("Demorou %.2f segundos com FOR.\n", difftime(inicio,fim) * (-1));

    inicio = time(NULL);
    printf("Informe seu nome: ");
    fgets(nome, 50, stdin);
    while (i < 50){
        printf("%s", nome);
        i++;
    }
    fim = time(NULL);
    printf("Demorou %.2f segundos com WHILE.", difftime(inicio,fim) * (-1));
}