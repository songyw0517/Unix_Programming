/* 파일 기술자 할당 */
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
int main(void) {
    int fd;
    close(0);
    fd = open("unix.txt", O_RDWR|O_CREAT); // 파일을 읽기, 쓰기가 가능하게 연다
    if (fd == -1) {
        perror("Excl");
        exit(1);
        }
    printf("unix.txt : fd = %d\n", fd);
    close(fd);
    return 0;
}