/* 파일 기술자 복사하기 */
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
int main(void) {
    int fd, fd1;
    // tmp.aaa파일이 없으면 생성한다. 쓰기전용으로 연다. 만약 tmp.aaa가 존재하면 내용을 모두 지운다.
    fd = open("tmp.aaa", O_CREAT | O_WRONLY | O_TRUNC, 0644);
    if (fd == -1) {
        perror("Create tmp.aaa");
        exit(1);
    }
    close(1); // 표준 출력을 닫았다.

    fd1 = dup(fd); // fd를 복사하면 가장 작은 값인 1로 복사된다.
    printf("DUP FD=%d\n", fd1);
    printf("Standard Output Redirection\n");
    close(fd);
    return 0;
}
