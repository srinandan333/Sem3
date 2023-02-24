#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
        int key;
        struct node *link;
}node_t;

typedef struct queue
{
        node_t *front;
        node_t *rear;
}queue_t;

void init(queue_t *p)
{
        p->front=NULL;
        p->rear=NULL;
}   

node_t* create_node(int key)
{
        node_t *temp=(node_t*)malloc(sizeof(node_t));
        temp->key=key;
        temp->link=NULL;
        return temp;
}

void enqueue(queue_t *p,int key)
{
        node_t *temp=create_node(key);
        if(p->front==NULL)
        {
                p->front=p->rear=temp;
                temp->link=temp;
        }
        else
        {
                p->rear->link=temp;
                p->rear=temp;
                temp->link=p->front;
        }
}

int dequeue(queue_t *p, int k)
{
        node_t *pres;
        node_t *prev;
        int i;
        if(p->front==NULL)
        {
                printf("Empty\n");
        }
        else
        {
                pres=p->front;
                prev=NULL;
                while(pres->link!=pres)
                {
                        i=0;
                        while(i<k-1)
                        {
                                prev=pres;
                                pres=pres->link;
                                ++i;
                        }
                        prev->link=pres->link;
                        printf("Killed:%d\n",pres->key);
                        free(pres);
                        pres=prev->link;
                }
                p->front=pres;
                p->rear=pres;
                return pres->key;
        }
}

void disp(queue_t *p)
{

	node_t *temp;
	if(p->front==NULL)
	{
		printf("Empty\n");
	}
	else
	{
		temp=p->front;
		while(temp->link!=p->front)
		{
			printf("%d\n",temp->key);
			temp=temp->link;
		}
		printf("%d\n",temp->key);
		printf("\n");
	}
}

int main()
{
	queue_t q;
	init(&q);
	int n;
        printf("Enter value of n and k:\n");
	scanf("%d",&n);
	int k;
	scanf("%d",&k);
	for(int i=1;i<=n;++i)
	{
		enqueue(&q,i);
	}
	printf("Survivor:%d\n",dequeue(&q,k));
	return 0;
}
		