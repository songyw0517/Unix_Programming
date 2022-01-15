#include <stdlib.h>
#include <stdio.h>

int main(void){
    FILE *rfp;
    char buf[BUFSIZ];
    int n;

    if ((rfp = fopen("unix.txt", "r")) == NULL){
        perror("fopen : unix.txt");
        exit(1);
    }

    // rfp로부터 sizeof(char)*2인 데이터를 3만큼 읽어 buf에 저장
    while((n = fread(buf, sizeof(char)*2, 1, rfp)) > 0){
        buf[6] = '\0';
        printf("n = %d, buf=%s, sizeof(char)*2 = %ld\n", n, buf, sizeof(char)*2);
    }
    fclose(rfp);
    return 0;

}