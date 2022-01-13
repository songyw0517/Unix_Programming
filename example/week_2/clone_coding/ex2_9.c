#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(void){
    int fd, flags;

    fd = open("unix.txt", O_RDWR); // unix.txt를 읽기 쓰기 모드로 연다.
    if (fd == -1){
        perror("open");
        exit(1);
    }
    // flags는 fcntl의 반환값, 
    if ((flags = fcntl(fd, F_GETFL)) == -1){
        perror("fcntl");
        exit(1);
    }
    printf("flags = %d\n", flags);
    printf("O_RDONLY = %d\n", O_RDONLY);
    printf("O_WRONLY = %d\n", O_WRONLY);
    printf("O_RDWR = %d\n", O_RDWR);
    printf("O_EXCL = %d\n", O_EXCL);
    printf("O_APPEND = %d\n", O_APPEND);
    printf("32770 |= O_APPEND = %d\n", 32770|O_APPEND);

    flags |= O_APPEND; // 파일을 추가 모드로 수정

    printf("O_APPEND |= O_APPEND = %d\n", flags);
    if (fcntl(fd, F_SETFL, flags) == -1){
        perror("fcntl");
        exit(1);
    }

    
    if (write(fd, "Hanbit Media", 12) != 12) perror("write");
    close(fd);

    return 0;
}