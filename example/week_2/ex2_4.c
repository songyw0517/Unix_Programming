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
    // rfd로부터 6바이트씩 읽어 buf에 저장, n에는 글자수가 저장됨
    while ((n = read(rfd, buf, 6)) > 0) 
    // wfd에 n바이트 만큼 파일에 기록, 글자수가 n이 아닐 경우 에러 발생
    if (write(wfd, buf, n) != n) perror("Write");
    
    if (n == -1) perror("Read");
    close(rfd);
    close(wfd);
    
    return 0;
}