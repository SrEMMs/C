#include <stdio.h>
#include <stdlib.h>
#define TRUE 1

int main( void) {
   int x, n, k;
   double soma;
   FILE *entrada;
   entrada = fopen( "dados.txt", "rb");
   if (entrada == NULL) {
  	printf( "\nNão encontrei arquivo\n");
  	exit( EXIT_FAILURE);
   }
   soma = n = 0;
   while (TRUE) {
  	k = fscanf( entrada, "%d", &x);
  	//printf( "K vale: %d\n", k);
  	if (k != 1) break;
  	soma += x;
  	n += 1;
   }
   fclose( entrada);
   printf( "A media dos numeros e %f\n", soma/n);
   system("pause");
   return EXIT_SUCCESS;
}
