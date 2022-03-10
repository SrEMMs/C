#include<stdio.h>
#include<stdlib.h>
#define QTDE 9

main(){
    char name[QTDE] = "PASARGADA";
    char temp;

    for (int i = 0; i < QTDE; i++){
        for (int j = 0; j < QTDE-1; j++){
            if(name[j] > name[j+1]){
                temp = name[j];
                name[j] = name[j+1];
                name[j+1] = temp;
            }
            for (int i = 0; i < QTDE; i++){
            printf("%c ", name[i]);
            }
            printf("\n");
        }
    }
}