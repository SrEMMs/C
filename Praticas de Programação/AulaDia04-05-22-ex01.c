#include <stdio.h>
#include <stdlib.h>

int main(){
	double Notas[3];
	FILE *arq;
	int result;
	int i;

	arq = fopen("ArqTeste1.txt", "w"); // Cria um arquivo binário para gravação

	if (arq == NULL) // Se não conseguiu criar
	{
    	printf("Problemas na CRIACAO do arquivo\n");
  	 return 0;
	}
	for (i=0; i<3; i++){
  	scanf("%lf\n", &Notas[i]);
  	}
	// Grava 3 números do vetor a partir da posição 0
	result = fwrite (&Notas[0], sizeof(double),3,arq);

	printf("Nro de elementos gravados: %d\n", result);
	system("pause");
	fclose(arq);

}
