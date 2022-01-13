/*
새 파일 열고 닫기
*/
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
int main(void) {
    int fd;
    mode_t mode;
    mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH; // 권한 : 644
    /*
    S_IRUSR : USER에 R 권한
    S_IWUSR : USER에 W 권한
    S_IRGRP : GROUP에 R 권한
    S_IROTH : OTHER에 R 권한
    
    USER/GROUP/OTHER : RW-R--R--
    */
    fd = open("unix.txt", O_CREAT, mode); // unix.txt파일이 없으면 파일 생성, 권한 설정
    if (fd == -1) {
        // 실패시 에러발생
        perror("Creat");
        exit(1);
        }
        close(fd);
        return 0;
}
/*
$ ls unix.txt
ls: cannot access 'unix.txt': No such file or directory
$ gcc -o ex2_1.out ex2_1.c
$ ./ex2_1.out
$ ls -l unix.txt
-rw-r--r-- 1 scof scof 0 Jan  8 16:00 unix.txt
*/