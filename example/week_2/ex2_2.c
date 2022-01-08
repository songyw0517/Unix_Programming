/* O_EXCL 플래그 사용하기 */
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
int main(void) {
    int fd;
    fd = open("unix.txt", O_CREAT | O_EXCL, 0644);
    // O_EXCL : 기존에 없는 파일이면 파일을 생성, 파일이 이미 있으면 오류 발생
    if (fd == -1) {
        perror("Excl");
        exit(1);
        }
    close(fd);
    return 0;
}