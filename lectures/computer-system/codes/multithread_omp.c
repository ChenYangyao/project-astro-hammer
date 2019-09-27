#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main(int argc, char const *argv[]){
    if( argc < 3 ){
        printf("Usage:\n\t ./multithread_omp.out nloop nthread\n");
        exit(1);
    }
    int nloop = atoi(argv[1]), nthread = atoi(argv[2]);
    long total = 0;

    /* create `nthread` threads, each shares some work from the first `for` loop */
    #pragma omp parallel default(none) shared(nloop, total) \
        num_threads(nthread)
    {
        long total_private = 0;

        /* work-sharing */
        #pragma omp for
        for (int i = 1; i <= nloop; i++){
            for (int j = 1; j <= i; j++){
                total_private += j;
            }
        }

        /* reduce to the total sum */
        #pragma omp critical
        {
            printf("thread %d got %ld\n", omp_get_thread_num(), total_private);
            total += total_private;
        }
    }

    printf("sum over all threads gives %ld\n", total);

    return 0;
}
