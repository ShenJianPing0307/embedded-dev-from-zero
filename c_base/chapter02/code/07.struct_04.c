#include <stdio.h>
#include <string.h>
#define N 32

struct student {

    int no;
    char name[N];
    struct birthday{
        int year;
        int month;
        int day;
    }date;
    float score;

}s3={3, "zhangsan", 90}, s4={4, "lisi", 80};

int main(int argc, char *argv[]) {

    struct student s1;
    strcpy(s1.name, "xiaoming"); // 通过 strcpy 给变量赋值
    s1.score = 90; // 给分数赋值
    s1.name[0] = 'k'; //修改名称中的第一个字符
    s1.date.year=1993;
    s1.date.month=03;
    s1.date.day=10;
    printf("%d %s %d-%d-%d %2.f\n", s1.no, s1.name, s1.date.year, s1.date.month, s1.date.day, s1.score); // -1210147384 kiaoming 1993-3-10 90

}