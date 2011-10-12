#include<stdio.h>
#include<stddef.h>
#include<sys/msg.h>

struct student_msgbuf {
    long mtype;
    struct student_info {
        char name[30];
        char stud_type;
        int age;
        int marks;
    }info;
};

typedef struct student_msgbuf student_msgbuf;

int main()
{
    int key = ftok("/home/labwork/Desktop/msgq",'S');
    int msgqid = msgget(key, 0666 | IPC_CREAT);
    student_msgbuf send = {2,{"Shikhar Kohli",'U',20,20}};
    msgsnd(msgqid,&send,sizeof(student_msgbuf)-sizeof(long),0);
    printf("Sent a message\n");
    return 0;
}
