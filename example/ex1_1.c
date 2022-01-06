#include<unistd.h>
#include<stdio.h>
#include</usr/include/errno.h> // 추가

extern int errno;

int main(void){
    if (access("unix.txt", F_OK) == -1){
        printf("errno = %d\n", errno);
    }

    return 0;
}
