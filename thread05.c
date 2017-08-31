#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#define NINC 100

int danger;
sem_t semaphore;

void* start (void* args) {
	printf("Nova thread criada. TID = %lu!\n", (unsigned long) pthread_self());
	for (int i = 0; i < NINC; i++) {
		sem_wait(&semaphore);
		danger++;
		sem_post(&semaphore);
	}
	pthread_exit(NULL);
}

int main (int argc, char** argv) {
	int nthreads = atoi(argv[1]);
	pthread_t thread[nthreads];
	sem_init(&semaphore, 0, 1);

	for (int i = 0; i < nthreads; i++) {
		pthread_create(&(thread[i]), NULL, start, NULL);
	}
	for (int i = 0; i < nthreads; i++) {
		pthread_join(thread[i], NULL);
	}

	printf("Valor global: %d\n", danger);

	pthread_exit(NULL);
	sem_destroy(&semaphore);
}

