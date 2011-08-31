#include<stdio.h>

int main()
{
    int pid;
    int info[2];
    pipe(info);
    pid=fork();
    if(pid==0) {
        printf("Child process begins writing to parent process...\n");
        write(info[1],"Child to parent",15);
    }
    else {
        char arr[60];
        printf("Parent receiving...\n");
        read(info[0],arr,60);
        printf("The parent got from the child:\n\t%s\n",arr);
    }
    return 0;
}
         
