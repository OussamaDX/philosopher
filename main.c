# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

void* thread_function(void* arg) {
    int thread_number = *((int*)arg);
    printf("Hello from thread %d\n", thread_number);
    pthread_exit(NULL);
}

int main() {
    pthread_t thread;
    int thread_arg = 9;

    if (pthread_create(&thread, NULL, thread_function, &thread_arg) != 0) {
        fprintf(stderr, "Failed to create thread\n");
        return 1;
    }
    // Wait for the thread to finish
    pthread_join(thread, NULL);

    return 0;
}
