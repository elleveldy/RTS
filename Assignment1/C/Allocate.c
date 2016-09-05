#include "stdlib.h"
#include "stdio.h"
#include "string.h"

// void changed to int. method should perror() in case of failed allocation, 0 in case of success

int allocate (int value) {
	int *ptr = NULL;	// pointer is set to null
	ptr = malloc(100000 * sizeof(int));	// success?
	*ptr = value;
	// printf("test of allocated memory: %i\n");
	printf("The allocated memory starts at address: %i \n", *ptr);
	if (ptr == NULL) {
		perror("Error: Memory could not be allocated.");
	} else return 0;
}

int main() {
	int x = 2;
	allocate(x);
	return 0;
}
