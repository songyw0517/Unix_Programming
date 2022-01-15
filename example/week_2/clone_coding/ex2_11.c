// 문자 기반 입출력 함수 사용하기
#include <stdlib.h>
#include <stdio.h>

int main(void){
    FILE *rfp, *wfp;
    int c;

    // unix.txt를 r모드로 연다. rfp는 unix.txt파일을 가리킨다.
    if((rfp = fopen("unix.txt", "r")) == NULL){
        perror("fopen : unix.txt");
        exit(1);
    }
    
    // unix.out을 w모드로 연다. wfp는 unix.out파일을 가리킨다.
    if((wfp = fopen("unix.out", "w")) == NULL){
        perror("fopen : unix.out");
        exit(1);
    }

    // rfp로부터 하나의 문자를 읽어 c에 저장한다. c가 EOF이면 while문을 나온다.
    while((c = fgetc(rfp)) != EOF){

        // c의 문자를 wfp에 출력(쓴)다.
        fputc(c, wfp);
    }
    fclose(rfp);
    fclose(wfp);

    return 0;
}