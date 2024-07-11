typedef int data_t;
#define N 128

typedef struct {
    data_t data[N];
    int last;
}sqlist, *sqlink;

sqlink list_creat();
int list_clear(sqlink L);
int list_free(sqlist L);
int list_empty(sqlink);
int list_length(sqlink L);
int list_locate(sqlink L, data_t value);
int list_insert(sqlink L, data_t value, int pos);
