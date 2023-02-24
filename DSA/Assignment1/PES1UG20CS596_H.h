typedef struct entry
{
    int row;
    int col;
    int info;
} entry;

typedef struct node
{
    struct node *down;
    struct node *right;
    union
    {
        struct node *next;
        entry entry_t;
    } union_t;
} node_t;

int top;
void push(node_t *stack_t[], node_t *ele);
node_t *pop(node_t *stack_t[]);
node_t *read(int *x0, int *y0, int *xf, int *yf);
void store(node_t *stack_t[], int x2, int y2, int key);
void search(node_t *stack_t[], node_t *p, int x1, int y1, int x2, int y2);
