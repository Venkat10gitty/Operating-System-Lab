#include <stdio.h>
#include <stdlib.h>

int mutex = 1;
int full = 0;
int empty = 10, x = 0;

void producer()
{
	--mutex;
	++full;
	--empty;
	x++;
	printf("Producer produces item %d\n",x);\
	++mutex;
}

void consumer()
{
	--mutex;
	--full;
	++empty;
	printf("Consumer consumes item %d\n",x);
	x--;
	++mutex;
}

int main()
{
	int n, i;
    for(int i =0; i<3; i++) {
        if ((mutex == 1) && (empty != 0)) {
		    producer();
	    }
	    else {
		    printf("Buffer is full!");
	    }
    }
    for(int i =0; i<3; i++) {
        if ((mutex == 1) && (full != 0)) {
			consumer();
		}
		else {
			printf("Buffer is empty!");
		}
    }
}

