// open
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
int open(const char *path, int oflag [, mode_t mode]);

// close
#include <unistd.h>
int close(int fildes);
