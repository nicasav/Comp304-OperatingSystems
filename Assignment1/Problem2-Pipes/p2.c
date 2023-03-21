#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/time.h>

int main(int argc, char *argv[]) {
    int NUM_CHILDREN = atoi(argv[1]);
    int fd[NUM_CHILDREN][2];
    pid_t pid[NUM_CHILDREN];
    struct timeval start_time, end_time;
    char start_time_str[100], end_time_str[100];
    char *cmd_args[argc-1];
    double max = 0.0, min = 1e9, sum = 0, avg;
    for (int i = 2; i < argc; i++) {
        cmd_args[i-2] = argv[i];
    }
    cmd_args[argc-2] = NULL;

    // create pipes for each child process
    for (int i = 0; i < NUM_CHILDREN; i++) {
        if (pipe(fd[i]) < 0) {
            printf("Pipe could not be created");
            return 1;
        }
    }

    // create child processes
    for (int i = 0; i < NUM_CHILDREN; i++) {
        pid[i] = fork();
        if (pid[i] == 0) {
            // child process
            close(fd[i][0]); // close read end of pipe

            gettimeofday(&start_time, NULL);
            write(fd[i][1], &start_time, sizeof(start_time));

            // sleep for a random time between 1 and 5 seconds
            execv(cmd_args[0], cmd_args);

            gettimeofday(&end_time, NULL);
            write(fd[i][1], &end_time, sizeof(end_time));

            close(fd[i][1]); // close write end of pipe
            exit(0); // exit child process
        }
    }

    // parent process
    for (int i = 0; i < NUM_CHILDREN; i++) {
        close(fd[i][1]); // close write end of pipe

        read(fd[i][0], &start_time, sizeof(start_time));
        read(fd[i][0], &end_time, sizeof(end_time));

        double start_time_d = (double) start_time.tv_sec + (double) start_time.tv_usec / 1000000.0;
        double end_time_d = (double) end_time.tv_sec + (double) end_time.tv_usec / 1000000.0;
        double runtime = (end_time_d - start_time_d) * 1000.0;
        if (runtime > max){
          max = runtime;
        }
        if (runtime < min) {
          min = runtime;
        }
        sum += runtime;

        printf("Child %d Executed in %.2f millis\n", i+1, runtime);
        

        close(fd[i][0]); // close read end of pipe
    }
    avg = sum / NUM_CHILDREN;
    printf("Max: %.2f millis\n", max);
    printf("Min: %.2f millis\n", min);
    printf("Average: %.2f millis\n", avg);

    return 0;
}
