#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void* start (void* args) {
	printf("Nova thread criada. TID = %lu!\n", (unsigned long) pthread_self());
	pthread_exit(NULL);
}

int main (void) {
	pthread_t thread;
	pthread_create(&thread, NULL, start, NULL);
	pthread_join(thread, NULL);
	pthread_exit(NULL);
}

