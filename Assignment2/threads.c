#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>


// memory of global variable is shared while memory of local variable isn't

int global_variable = 0;


void* increment_variables(void * random){
	int local_variable = 0;

	int i;
	for(i = 0; i < 5; i++){
		global_variable++;
		local_variable++;
		printf("global: %i\tlocal: %i\n", global_variable, local_variable);
	}
	return;
}


int main(){
	
	pthread_t thread1, thread2;


	pthread_create(&thread1, NULL, &increment_variables, NULL);
	pthread_create(&thread2, NULL, &increment_variables, NULL);

	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);



}