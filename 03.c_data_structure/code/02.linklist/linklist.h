typedef int data_t;

typedef struct node {
    data_t data;
    struct node * next;
} listnode, * linklist;

linklist list_create();
int list_tail_insert(linklist H, data_t value);
linklist list_get(linklist H, int pos);
int list_insert(linklist H, data_t value, int pos);
int list_delete(linklist H, int pos);
int list_show(linklist H);
linklist list_free(linklist H);
int list_reverse(linklist H);
linklist list_adjmax(linklist H, data_t *value);