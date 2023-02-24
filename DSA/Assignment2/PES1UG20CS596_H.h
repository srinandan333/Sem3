typedef struct node_t
{
    int row;
    int col;
    int id;
    struct node_t *link;
    struct node_t *ver;
}node_t;

typedef struct list_t{
    node_t *head;
}list_t;

typedef struct graph_t
{
    int v;
    list_t* arr;
}graph_t;

void push(node_t * stack_t[],node_t *p, int *top);
node_t* pop(node_t *stack_t[], int* top);
void enqueue(node_t* q[],node_t *p, int * rear);
node_t * dequeue(node_t* q[], int * rear);
void insert(graph_t *g, int i, int j);
node_t *read(int *i0,int *j0,int *ifi, int *jf, graph_t *g, int *count);
void finddfs( graph_t *g, int count);
void findbfs(graph_t *g, int count);
void storedfs(graph_t *g, int path[], int z, int count);
void storebfs(graph_t *g, int path[], int y, int count);
