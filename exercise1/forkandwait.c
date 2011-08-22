#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<errno.h>

int main()
{
    pid_t pid;
    int return_value;
    printf("Exercise 1:\n");
    pid=fork();
    if(pid==0) {
        printf("Child process executing\n");
        printf("\tChild process pid is %d \n",getpid());
        printf("\tParent of child process pid is %d\n",getppid());
        return_value=255;
        exit(return_value);
    }
    else {
        wait(&return_value);
        /* Without wait, child and parent statements get interleaved (like
           two separate threads). Wait ensures that parent process execution
           proceeds only once the child process have finished executing
        */
        printf("Parent process executing\n");
        printf("\tParent process pid is %d\n",getpid());
        printf("\tParent of parent process pid is %d\n",getppid());
        printf("\tThe child process returned the value %d\n",WEXITSTATUS(return_value));
        /* According to the man page, WEXITSTATUS returns the least significant           
           8 bits of the return value, hence it will be return correct values
           for numbers greater than 255
        */
    }
    return 0;
}
