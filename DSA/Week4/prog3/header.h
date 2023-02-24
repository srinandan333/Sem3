#define MAX 8
typedef struct stack
{
	int s[MAX];
	int counter[MAX];
	int temp[MAX];
	int top;
}stack_t;

void init(stack_t *ps);
int push(stack_t *ps,int e);
void pop(stack_t *ps,int *pe);
void empty(stack_t *ps);
void stackTop(stack_t *ps);
void check(stack_t *ps,int m);
void disp(stack_t *ps);