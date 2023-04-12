#include "p1fxns.h"
#include <stdlib.h>
#define UNUSED __attribute__((unused))

volatile bool USR1_seen = false; 

void onusr1(UNUSED int sig){
	USR1_seen = true; 

}
​
int main(UNUSED int argc, UNUSED char *argv[]) {
	struct timespec ms20 = {0, 20000000};
	if (signal(SIGUSR1, onusr1) == SIG_ERROR){
		printf(stderr, "Cant establish the SIGUSR1 handler\n");
		return EXIT_FAILURE;
	}


	while(!USR1_seen){
		(void)nanosleep(&ms20, NULL);
	}

	printf("SIGUSR1 recieved\n");
	return EXIT_SUCCESS;
}
