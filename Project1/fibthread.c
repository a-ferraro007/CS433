#include "fibthread.h"

int main(int argc, char *argv[])
{
    int input;
    printf("Enter an integer: ");
    scanf("%d", &input);
    printf("Calculating Fibonnaci for: %d \n", input);

    pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
    struct struct_args thread_args = {input, (int *)malloc(input * sizeof(int)), &mutex};
    pthread_t thread;

    pthread_create(&thread, NULL, fib, (void *)&thread_args);
    pthread_join(thread, NULL);

    printf("total is: %d \n", thread_args.arr[input]);
    pthread_mutex_destroy(&mutex);
    return 0;
};

void *fib(void *args)
{
    struct struct_args *thread_args = (struct struct_args *)args;
    int n = thread_args->n;
    if (n == 0 || n == 1)
    {
        pthread_mutex_lock(thread_args->mutex);
        thread_args->arr[n] = n;
        pthread_mutex_unlock(thread_args->mutex);
    }
    else
    {
        pthread_t thread_id1;
        pthread_t thread_id2;
        struct struct_args thread_args1 = {n - 1, thread_args->arr, thread_args->mutex};
        struct struct_args thread_args2 = {n - 2, thread_args->arr, thread_args->mutex};

        pthread_create(&thread_id1, NULL, fib, (void *)&thread_args1);
        pthread_create(&thread_id2, NULL, fib, (void *)&thread_args2);
        pthread_join(thread_id1, NULL);
        pthread_join(thread_id2, NULL);

        pthread_mutex_lock(thread_args->mutex);
        thread_args->arr[n] = thread_args1.arr[n - 1] + thread_args2.arr[n - 2];
        pthread_mutex_unlock(thread_args->mutex);
    }
    pthread_exit(0);
}
