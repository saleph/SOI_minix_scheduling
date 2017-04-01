#include <stdio.h>
#include <stdlib.h>
#include <lib.h>
#include <unistd.h>
#include <limits.h>


typedef enum group {
    GROUP_A = 2,
    GROUP_B,
    GROUP_C
} group;

#define GRTOCHAR(g) (g==2 ? 'A' : (g==1 ? 'B' : 'C'))
#define CHARTOGR(c) (c=='A' ? 2 : (c=='B' ? 3 : 4))

int getgroup(int pid);
void setgroup(int pid, int group);

int getgroup(int pid){
    message m;
    m.m1_i1 = pid;
    printf("PID: %d \n", pid);
    return _syscall(MM, GETGROUP, &m);
}

void setgroup(int pid, int group){
    message m;
    m.m1_i1 = pid;
    m.m1_i2 = group;
    _syscall(MM, SETGROUP, &m);
}

int main(int argc, char* argv[]){

    pid_t pid = getpid();

    char gr;
    int groupval;

    int i = 1;

    if (argc != 2){
        printf("Invalid arguments: %s \n", argv[0]);
        return 0;
    }

    groupval = getgroup(pid);

    printf("Process pid (%d) group: %c \n", pid, GRTOCHAR(groupval));

    gr = argv[1][0];

    printf("NEW GROUP: %c \n", gr);

    printf("Group changed to %c \n", gr);
    setgroup(pid, CHARTOGR(gr));

    groupval = getgroup(pid);
    printf("Process pid (%d) group: %c\n", pid, GRTOCHAR(groupval));

    i = INT_MAX / 2;
    while(i < INT_MAX){
        ++i;
    }

    printf("Process pid (%d) group: %c FINISHING\n", pid, GRTOCHAR(groupval));

    return 0;
}