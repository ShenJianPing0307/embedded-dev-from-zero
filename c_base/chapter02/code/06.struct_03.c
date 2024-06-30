#include <stdio.h>
#include <string.h>
#define N 32

struct student {

    int no;
    char name[N];
    float score;

}s3={3, "zhangsan", 90}, s4={4, "lisi", 80};

int main(int argc, char *argv[]) {

    struct student s1, s2;
    strcpy(s1.name, "xiaoming"); // 通过 strcpy 给变量赋值
    s1.score = 90; // 给分数赋值
    s1.name[0] = 'k'; //修改名称中的第一个字符
    printf("%d %s %2.f\n", s1.no, s1.name, s1.score); // -1209245696 kiaoming 90

    s2 = s1;
    s2.no = 2;
    printf("%d %s %2.f\n", s2.no, s2.name, s2.score); // 2 kiaoming 90

}