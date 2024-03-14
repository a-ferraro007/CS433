#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <pthread.h>

void *fib(void *args);
struct struct_args {
    int n;
    int *arr;
    pthread_mutex_t *mutex;
};