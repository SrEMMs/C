#include <stdio.h>
#include <stdlib.h>
int main()
{
  FILE *arq;
  double Vet[3];
  int result;
  int i;
  // Abre um arquivo BINÁRIO para LEITURA
  arq = fopen("ArqTeste1.txt", "rb");
  if (arq == NULL)  // Se houve erro na abertura
  {
 	printf("Problemas na abertura do arquivo\n");
 	system("pause");
 	return 0;
  }
  result = fread (&Vet[0], sizeof(double), 3, arq);
  printf("Nro de elementos lidos: %d\n", result);

  for (i=0; i<3; i++)
  	printf("%lf\n", Vet[i]);
 
  system("pause");
  fclose(arq);
    
}
