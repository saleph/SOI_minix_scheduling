#include <stdio.h>
#include <stdlib.h>
#include <lib.h>


#define GROUP_A 0
#define GROUP_B 1
#define GROUP_C 2

#define GRTOCHAR(g) (g==GROUP_A ? 'A' : (g==GROUP_B ? 'B' : 'C'))
#define CHARTOGR(c) (c=='A' ? GROUP_A : (c=='B' ? GROUP_B : GROUP_C))

void settime(int group, int time){
    message m;
    printf("GROUP: %c TIME: %d \n", GRTOCHAR(group), time);

    m.m1_i2 = group;
    m.m1_i3 = time;

    _syscall(MM, SETQUANTUM, &m);
}

int gettime(int group) {
    message m;
    m.m1_i2 = group;

    return _syscall(MM, GETQUANTUM, &m);
}

int main(void){

    int groupValue = 0;
    char gr;
    int time = 0;

    printf("Enter group {A, B, C}: ");
    scanf("%c", &gr);
    groupValue = CHARTOGR(gr);
    printf("\n");
    printf("Enter new time: ");
    scanf("%d", &time);
    printf("\n");

    printf("Current time: %d \n", gettime(groupValue));
    settime(groupValue, time);
    printf("New time: %d \n", gettime(groupValue));

    return 0;
}
