#include <stdio.h>
#include <unistd.h>
#define NPROC 4

int main (void) {
	pid_t pid = getpid();

	for (int i = 0; i < NPROC && pid != 0; i++) {
		pid = fork();
		if (pid != 0) {
			printf("Processo pai %d criou filho %d\n", (int) getpid(), (int) pid);
		}
	}
}
