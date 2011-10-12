//Named FIFO that can be shared by multiple processes
#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

int main()
{
    char s[80];
    int num;
    mknod("myfifo",S_IFIFO|0644,0);
    //The fifo file is called mkfifo
    //The creation mode tells mknod to make a FIFO (S_IFIFO)
    // and the permissions, in octal are 0644
    //Macros from sys/stat.h can also be used to 
    //set access permissions
    printf("Waiting for a listening process...\n");
    int fd = open("myfifo",O_WRONLY); 
    //Blocks FIFO until another process reads the FIFO
    printf("Listener acquired...\n");
    while(gets(s),!feof(stdin)) {
        if((num = write(fd,s,strlen(s)))== -1)
            printf("Write");
        else
            printf("Speaker wrote %d bytes",num);
    }
    return 0;
}
