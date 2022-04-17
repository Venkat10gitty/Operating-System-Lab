#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
void* calls(void* ptr)
{
   
	printf("In function \nthread id = %d\n", pthread_self());
	pthread_exit(NULL);
	return NULL;
}

int main()
{
	pthread_t thread; 
	pthread_create(&thread, NULL, calls, NULL);
    printf("Process id: %ld%ld", (long)getpid(), (long)getppid());
	printf("In main \nthread id = %d\n", thread);
	pthread_join(thread, NULL);
	return 0;
}
