#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

// 새 파일 열고 닫기
int main(void){
    int fd;
    mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;

    fd = open("unix.txt", O_CREAT, mode); // 파일 열기
    if(fd == -1){
        perror("Creat");
        exit(1);
    }
    close(fd); // 파일 닫기
    return 0;

}