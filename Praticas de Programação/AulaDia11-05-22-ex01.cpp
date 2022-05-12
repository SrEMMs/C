#include <stdio.h>
# include <time.h>
#include <stdlib.h>
#define TAM_VET 510000

void qsort(int*,int , int);      /* funcao para ordenacao */
void criavetor(int *,int , int); /* funcao auxiliar para gerar o vetor aleatorio */


int main(){
   int vetor[TAM_VET];
   int i;
   criavetor(vetor,TAM_VET,TAM_VET);
   printf("Estado Inicial:\n");
   for(i=0;i<TAM_VET;i++)
   {
      printf("%d ",vetor[i]);  
   }
   printf("\n");
   qsort(vetor,0,TAM_VET-1);
   printf("\nOrdenado:\n");
   for(i=0;i<TAM_VET;i++)
   {
      printf("%d ",vetor[i]);  
   }
   getchar();
   return 0;
}
 
void qsort(int *vet, int inicio, int fim){
   /* inicia os indices */
	int i = inicio;
	int j = fim;
	int tmp;
	/* verifica se ainda é necessário a ordenacao (> 2 elementos)  */
	if (i >= j)
   {
	    return;
	}
	/*  considera o elemento central como pivo*/
	int pivo = vet[(int)(inicio+fim)/2];
	/* 'corre' todo o vetor até que os indices se encontrem */
	while (i < j) 
   {
	    while (i<j && vet[i] < pivo) { i++; }/* 'procura' por um elemento menor ou igual ao pivo*/
	    while (i<j && vet[j] > pivo) { j--; }/* 'procura' por um elemento maior ou igual ao pivo*/
      /* troca os elementos encontrados se os indices nao tivem se cruzado*/
	    if (i < j)                           
       {
		    tmp= vet[i];
		    vet[i] = vet[j];
		    vet[j] = tmp;
		    i++;
		    j--;
	    }
	}
	/* se os indices se cruzaram, reorganiza os indices*/
	if (j < i)
   {
	    tmp = j;
	    j = i;
	    i = tmp;
	}
	/* ordernar o subvetor da esquerda */
	qsort(vet, inicio, i);
	/* se o pivo escolhido era o primeiro elemento, ordena os demais à direita*/
	if(i == inicio)
	{
      qsort(vet,i+1,fim);
   }
   else
   {
    /* ordena o subvetor a direita*/
     qsort(vet,i,fim);
   }
}


void criavetor(int *vet,int tam,int max)
{
	time_t t; 
	int i;
	srand(time(&t));
	for(i = 0;i < tam;i++)
   {
		vet[i]  = rand() % (max+1);
	}
}
