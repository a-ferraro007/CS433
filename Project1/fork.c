#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int getProcessIds() {
    printf("Parent process id: %d\nChild process id: %d\n", getppid(), getpid());
    return 0;
};

int handleFork() {
    pid_t p;
    p = fork();

    if(p < 0) {
        printf("Error calling fork()");
        exit(1);
    }

    if(p == 0) {
        getProcessIds();
    }

    return 0;
};


int main() {
    handleFork();
    sleep(60);
    return 0;
};