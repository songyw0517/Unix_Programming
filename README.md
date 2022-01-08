# 유닉스시스템 프로그래밍의 정의
- 유닉스에서 제공하는 시스템 호출을 사용해 프로그램을 작성하는 것
# 시스템 호출
- 유닉스 시스템이 제공하는 서비스를 이용해 프로그램을 작성할 수 있도록 제공되는 프로그래밍 인터페이스
- 기본적인 형태는 C언어 함수 형태로 제공됨
# 라이브러리 함수
- 미리 컴파일된 함수들을 묶어서 제공하는 특수한 형태의 파일
- 자주 사용하는 기능을 독립적으로 분리하여 구현 -> 프로그램의 개발과 디버깅을 쉽게하고, 컴파일을 빠르게 할 수 있다.
- 일반적으로 커널 모듈을 직접 호출하지 않는다.
# 컴파일
- 텍스트로 작성한 프로그램을 시스템이 이해할 수 있는 기계어로 변환하는 과정
- 보통 컴파일 과정과 라이브러리 링크 과정을 묶어서 수행하는 것을 의미한다.

# 저수준 파일 입출력과 고수준 파일 입출력
## 저수준 파일 입출력
- 파일 지시자 = 파일 기술자(file descriptor)
- 유닉스 커널의 시스템 호출을 사용하여 파일 입출력 실행
- <b>파일에 빠르게 접근 가능, 바이트 단위로 파일의 내용을 다룸 -> 특수 파일도 읽고 쓸 수 있다.</b>
- 바이트 단위를 적당한 형태의 데이터로 변환하는 함수 등이 필요하다.
## 고수준 파일 입출력
- 파일 지시자 = 파일 포인터(file pointer)
- C언어의 표준 함수로 제공, 여러가지 형태의 데이터 형식을 지원
- 버퍼 단위로 읽고 쓰기가 가능하다.
## 저수준 VS 고수준
- 저수준은 버퍼가 없어서 빈번하게 일어나는 작은 데이터에 대해 오버헤드가 발생할 수 있다.
- 고수준은 버퍼가 있어서 작은 단위들을 한번에 처리할 수 있기에 오버헤드가 덜 발생한다.

# 파일 기술자
- 현재 열려있는 파일을 구분하는 정수값
- 저수준 파일 입출력에서 열린 파일을 참조하는데 사용된다.
- 0 : 표준 입력 | 1 : 표준 출력 | 2 : 표준 오류


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
## 파일 생성 : create
- 파일 생성 함수, open 함수에 파일 생성 기능이 없던 구버전 유닉스에서 사용 (요즘 사용X)
- open 함수와 달리 옵션을 지정하는 부분이 없다.
- create 함수로 파일을 생성하면 파일 기술자를 리턴하므로 별도로 open할 필요 없음
- open with open( path, O_CREAT|O_WRONLY|O_TRUNC, mode)와 동일
``` C
#include <sys/stat.h>
#include <fcntl.h>
int create(const char *path, mode_t mode);
```
## 파일 닫기 : close
``` C
#include <unistd.h>
int close(int fildes);
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
