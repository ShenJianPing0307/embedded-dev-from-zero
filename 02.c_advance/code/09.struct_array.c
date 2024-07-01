#include <stdio.h>

#define N 20

struct student {
    int no;
    char name[N];
    float score;
}s2[5];

int main() {

    int i;
    struct student s1[5] = {{1, "s1", 85}, {2, "s2", 90}};

    printf("%d-%s-%f\n", s1[0].no, s1[0].name, s1[0].score);

    for(int i = 0; i < sizeof(s2)/sizeof(struct student); i++) {

        printf("%d-%s-%f\n", s2[i].no, s2[i].name, s2[i].score);

    }
    return 0;

}