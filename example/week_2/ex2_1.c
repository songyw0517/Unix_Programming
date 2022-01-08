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
    fd = open("unix.txt", O_CREAT, mode);
    if (fd == -1) {
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