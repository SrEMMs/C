#include<stdio.h>
#include<stdlib.h>
#define QTDE 6

main(){
    int numbers[QTDE] = {58, 12, 75, 18, 20, 40};
    int temp;
    for (int i = 0; i < QTDE; i++){
        for (int j = 0; j < QTDE-1; j++){
            if(numbers[j] > numbers[j+1]){
                temp = numbers[j];
                numbers[j] = numbers[j+1];
                numbers[j+1] = temp;
            }
            for (int i = 0; i < QTDE; i++){
            printf("%d ", numbers[i]);
            }
            printf("\n");
        }
    }
}