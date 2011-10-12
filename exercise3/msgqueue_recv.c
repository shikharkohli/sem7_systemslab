#include<stdio.h>
#include<sys/msg.h>
#include<stddef.h>

struct student_msgbuf {
    long mtype;
    struct student_info {
        char name[30];
        char stud_type;
        int age;
        int marks;
    } info;
};

typedef struct student_msgbuf student_msgbuf;

int main()
{
    key_t key;
    student_msgbuf recv;
    key = ftok("/home/labwork/Desktop/msgq",'S');
    int msgqid = msgget(key, 0666 | IPC_CREAT);
    printf("Receiving message...\n");
    msgrcv(msgqid, &recv, sizeof(recv) - sizeof(long),2,0);
    printf("Name : %s\n Type : %c\n Age : %d\nMarks : %d\n",recv.info.name,recv.info.stud_type,recv.info.age,recv.info.marks);
    return 0;
}
