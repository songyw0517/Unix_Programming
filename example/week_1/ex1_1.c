#include<unistd.h>
#include<stdio.h>
#include</usr/include/errno.h> // 추가

extern int errno;

int main(void){
    if (access("unix.txt", F_OK) == -1){
        printf("errno = %d\n", errno); // printf를 사용하여 error 번호를 출력
    }

    return 0;
}
