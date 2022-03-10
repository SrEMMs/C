#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(void){
    time_t segundos;

    segundos = time(NULL);
    printf("%ld horas desde 1 de Janeiro de 1970.\n", segundos/3600);
    system("pause");
    return 0;
}