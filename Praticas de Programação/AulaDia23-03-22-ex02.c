#include<stdio.h>
#include<stdlib.h>

void selecao(int *p, int tamanho){
	int a,b,c;
	int troca;
	int t;
	for(a = 0;a<tamanho-1;++a){
		troca = 0;
		c = a;
		t = p[a];
		for(b = a+1;b<tamanho;++b){
			if(p[b]<t){
				c = b;
				t = p[b];
				troca = 1;
			}
		}
		if(troca){
			p[c] = p[a];
			p[a] = t;
		}
	}
}

int main(){
	int vetor[12] = {17, 42, 9, 33, 12, 54, 65, 23, 54, 76, 1, 22};
	int *v = vetor;
	
    selecao(v,12);

	for(int i = 0;i<12;i++){
		printf("%d ",v[i]);
	}
	system("pause");
	return 0;
}