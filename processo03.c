#include <stdio.h>
#include <unistd.h>
#define NPROC 2

int level = 2;

void create_procs(int num);

int main (void) {
	create_procs(NPROC);
}

void create_procs(int num) {
	pid_t pid = getpid();

	for (int i = 0; i < NPROC && pid != 0; i++) {
		pid = fork();
		if (pid != 0) {
			printf("Processo pai %d criou filho %d\n", (int) getpid(), (int) pid);
		} else {
			level--;
			if (level > 0) {
				create_procs(num);
			}
		}
	}

}
