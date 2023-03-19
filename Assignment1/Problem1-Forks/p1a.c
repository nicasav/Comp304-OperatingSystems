#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
	int n = atoi(argv[1]);
	int level = 0;
	printf("Main ProcessID: %d, level: %d\n", getpid(), level);
	for ( int i = 0; i < n; i++) {
		if (fork() == 0) {
			level++;
			printf("Process ID: %d, Parent ID: %d, level: %d\n", getpid(), getppid(), level);
		} else {
			wait(NULL);
		}
	}

	return 0;
}

