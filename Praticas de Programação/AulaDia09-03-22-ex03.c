#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    time_t currentTime;
    struct tm * timeinfo;
    int dia, mes, ano;
    char *diaSemana [] = {"Domingo", "Segunda", "Terca", "Quarta", "Quinta", "Sexta", "Sabado"};

    /*Le uma data para verificar o dia da semana correspondente a ela.*/
    printf("Dia ");
    scanf("%d", &dia);
    printf("Mes ");
    scanf("%d", &mes);
    printf("Ano ");
    scanf("%d", &ano);

    /*Pega a hora atual do sistema e a converte em uma estrutura tm.*/
    time(&currentTime);
    timeinfo = localtime(&currentTime);

    /*Atualiza os valores dia, mes, ano da estrutura.*/
    timeinfo->tm_mday = dia;
    timeinfo->tm_mon = mes - 1;
    timeinfo->tm_year = ano - 1900;

    /*Atraves da funcao mktime(), atualiza os outros campos da estrutura de acordo com os atualizados anteriormente.*/
    mktime(timeinfo);

    /*Imprime o dia da semana.*/
    printf("%02d/%02d/%d foi %s.\n", dia, mes, ano, diaSemana[timeinfo->tm_wday]);

    system("pause");
    return 0;
}