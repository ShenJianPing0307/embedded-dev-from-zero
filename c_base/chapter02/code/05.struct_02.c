#include <stdio.h>

#define WORKER struct worker // WORKER与struct worker完全等效

WORKER
{
    long number;
    char name[20];
    char sex;
    int age;
    float salary;
    char address[80];
};

int main(int argc, char *argv[]) {

    WORKER worker1;

    printf("%d\n",sizeof(worker1));

}