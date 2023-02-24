#include<stdio.h>
#include<stdlib.h>
#define MAX 5

typedef struct queue
{
	int a[MAX];
	int front;
	int rear;
}queue_t;

void init(queue_t *p)
{
	p->front=0;
	p->rear=-1;	
}

int isEmpty(queue_t *p)
{
	return p->front>p->rear;
}

int isFull(queue_t *p)
{
	return p->rear==MAX-1;
}

void enqueue(queue_t *p,int ele)
{
	if(isFull(p))
	{
		printf("Queue is full\n");
	}
	else
	{
		p->rear++;
		p->a[p->rear]=ele;
	}
}

int dequeue(queue_t  *p)
{
	if(isEmpty(p))
	{
		printf("Queue is empty\n");
	}
	else
	{
		return p->a[p->front++];
	}
}

void disp(queue_t *p)
{
	if(isEmpty(p))
		return;
	else
	{
	        printf("Queue:");
		for(int i=p->front;i<=p->rear;++i)
		{
			printf("%d ",p->a[i]);
		}
	}
	printf("\n");		
}

int main()
{
	queue_t p;
	init(&p);
	int ele;
	int ch;	
	printf("1:Enqueue\t2:Dequeue\t3:Isempty\t4:Isfull\t5:Display\t6.Exit\n");
	while(1)
	{
		printf("Enter choice:\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: printf("Enter element:\n");
				scanf("%d",&ele);
				enqueue(&p,ele);
				break;
			case 2: printf("Deleted element is:%d\n",dequeue(&p));
				break;
			case 3: if(isEmpty(&p))
					printf("Queue is empty.\n");
				else
					printf("Queue is not empty.\n");	
				break;
			case 4: if(isFull(&p))
					printf("Queue is full.\n");
				else
					printf("Queue is not full.\n");
				break;
			case 5:disp(&p);
				break;	
			case 6:exit(0);
		}
	}
	return 0;
}








