#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#define SIZE 512

int main(void){
    sssize_t nread;
    char buf[SIZE];

    while((nread = read(0, buf, SIZE)) > 0)
        write(1, buf, nread);
    return 0;
}