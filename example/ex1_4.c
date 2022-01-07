#include<sys/errno.h>
#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>

int main(){
	if (access("unix.txt", R_OK) == -1){
		perror("unix.txt"); // 에러 메시지 출력, perror은 stdio에 있음
		exit(1);
	}
	return 0;
}
