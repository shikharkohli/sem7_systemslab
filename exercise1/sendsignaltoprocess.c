#include<stdio.h>
#include<stdlib.h>
#include<signal.h>

int main()
{
    int process_number,signal;
    do {
        printf("Enter process number (0 to exit)\t");
        scanf("%d",&process_number);
        if(process_number==0)
            return 0;
        printf("Enter signal \t");
        scanf("%d",&signal);
        if(kill(process_number,signal)==0) {
            printf("Signal sent successfully \n");
        }
        else
            printf("Signal sending failed\n");
    }while(1);
    return 0;
}
