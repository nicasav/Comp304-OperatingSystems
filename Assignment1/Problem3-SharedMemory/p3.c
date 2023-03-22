#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    int n = atoi(argv[2]);
    int x = atoi(argv[1]);
    int sequence[1000];
    int i, j;

    for (i = 0; i < 1000; i++) {
        if (scanf("%d", &sequence[i]) != 1) {
            break;
        }
    }

    int chunk_size = i / n;
    int extras = i % n;

    int child_status[n];
    pid_t child_pid[n];

    for (i = 0; i < n; i++) {
        pid_t pid = fork();
        if (pid == 0) {
            int start = i * chunk_size;
            int end = start + chunk_size;
            if (i == n - 1) {
                end += extras;
            }

            for (j = start; j < end; j++) {
                if (sequence[j] == x) {
                    printf("%d\n", j);
                    exit(0);
                }
            }
            exit(1);
        } else if (pid > 0) {
        child_pid[i] = pid;
        } else {
            printf("Fork failed\n");
        }
    }
    int found = 0;
    while (1) {
        for (i = 0; i < n; i++) {
            if (child_pid[i] > 0 && waitpid(child_pid[i], &child_status[i], WNOHANG) > 0) {
                if (WIFEXITED(child_status[i]) && WEXITSTATUS(child_status[i]) == 0) {
                    for (j = 0; j < n; j++) {
                        if (child_pid[j] > 0 && child_pid[j] != child_pid[i]) {
                            kill(child_pid[j], SIGKILL);
                            child_pid[j] = 0;
                        }
                    }
                    found = 1;
                    break;
                }
                child_pid[i] = 0;
            }
        }

        if (found) {
            break;
        }
    }

    return 0;
}
