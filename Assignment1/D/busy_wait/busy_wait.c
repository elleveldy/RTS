#include <stdlib.h>
#include <stdio.h>

#include <unistd.h>
#include <pthread.h>
#include <sys/times.h>
//#include <time.h>




void busy_wait_delay(int seconds)
{
	time_t timer;


    int start_time = time(&timer);
    int current_time = 0;
    while( (current_time - start_time) < seconds)
    {
   		current_time = time(&timer);
    }
}

void* busy_wait_print(void* arg){
	printf("Hello from thread nr %i\n", (int)arg);
	busy_wait_delay(5);
	printf("Goodbye from thread nr %i\n", (int)arg);

}



int main(){
	pthread_t thread;


	pthread_create(&thread, NULL, busy_wait_print, 1);
	pthread_create(&thread, NULL, busy_wait_print, 2);

	pthread_join(thread,NULL);

	return 0;

}

