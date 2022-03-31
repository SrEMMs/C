//===========================================================
// Nome Do Arquivo: insertion.cpp
// 
// Includes: stdio.h
// 
// Descrição: Implementação do algoritmo de ordenação por 
//            inserção
//============================================================
#define MAX 5
#include <stdio.h>
#include <stdlib.h> 
// Protótipo da função de ordenação
void insertion_sort(int *a);
// Função Principal
int main(int argc, char** argv)
{
 int i, vet[MAX];
 // Lê MAX valores
 for(i = 0; i < MAX; i++)
 {
  printf("Digite um valor: ");
  scanf("%d", &vet[i]);
 }
 // Ordena o vetor
 insertion_sort(vet);
 // Imprime os valores ordenados
 printf("\n\nValores ordenados\n");
 for(i = 0; i < MAX; i++)
 {
  printf("%d\n", vet[i]);
     system("pause"); 
 }
 return 0;
}
// Função de Ordenação por Inserção
void insertion_sort(int *a){
 int i, j, tmp;
 for(i = 1; i < MAX; i++)
 {
  tmp = a[i];
  for(j = i-1; j >= 0 && tmp < a[j]; j--)
  {
   a[j+1] = a[j];
  }
  a[j+1] = tmp;
 }
}