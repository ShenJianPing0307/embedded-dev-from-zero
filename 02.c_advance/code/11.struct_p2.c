#include <stdio.h>

#define N 20

struct student {
    int no;
    char name[N];
    float score;
};

void printf_info(struct student *p, int n) {

    int i;
    for(i = 0; i < n; i++) {
        printf("%d-%s-%f\n", (p+i)->no, (p+i)->name, (p+i)->score);
    }

}

int main(int argc, const char *argv[]) {
    int i;

    struct student s1[] = {{1, "s1", 85}, {2, "s2", 90}};
    printf_info(s1, sizeof(s1)/sizeof(struct student));

    return 0;
}