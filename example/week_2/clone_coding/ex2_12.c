// 문자열 기반 입출력 함수 사용하기
#include <stdio.h>
#include <stdlib.h>

int main(void){
    FILE *rfp, *wfp;
    char buf[BUFSIZ];

    if ((rfp = fopen("unix.txt", "r")) == NULL){
        perror("fopen : unix.txt");
        exit(1);
    }

    if ((wfp = fopen("unix.out", "a")) == NULL){
        perror("fopen : unix.out");
        exit(1);
    }

    // rfp로부터 BUFSiZ (stdio에 정의)만큼, 한 행씩 읽어서 buf에 저장
    while(fgets(buf, BUFSIZ, rfp) != NULL){
        // wfp에 buf내용을 쓴다.
        fputs(buf, wfp);
    }

    fclose(rfp);
    fclose(wfp);
}