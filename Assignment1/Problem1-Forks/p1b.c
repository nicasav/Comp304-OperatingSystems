#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
	pid_t pid = fork();
	if (pid == -1) {
		printf("Failed to fork!\n");
		exit(1);
	} else if (pid == 0) {
		printf("Child process created.\n");
		exit(0);
	} else if (pid > 0) {
		printf("Parent process created.\n");
		sleep(5);
		//wait(NULL);
		//sleep(5);
	}

	return 0;
}
