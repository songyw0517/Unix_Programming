#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
int main(void) {
    int fd, n;
    off_t start, cur;
    char buf[256];
    fd = open("unix.txt", O_RDONLY); // 읽기 전용으로 읽음

    // 제대로 읽었는지 확인
    if (fd == -1) {
        perror("Open unix.txt");
        exit(1);
    }

    start = lseek(fd, 0, SEEK_CUR); // 현재 위치 0
    n = read(fd, buf, 255); // 225bytes만큼 읽음, n에는 글자수가 들어감
    buf[n] = '\0'; // 마지막임을 알려주는 문자
    // start = 0, buf = "Unix System Programming\0", n=24
    printf("Offset start=%d, Read Str=%s, n=%d\n", (int)start, buf, n);

    // 현재 위치 cur = 24
    cur = lseek(fd, 0, SEEK_CUR);
    printf("Offset cur=%d\n", (int)cur);

    // 파일의 시작 기준으로 5만큼 이동, start=5
    start = lseek(fd, 5, SEEK_SET);
    n = read(fd, buf, 255);
    buf[n] = '\0';
    printf("Offset start = %d, Read Str=%s", (int)start, buf);

    close(fd);
    return 0;
}