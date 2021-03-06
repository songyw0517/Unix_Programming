# Unix Programming 공부

# 환경
- Windows vscode에서 Remote-SSH를 이용하여 Ubuntu Server에 접속

# 방법
- Summary.docx에 내용 정리
- example에 예제코드 정리
- README.md에 C함수 및 유닉스 명령어 정리

# C코드 기능
## 오류 메시지 출력 : perror
``` C
#include <stdio.h>
void perror(const char *s);
```
## 오류 메시지 출력 : strerror
``` C
#include <string.h>
char *strerror(int errnum);
```
## 메모리 할당 : malloc
``` C
#include <stdlib.h>
void *malloc(size_t size);
```
## 메모리할당과 초기화 : calloc
``` C
#include <stdlib.h>
void *calloc(size_t nelem, size_t elsize);
```
## 메모리 추가 할당 : realloc
``` C
#include <stdlib.h>
void *realloc(void *ptr, size_t size);
```
## 메모리 해제 : free
``` C
#include <stdlib.h>
void free(void *ptr)
```
## 파일 열기 : open
``` C
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
int open(const char *path, int oflag [, mode_t mode]);

- path : 경로와 이름
- oflag
    - O_RDONLY : 파일을 읽기 전용으로 연다.
    - O_WRONLY : 파일을 쓰기 전용으로 연다.
    - O_RDWR|O_CREAT : 파일을 읽기와 쓰기가 가능하게 연다.
    - O_CREAT : 파일이 없으면 파일을 생성한다
    - O_EXCL | O_CREAT : O_CREAT 옵션과 함께 사용할 경우 기존에 없는 파일이면 파일을 생성하지만, 파일이 이미 있으면 파일을 생성하지 않고 오류 메시지를 출력한다.
    - O_APPEND : 파일의 맨 끝에 내용을 추가한다.
    - O_TRUNC | O_CREAT : 파일을 생성할 때 이미 있는 파일이고 쓰기 옵션으로 열었으면 내용을 모두 지우고 파일의 길이를 0으로 변경한다.
    - O_NONBLOCK/O_NDELAY : 비블로킹(Non-blocking) 입출력
    - O_SYNC/O_DSYNC : 저장장치에 쓰기가 끝나야 쓰기 동작을 완료

- mode : 파일 접근 권한 지정, 0644같이 숫자나 플래그 값으로 지정 가능
    - S_IRWXU   0700    소유자 읽기/쓰기/실행 권한
    - S_IRUSR   0400    소유자 읽기 권한
    - S_IWUSR   0200    소유자 쓰기 권한
    - S_IXUSR   0100    소유자 실행 권한
    - S_IRWXG   0070    그룹 읽기/쓰기/실행 권한
    - S_IRGRP   0040    그룹 읽기 권한
    - S_IWGRP   0020    그룹 쓰기 권한
    - S_IXGRP   0010    그룹 실행 권한
    - S_IRWXO   0007    기타 사용자 읽기/쓰기/실행 권한
    - S_IROTH   0004    기타 사용자 읽기 권한
    - S_IWOTH   0002    기타 사용자 쓰기 권한
    - S_IXOTH   0001    기타 사용자 실행 권한
```
## 파일 생성 : creat
- 파일 생성 함수, open 함수에 파일 생성 기능이 없던 구버전 유닉스에서 사용 (요즘 사용X)
- open 함수와 달리 옵션을 지정하는 부분이 없다.
- create 함수로 파일을 생성하면 파일 기술자를 리턴하므로 별도로 open할 필요 없음
- open with open( path, O_CREAT|O_WRONLY|O_TRUNC, mode)와 동일
``` C
#include <sys/stat.h>
#include <fcntl.h>
int creat(const char *path, mode_t mode);
```
## 파일 닫기 : close
``` C
#include <unistd.h>
int close(int fildes);
```
## 파일 읽기 : read
- 파일에서 nbytes로 지정한 크기만큼 바이트를 읽어서 buf에 저장
- 실제로 읽어온 바이트 개수를 리턴
- 리턴값이 0이면 파일의 끝에 도달했음을 의미
- 파일의 종류에 상관없이 무조건 바이트 단위로 읽어온다.
``` C
#include <unistd.h>
ssize_t read(int fileds, void *buf, size_t nbytes);
```
## 파일 쓰기 : write
- buf가 가리키는 메모리에서 nbytes로 지정한 크기만큼 파일에 기록
- 실제로 쓰기를 수행한 바이트 수 리턴
``` C
#include <unistd.h>
ssize_t write(int fildes, const void *buf, size_t nbytes);
```

## 파일 오프셋 위치 지정 : lseek
- offset으로 지정한 크기만큼 오프셋을 이동시킨다.
- offset의 값은 whence값을 기준으로 해석한다.
``` C
#include <sys/types.h>
#include <unistd.h>
off_t lseek(int fildes, off_t offset, int whence);

whence
- offset의 기준
    - SEEK_SET : 파일의 시작 기준
    - SEEK_CUR : 현재 위치 기준
    - SEEK_END : 파일의 끝 기준
```

## 파일 기술자 복사 : dup
- 기존 파일 기술자를 인자로 받아 새로운 파일 기술자를 리턴
- 새로운 파일 기술자는 현재 할당할 수 있는 파일 기술자 중 가장 작은 값으로 자동할당
``` C
#include <unistd.h>
int dup(int fildes)
```

## 파일 기술자 복사 : dup2
- 새로운 파일 기술자를 지정할 수 있다.
``` C
#include <unistd.h>
int dup2(int fildes, int fildes2)
```

## 파일 기술자 제어 : fcntl
- 파일 기술자가 가리키는 파일에 cmd로 지정한 명령을 수행
- cmd의 종류에 따라 인자(arg)를 지정할 수 있음
- 자주 사용하는 cmd
    - F_GETFL : 상태 플래그 정보를 읽어온다.
    - F_SETFL : 상태 플래그 정보를 설정한다. 설정할 수 있는 플래그는 대부분 open 함수에서 지정하는 플래그이다.

# 고수준 파일 입출력 : 표준 입출력 라이브러리
## 파일 열기 : fopen
- filename으로 지정한 파일을 mode로 지정한 모드에 따라 열고 파일 포인터를 리턴
``` C
#include <stdio.h>
FILE *fopen(const char *filename, const char *mode);
```

## 파일 닫기 : fclose
``` C
#include <stdio.h>
int fclose(FILE *stream);

filename : 파일이름
mode : 모드
    - r : 읽기 전용
    - w : 새로 쓰기용, 기존 내용은 삭제
    - a : 추가용
    - rb : 읽기 전용, 바이너리
    - wb : 새로 쓰기용, 바이너리, 기존 내용 삭제
    - ab : 추가용, 바이너리
    - r+ : 읽기와 쓰기용
    - w+ : 쓰기와 읽기용
    - a+ : 추가와 읽기용
    - rb+ : 읽기와 쓰기용, 바이너리
    - wb+ : 쓰기와 읽기용, 바이너리
    - ab+ : 추가와 읽기용, 바이너리

```
## 문자 기반 입력함수 : fgetc, getc, getchar, getw
``` C
#include <stdio.h>
int fgetc(FILE *stream);
: 문자 한 개를 unsigned char 형태로 읽어온다.

int getc(FILE *stream);
int getchar(void);
: 매크로

int getw(FILE *stream);
: 워드 단위로 읽어온다.
```


# 명령어
## man (메뉴얼)
- 명령어의 메뉴얼의 내용을 보여준다.
- 로컬 시스템에서 여러 참고 문서들을 이용하여 특정 명령이나 자원들의 메뉴얼을 출력하는 영역으로, 
유닉스에서는 총 8개의 영역으로 되어있으나, 리눅스 커널 부분이 추가되어 총 9개의 영역으로 구성되어 있다.
    ## manual Section (man 섹션)
    - man1 : 실행 프로그램 또는 셸 명령
    - man2 : 시스템 콜 (시스템 호출)
    - man3 : 라이브러리 콜 (라이브러리 호출)
    - man4 : Special Files (관련 장치, 드라이버, FIFO, socket, /dev 등)
    - man5 : 파일 형식 및 규칙 (/etc/passwd, /etc/shadow, winetd,conf 등)
    - man6 : 게임
    - man7 : Miscellanea (리눅스 시스템 파일 관련 표준, 규칙, 프로토콜, 문자셋, 시그널 목록 등에 대한 정보)
    - man8 : System Administration commands( root가 사용하는 시스템 관리와 관련된 명령어 )
    - man9 : Linux kernel routines (리눅스 커널)
    ## man 사용법
    ~~~
    $ man [option] [section] command
    ~~~
    ## man option
    - k 키워드 : 해당 키워드로 발견되는 모든 매뉴얼의 내용을 검색하여 보여준다.
    - f 키워드 : 해당 키워드에 대한 완벽히 일치되는 매뉴얼 페이지에 대한 정보를 보여준다.
    - w 키워드 : man 명령 실행 시에 호출되는 '메뉴얼 페이지' 파일의 위치를 보여준다.(--path)
    - s, -S : 특정 section을 지정할 때 사용한다. (--sections=섹션번호)
    ~~~
    $ man ls
    ls 명령어의 메뉴얼 페이지를 보여준다. 기본적으로 영역 값을 지정하지 않으면 첫 번째 영역의 페이지 정보를 출력한다.

    $ man man 
    man 명령어의 매뉴얼 페이지를 보여준다. 

    $ man -k passwd
    passwd라는 키워드가 포함된 메뉴얼 페이지를 찾아서 출력한다. 

    $ man -f passwd 
    passwd라는 키워드와 일치하는 메뉴얼 페이지의 목록 정보를 출력한다. 

    $ man 5 passwd
    다섯 번째 영역에 있는 passwd의 메뉴얼 페이지를 출력한다.

    $ man -w mkdir
    man mkdir 실행 시에 출력되는 '메뉴얼 페이지' 파일의 경로를 출력한다.

    ~~~
