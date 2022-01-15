#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
/*
int fcntl(int fd, int cmd);
int fcntl(int fd, int cmd, long arg);
int fcntl(int fd, int cmd, struct flock *lock);
*/
int main(void){
    int fd, flags;

    if (fd = open("fcntlTest.txt", O_RDWR) == -1){
        perror("open Error");
        exit(1); // 문제가 있음을 알리는 1
    }

    if ((flags = fcntl(fd, F_GETFL)) == -1){
        perror("fcntl Error");
        exit(1);
    }
    printf("****************플래그 종류*****************\n");
    printf("현재 flags = %d, fd flags(O_RDWR) = %d\n", flags, O_RDWR);
    printf("O_RDONLY = %d\n", O_RDONLY);
    printf("O_WRONLY = %d\n", O_WRONLY);
    printf("O_RDWR = %d\n", O_RDWR);
    printf("O_EXCL = %d\n", O_EXCL);
    printf("O_APPEND = %d\n", O_APPEND);

    printf("*******************FD_SETFL******************\n");
    // setfl 사용
    flags |= O_APPEND;
    if (fcntl(fd, F_SETFL, flags) == -1){
        perror("fcntl SETFD");
        exit(1);
    }

    // getfl로 플래그 확인
    if ((flags = fcntl(fd, F_GETFL)) == -1){
        perror("fcntl Error");
        exit(1);
    }

    switch (flags & O_ACCMODE){
        case O_RDONLY:
        case O_WRONLY:
        case O_RDWR:
        case O_CREAT:
        case O_TRUNC:
        case O_DIRECT:
        case O_EXCL:
        case O_NOCTTY:
        case O_RSHARE:
        case O_NSHARE:
        case O_NONBLOCK:
        case FNONBLOCK:
        case O_APPEND:
        case FAPPEND:
        case O_SYNC:
        case FSYNC:
        case O_DSYNC:
        case FDATASYNC:
        case O_RSYNC:
        case FREADSYNC:
        case FASYNC:
        case O_NDELAY:
        case FNDELAY:
        case O_LARGEFILE:
        case O_DEFER:
        case O_DELAY:
        case O_DIRECT:
        case FD_CLOEXEC:	
        case FREAD:
        case FWRITE:
        case F_DUPFD:
        case F_GETFD:
        case F_SETFD:
        case F_GETFL:
        case F_SETFL:
        case F_GETLK:
        case F_GETLK64:
        case F_SETLK:
        case F_SETLK64:
        case F_SETLKW:
        case F_SETLKW64:
        case F_GETOWN:
        case F_SETOWN:
    }
    close(fd);
    return 0;

}