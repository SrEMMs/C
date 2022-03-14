#include<stdio.h>
#define QTDE 5

int main(){
    char palavra[QTDE][30];
    int min, aux;

    for (int i = 0; i < QTDE; i++){
        printf("Insira o %d nome: ", i+1);
        fflush(stdin);
        scanf("%s", &palavra[i]);
    }
    
    for (int i = 0; i < QTDE - 1; i++){
        min = i;
        for(int j = i+1; j < QTDE; j++){
            if (strcmp(palavra[j], palavra[min]) < 0){
                min = j;
            }
        }
        strcpy(aux, palavra[min]);
        strcpy(palavra[min], palavra[i]);
        strcpy(palavra[i], aux);
    }
    for (int i = 0; i < QTDE; i++){
        printf("%s\n", palavra[i]);
    }
    return 0;
}
