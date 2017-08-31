#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void work();

int main (int argc, char** argv) {
	pid_t pid = getpid();
	int nproc = atoi(argv[1]);

	for (int i = 0; i < nproc && pid != 0; i++) {
		pid = fork();
		if (pid == 0) {
			work();
		}
	}
	for (int i = 0; i < nproc; i++) {
		wait(NULL);
	}
}

void work () {
	srand(getpid());
	int seconds = (rand() % 9) + 1;
	sleep(seconds);
	printf("Processo %d criado.\n", (int) getpid());
}


