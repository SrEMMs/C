#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    const time_t timer = time(NULL);
    printf("ctime, agora sao: %s\n", ctime(&timer));
    system("pause");
    return 0;
}