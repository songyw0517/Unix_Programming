/*파일 읽기*/
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
int main(void) {
    int rfd, wfd, n; // 파일 기술자 rfd, wfd
    char buf[10]; // 버퍼
    // 읽기 전용으로 읽어오기
    rfd = open("unix.txt", O_RDONLY);

    if(rfd == -1) {
        perror("Open unix.txt");
        exit(1);
    }

    // 쓰기 전용으로 읽어오기
    wfd = open("unix.bak", O_CREAT | O_WRONLY | O_TRUNC, 0644);
    if (wfd == -1) {
        perror("Open unix.bak");
        exit(1);
    }
    // rfd로부터 6바이트씩 읽어 buf에 저장, n에는 글자수가 저장됨 (read의 반환값)
    while ((n = read(rfd, buf, 6)) > 0) 
    
    // wfd에 n바이트 만큼 파일에 기록, 글자수가 n이 아닐 경우 에러 발생
    if (write(wfd, buf, n) != n) perror("Write");
    
    if (n == -1) perror("Read");
    close(rfd);
    close(wfd);
    
    return 0;
}
/*
$ ls unix.bak
ls: cannot access 'unix.bak': No such file or directory
$ vi unix.txt
'Unix System Programming' 작성
$ gcc -o ex2_4.out ex2_4.c
$ ./ex2_4.out
$ cat unix.bak
Unix System Programming
*/