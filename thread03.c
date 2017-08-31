#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#define NINC 100

int danger;

void* start (void* args) {
	printf("Nova thread criada. TID = %lu!\n", (unsigned long) pthread_self());
	for (int i = 0; i < NINC; i++) {
		danger++;
	}
	pthread_exit(NULL);
}

int main (int argc, char** argv) {
	int nthreads = atoi(argv[1]);
	pthread_t thread[nthreads];

	for (int i = 0; i < nthreads; i++) {
		pthread_create(&(thread[i]), NULL, start, NULL);
	}
	for (int i = 0; i < nthreads; i++) {
		pthread_join(thread[i], NULL);
	}

	printf("Valor global: %d\n", danger);

	pthread_exit(NULL);
}

