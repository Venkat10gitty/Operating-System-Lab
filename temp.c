#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int
main(void)
{
    printf("%ld%ld", (long)getpid(), (long)getppid());
    return 0;
}