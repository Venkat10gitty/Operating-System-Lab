#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
int MAX = 50;
int count = 1;
pthread_mutex_t thr;
pthread_cond_t cond;

void *number(void *arg)
{
    for(int i = 0; i < MAX; i++)
    {
        printf("20BCE1551, ");
        pthread_mutex_unlock(&thr);
        pthread_cond_signal(&cond);
    }
    pthread_exit(0);
}
void *name(void *arg)
{
    for(int i = 0; i < MAX; i++)
    {
        printf("Venkat, ");
        pthread_mutex_unlock(&thr);
        pthread_cond_signal(&cond);
    }
    pthread_exit(0);
}
int main()
{
    pthread_t thread1;
    pthread_t thread2;
    pthread_mutex_init(&thr, 0);
    pthread_cond_init(&cond, 0);
    pthread_create(&thread1, 0, &name, NULL);
    pthread_create(&thread2, 0, &number, NULL);
    
    pthread_join(thread1, 0);
    pthread_join(thread2, 0);
    pthread_mutex_destroy(&thr);
    pthread_cond_destroy(&cond);
    return 0;
}