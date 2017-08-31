#include <stdio.h>
#include <unistd.h>

int main (void) {
	pid_t test;
	test = fork();
	printf("Novo processo criado!\n");
}
