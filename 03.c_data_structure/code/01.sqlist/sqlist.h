typedef int data_t;
#define N 128

typedef struct {
    data_t data[N];
    int last;
}sqlist, *sqlink;

sqlink list_creat();
