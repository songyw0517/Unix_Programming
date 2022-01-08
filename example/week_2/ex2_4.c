/*파일 읽기*/
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
int main(void) {
    int rfd, wfd, n; // 파일 기술자 rfd, wfd
    char buf[10]; // 버퍼
    rfd = open("unix.txt", O_RDONLY); // 읽기 전용으로 읽어오기
    if(rfd == -1) {
        perror("Open unix.txt");
        exit(1);
    }
    wfd = open("unix.bak", O_CREAT | O_WRONLY | O_TRUNC, 0644);
    if (wfd == -1) {
        perror("Open unix.bak");
        exit(1);
    }
}