#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    char url[]="notas1.txt";
    float nota;
    FILE *arq;
    arq = fopen(url, "w");
    if(arq == NULL)
   		 printf("Erro, nao foi possivel abrir o arquivo\n");
    else{
   	 printf("Nota de Matematica: ");
   	 scanf("%f", &nota);
   	 fprintf(arq, "Matematica: %.2f\n", nota);
   	 printf("Nota de Fisica: ");
   	 scanf("%f", &nota);
   	 fprintf(arq, "Fisica: %.2f\n", nota);
   	 printf("Nota de Quimica: ");
   	 scanf("%f", &nota);
   	 fprintf(arq, "Quimica: %.2f\n", nota);
    }
    fclose(arq);
    return 0;
}

