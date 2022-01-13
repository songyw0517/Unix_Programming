// open
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
int open(const char *path, int oflag [, mode_t mode]);

// close
#include <unistd.h>
int close(int fildes);

// read
#include <unistd.h>
ssize_t read(int fildes, void *buf, size_t nbytes);

// write
#include <unistd.h>
ssize_t read(int fildes, void *buf, size_t nbytes);

// lseek
#include <sys/types.h>
#include <unistd.h>
off_t lseek(int fildes, off_t offset, int whence);

// dup
#include <unistd.h>
int dup(int fildes);

// dup2
#include <unistd.h>
int dup2(int fildes);

// fcntl
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
int fcntl(int fildes, int cmd, /* arg */ ...);

// unlink
#include <unistd.h>
int unlink(const char *path);

// remove
#include <stdio.h>
int remove(const char *path);


// fopen
#include <stdio.h>
FILE *fopen(const char *filename, const char *mode);

// fclose
#include <stdio.h>
int fclose(FILE *stream);

// fgetc, getc, getchar, getw
#include <stdio.h>
int fgetc(FILE *stream);
int getc(FILE *stream);
int getchar(void);
int getw(FILE *stream);


// fputc, putc, putchar, putw
#include <stdio.h>
int fputc(int c, *stream);
int putc(int c, *stream);
int putchar(int c);
int putw(int w, FILE *stream);


