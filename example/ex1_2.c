#include<stdlib.h>
#include<stdio.h>

extern int errno;

int main(void){
    FILE *fp;

    if((fp = fopen("unix.txt", "r")) == NULL){
        printf("errno = %d", errno);
    }
    fclose(fp);

    return 0;
}