#include <stdlib.h>
#include <stdio.h>

#include <unistd.h>
#include <pthread.h>


void *sleep_5sec(){

	printf("Sleep 5 sec.\n");
	sleep(5);
	printf("Woke up.\n");

}

int main(){
	pthread_t thread;


	pthread_create(&thread, NULL, sleep_5sec, NULL);
	pthread_create(&thread, NULL, sleep_5sec, NULL);

	pthread_join(thread,NULL);

	return 0;

}

