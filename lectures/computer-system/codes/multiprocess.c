#include <sys/types.h>      /* pid_t */
#include <stdio.h>          /* printf() */
#include <stdlib.h>         /* exit() */
#include <unistd.h>         /* fork() */
#include <sys/wait.h>       /* wait() */

int do_task( int n ){
    int total = 0;
    for (int i = 0; i < n; i++){
        total += i;
    }
    return total;
}

int main(int argc, char const *argv[]){
    int task_parent = 10, task_child = 5;

    printf("parent (PID=%ld) begins\n", (long)getpid() );
    
    /* create child process */
    pid_t pid = fork();         
    if( pid == -1 ){
        printf("ERROR: fork\n"); exit(1);
    }else if( pid == 0 ){
        /* child process does... */
        printf("child (PID=%ld) got %d\n", (long)getpid(), do_task( task_child ));
        exit(0);
    }else{
        /* parent process does... */
        if( wait(NULL) == -1 ){
            printf("ERROR: wait\n"); exit(1);
        }
        printf("parent (PID=%ld) got %d\n", (long)getpid(), do_task(task_parent));
    }
    return 0;
}

