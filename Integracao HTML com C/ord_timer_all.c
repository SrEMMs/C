/*
Erick Magdaleno de Melo
Tulio Cesar Cerqueira Soares
Cataguases 3 Periodo
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX 77336

void bubble(int tamanho){
	int aux, vetor[tamanho];
	int *v = vetor;

	FILE *entrada;
	entrada = fopen( "numeros.txt", "r");
	if (entrada == NULL) {
  		printf( "\nNão encontrei arquivo\n");
  		exit( EXIT_FAILURE);
	}
	
	for (int i = 0; i < MAX; i++){
		fscanf(entrada, "%d", &vetor[i]);
	}

	for (int i = 0; i < MAX; i++){
		for(int j = 0; j < MAX-1; j++){
			if (v[j] > v[j + 1]) {
				aux = v[j];
				v[j] = v[j + 1];
				v[j + 1] = aux;
			}
		}
	}
}

void selection(int tamanho){
	int a,b,c;
	int troca;
	int t;
	int vetor[tamanho];
	int *v = vetor;

	FILE *entrada;
	entrada = fopen( "numeros.txt", "r");
	if (entrada == NULL) {
  		printf( "\nNão encontrei arquivo\n");
  		exit( EXIT_FAILURE);
	}
	
	for (int i = 0; i < MAX; i++){
		fscanf(entrada, "%d", &vetor[i]);
	}

	for(a = 0;a<tamanho-1;++a){
		troca = 0;
		c = a;
		t = v[a];
		for(b = a+1;b<tamanho;++b){
			if(v[b]<t){
				c = b;
				t = v[b];
				troca = 1;
			}
		}
		if(troca){
			v[c] = v[a];
			v[a] = t;
		}
	}
}

void inserction (int tamanho){
	int aux, i;
	int vetor[tamanho];
	int *v = vetor;

	FILE *entrada;
	entrada = fopen( "numeros.txt", "r");
	if (entrada == NULL) {
  		printf( "\nNão encontrei arquivo\n");
  		exit( EXIT_FAILURE);
	}
	
	for (int i = 0; i < MAX; i++){
		fscanf(entrada, "%d", &vetor[i]);
	}
	
    for (int j=1; j< tamanho; j++) {
        aux = v[j];
        i = j-1;
        while((i>=0) && (v[i]>aux)) {
            v[i+1] = v[i];
            i--;
        }
        v[i+1] = aux;
    }
}

void shell(int tamanho){
	int vetor[tamanho];
	int *v = vetor;
	int h=1, valor, j;

	FILE *entrada;
	entrada = fopen( "numeros.txt", "r");
	if (entrada == NULL) {
  		printf( "\nNão encontrei arquivo\n");
  		exit( EXIT_FAILURE);
	}
	
	for (int i = 0; i < MAX; i++){
		fscanf(entrada, "%d", &vetor[i]);
	}

    do{
        h = (3*h) + 1;
    } while (h < MAX);

    do{
        h /= 3;
        for(int i = 0; i < MAX; i++){
            valor = v[i];
            j = i - h;
            while ((j >= 0) && (valor < v[j])){
                v[j + h] = v[j];
                j -= h;
            }
            v[j+h] = valor;
        }
    } while (h > 1);
}

void quick(int vetor[MAX], int inicio, int fim) {
    int pivo, aux, i, j, meio;

    i = inicio;
    j = fim;
    meio = (i+j) / 2;
    pivo = vetor[meio];
    do {
        while(vetor[i] < pivo)
            i = i + 1;
        while(vetor[j] > pivo)
            j = j - 1;
        if (i <= j) {
            aux = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = aux;
            i = i + 1;
            j = j - 1;
        }
    }while(j > i);

    if(inicio < j) {
        quick(vetor, inicio, j);
    }
    if(i < fim) {
        quick(vetor, i, fim);
    }
}

void heap(int tamanho){
	int i, p, f, aux, n;
	int vetor[tamanho];
	int *v = vetor;

	FILE *entrada;
	entrada = fopen( "numeros.txt", "r");
	if (entrada == NULL) {
  		printf( "\nNão encontrei arquivo\n");
  		exit( EXIT_FAILURE);
	}
	
	for (int i = 0; i < MAX; i++){
		fscanf(entrada, "%d", &vetor[i]);
	}

    i = MAX/2;
    n = MAX;
    while(1) {
        if (i > 0) {
            i--;
            aux = v[i];
        } else {
            n--;
            if (n == 0)
                break;
            aux = v[n];
            v[n] = v[0];
        }
        p = i;
        f = (i*2) + 1;
        while (f < n) {
            if ((f + 1 < n) && (v[f + 1] > v[f]))
                f++;
            if (v[f] > aux) {
                v[p] = v[f];
                p = f;
                f = (p*2) + 1;
            } else
                break;
        }
        v[p] = aux;
    }
}

int main(){

	int array[MAX];
	int *a = array;

	FILE *entrada;
	entrada = fopen( "numeros.txt", "r");
	if (entrada == NULL) {
  		printf( "\nNão encontrei arquivo\n");
  		exit( EXIT_FAILURE);
	}
	
	for (int i = 0; i < MAX; i++){
		fscanf(entrada, "%d", &array[i]);
	}

	clock_t t, t1, t2, t3, t4, t5;

	t = clock();
	bubble(MAX);
	t = clock() - t;

	t1 = clock();
	selection(MAX);
	t1 = clock() - t1;

	t2 = clock();
	inserction(MAX);
	t2 = clock() - t2;
	
	t3 = clock();
	shell(MAX);
	t3 = clock() - t3;
	
	t4 = clock();
	quick(a, 0, MAX-1);
	t4 = clock() - t4;
	
	t5 = clock();
	heap(MAX);
	t5 = clock() - t5;

	fclose(entrada);

	printf("Bubble time(ms) = %.2lf", ((double)t)/(CLOCKS_PER_SEC/1000));
	printf("\nSelection time(ms) = %.2lf", ((double)t1)/(CLOCKS_PER_SEC/1000));
	printf("\nInserction time(ms) = %.2lf", ((double)t2)/(CLOCKS_PER_SEC/1000));
	printf("\nShell time(ms) = %.2lf", ((double)t3)/(CLOCKS_PER_SEC/1000));
	printf("\nQsort time(ms) = %.2lf", ((double)t4)/(CLOCKS_PER_SEC/1000));
	printf("\nHeap time(ms) = %.2lf", ((double)t5)/(CLOCKS_PER_SEC/1000));

	FILE *html;
	html = fopen( "index.html", "w");
	if (html == NULL) {
  		printf( "\nNão encontrei arquivo\n");
  		exit( EXIT_FAILURE);
	}

	fprintf(html, "<!DOCTYPE html><html><head><title>Tabela de Ordenação</title></head><body>");
    fprintf(html, "<table border='1'><thead style='background-color: #ff0'><tr><th>Metodo</th><th>Tempo(ms)</th></thead><tbody>");
	fprintf(html, "<tr><td>Bubble</td><td>%d</td>", t);
	fprintf(html, "<tr><td>Selection</td><td>%d</td>", t1);
	fprintf(html, "<tr><td>Insertion</td><td>%d</td>", t2);
	fprintf(html, "<tr><td>Shell</td><td>%d</td>", t3);
	fprintf(html, "<tr><td>Qsort</td><td>%d</td>", t4);
	fprintf(html, "<tr><td>Heap</td><td>%d</td>", t5);
	fprintf(html, "</tbody></table></body></html>");
}