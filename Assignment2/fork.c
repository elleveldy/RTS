#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


int global_variable = 0;

//Vfork:
//Child borrows parents' memory and doesn't return it, unless it exits.
// parent is therefore incrementing after child has incremented
// fork:
// child and parent have their own memory and are both incrementing from 0

int main(){
	int local_variable = 0;

	vfork();
	int i;
	for(i = 0; i < 5; i++){
		global_variable++;
		local_variable++;
		printf("global: %i\tlocal: %i\n", global_variable, local_variable);
	}
	exit(2);

}