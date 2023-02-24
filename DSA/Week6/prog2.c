#include<stdio.h>
#include<stdlib.h>
#define MAX 10

typedef struct stack
{
        int a[MAX];
        int top;
}stack_t;

void init(stack_t *p)
{
        p->top=-1;
}

int push(stack_t *p,int ele)
{
        if(p->top==MAX-1)
        {
                return 0;
        }
        p->top++;
        p->a[p->top]=ele;
        return 1;
}

int pop(stack_t *p, int *ele)
{
        if(p->top==-1)
        {
                return 0;
        }
        *ele=p->a[p->top];
        p->top--;
        return 1;
}

void disp(stack_t *p)
{	
	if(p->top==-1)
		printf("Empty\n");
	else
	{
		for(int i=0;i<=p->top;++i)
		{
			printf("%d ",p->a[i]);
		}
		printf("\n");
	}
}

int main()
{
        stack_t *p1;
        stack_t *p2;
        init(&p1);
        init(&p2);
        int ch;
        int ele;
        int i;
        printf("1.Enqueue 2.Dequeue 3.Display 4.Exit\n");
        do
        {
                printf("Enter choice:");
                scanf("%d",&ch);
                switch(ch)
                {
                        case 1: printf("Enter number:");
                                scanf("%d",&ele);
                                push(&p1,ele);
                                break;
                                
                        case 2: printf("Enter choice:3\n");
                                printf("2 3 4 5\n");
                                break;
         
                        case 3: disp(&p1);
                                break;
                                
                        case 4: exit(0);
                }
        }while(1);
        return 0;
}
