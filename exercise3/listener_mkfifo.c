//Listener process for mkfifo
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<fcntl.h>
#include<sys/stat.h>

int main()
{
    char s[80];
    int num, fd;
    mknod("myfifo", S_IFIFO | 0666, 0);
    printf("Wait for a speaker...\n");
    fd = open("myfifo",O_RDONLY);
    printf("Got a speaker!\n");
    do {
        if((num = read(fd, s, 300)) == -1)
            printf("read");
        else {
            s[num] = '\0';
            printf("listen : read %d bytes: \"%s\"\n",num, s);
        }
    } while (num>0);
    return 0;
}
