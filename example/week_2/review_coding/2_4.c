#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>

int main(){
    int rfd, wfd, n;
    char buf[10];

    // unix.txt를 읽기모드로 가져옴
    rfd = open("unix.txt", O_RDONLY);
    if(rfd == -1){
        perror("Open unix.txt");
        exit(1);
    }

    // unix.bak를 쓰기, 초기화 모드로 가져옴
    wfd = open("unix.bak", O_CREAT|O_WRONLY|O_TRUNC);
    if (wfd == -1){
        perror("Open unix.bak");
        exit(1);
    }

    // rfd을 buf에 6바이트만큼 읽어서 저장함
    while((n = read(rfd, buf, 6)) > 0)

    // wfd에 buf의 n바이트를 읽어서 저장함
    if(write(wfd, buf, n) != n) perror("write");

    if(n==-1) perror("Read");
    close(rfd);
    close(wfd);
    return 0;
}