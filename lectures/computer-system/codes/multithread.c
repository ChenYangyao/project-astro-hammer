#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int glob = 0;

void * do_task( void * task ){
    int loops = (int)task, loc;
    for (int i = 0; i < loops; i++){
        loc = glob;
        ++loc;
        glob = loc;
    }
    return NULL;
}


int main(int argc, char const *argv[]){
    if( argc < 2 ){
        printf("Usage:\n\t./multithread.out nloop\n");
        exit(1);
    }
    int task = atoi( argv[1] );
    printf("Do %d loops\n", task);
    
    /* create 1 extra thread, running the function do_task( (void *)task ) */
    pthread_t tid;    
    int s = pthread_create( &tid, NULL, do_task, (void *)task );
    if( s != 0 ){
        printf("pthread_create\n"); exit(1);
    }

    /* also run the function do_task( (void *)task ) on the main thread */
    do_task( (void *)task );

    /* wait extra thread to terminate, release its resource */
    s = pthread_join( tid, NULL );
    if( s != 0 ){
        printf("pthread_join\n"); exit(1);
    }

    printf("Now glob = %d\n", glob);

    return 0;
}
