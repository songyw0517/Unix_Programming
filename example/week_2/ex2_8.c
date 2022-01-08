/* dup2 함수 사용하기 */
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
int main(void) {
    int fd;
    fd = open("tmp.bbb", O_CREAT | O_WRONLY | O_TRUNC, 0644);
    if (fd == -1) {
        perror("Create tmp.bbb");
        exit(1);
    }
    // dup2 사용
    dup2(fd, 1); // 표준출력 (1)로 지정하여 복사
    printf("DUP2 : Standard Output Redirection\n"); // 파일에 쓰기
    close(fd);
    return 0;
}
/*
$ gcc -o ex2_8.out ex2_8.c
$ ./ex2_8.out
$ cat tmp.bbb
DUP2 : Standard Output Redirection
*/