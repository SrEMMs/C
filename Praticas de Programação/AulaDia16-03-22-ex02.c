#include <stdio.h>
#include <time.h>
#include <string.h>
#include<stdlib.h>

int main(void){
  time_t inicio, fim;
  char nome[51];
  inicio= time(NULL);
  printf("Digite seu nome: ");
  fgets(nome, 51, stdin);
  fim= time(NULL);
  printf("\n%s Voce demorou %.2f segundos para digitar seu nome.\n", nome, difftime(inicio,fim) * (-1));
  system("pause");
  return 0;
}