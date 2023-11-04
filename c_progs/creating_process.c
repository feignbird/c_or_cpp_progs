#include<sys/types.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
// print("\nprintf called outside main function ....\n");

int main(){
    pid_t pid;
    printf("Main function started\n declared PID value: %d\n", pid);
    // fork a child process or create a child process
    pid = fork();

    printf("PID of forked process: %d\n", pid);

    if (pid<0){ // Some error occurred
        fprintf(stderr, "Fork Failed\n");
        return 1;
    }
    else if (pid == 0){ // child process created with zero PID
        execlp("/bin/ls", "ls", NULL);
    }
    else { // parent process
        // parent will wait for the child to complete.
        wait(NULL);
        printf("Child Complete\n");
    }
    printf("Hello from %s\n", (pid>0?"Parent":"Child"));
    return 0;
}