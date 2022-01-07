#include<stdlib.h>
#include<stdio.h>
#include</usr/include/errno.h>

extern int errno;

int main(void){
    FILE *fp;

    if((fp = fopen("unix.txt", "r")) == NULL){
        printf("errno = %d\n", errno); // 오류발생시 NULL을 반환, 에러출력
	exit(1);
    }
    fclose(fp);

    return 0;
}
