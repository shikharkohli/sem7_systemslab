#include<stdio.h>
#include<signal.h>
//#include<unistd.h>
#include<stdlib.h>
#include<errno.h>

void sigint_handler(int signal)
{
    printf("\b\b SIGINT received, signal value is %d\n",signal);
}

void sigsegv_handler(int signal)
{
    printf("SIGSEGV received but program execution continued, signal value is %d\n",signal);
}

void sigabrt_handler(int signal)
{
    printf("No! I will not abort %d,\n",signal);
}

void check()
{
    int arr[10];
    arr[10];
}

int main()
{
    printf("The process id is %d\n",getpid());
    struct sigaction sa;
    struct sigaction sv;
    struct sigaction ssigabrt;
    ssigabrt.sa_handler = sigabrt_handler;
    ssigabrt.sa_flags = SA_RESTART;
    sv.sa_handler = sigsegv_handler;
    sv.sa_flags = SA_RESTART;
    sa.sa_handler = sigint_handler;
    sa.sa_flags = SA_RESTART;
    sigemptyset(&sa.sa_mask);
    sigaction(SIGINT,&sa,NULL);
    sigaction(SIGSEGV,&sv,NULL);
    check();
    char ch = getchar();
    printf("%c\n",ch);
    return 0;
}
