#include <stdio.h>
#include <time.h>
#define BRAZIL (-3)
#define CHINA (+8)
#include<stdlib.h>

int main(void){
  time_t currentTime;
  struct tm *utcTime;
   currentTime= time(NULL);
   /* Converte a hora atual para UTC. o ano só é representado por dois caracteres e só temos precisão de minutos.*/
   /*Gmtime é responsável por converter*/
   utcTime= gmtime(&currentTime);
   /* Imprime os fuso-horarios do Brasil e China. */
printf("Brazil: %02d:%02d:%02d\n",(utcTime->tm_hour+BRAZIL)%24*-3,utcTime->tm_min, utcTime->tm_sec);
printf("China: %02d:%02d:%02d\n", (utcTime->tm_hour+CHINA)%24,utcTime->tm_min, utcTime->tm_sec);
 system("pause");
  return 0;
}