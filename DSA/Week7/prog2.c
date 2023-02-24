#define MAX 100
#include<stdio.h>

typedef struct node
{
	int info;
	int used;
}node_t;

void init(node_t *t)
{
	for(int i=0;i<MAX;++i)
	{
		t[i].used=0;
	}	
}

void create_t(node_t *t)
{	
	int ele;int i;int ch;
	printf("Enter root value:");
	scanf("%d",&t[0].info);
	t[0].used=1;
	do
	{
		printf("Enter value:");
		scanf("%d",&ele);
		i=0;		
		while(i<MAX && t[i].used)
		{
			if(ele<t[i].info)
				i=2*i+1;
			else
				i=2*i+2;
		}
		if(i>=MAX)
			printf("Reached end.\n");
		else
		{
			t[i].info=ele;
			t[i].used=1;
		}
		printf("Do u want to continue?\n");
		scanf("%d",&ch);	
	}while(ch);	
}

void inorder(node_t *t ,int i)
{
	if(t[i].used)
	{
		inorder(t,2*i+1);
		printf("%d ",t[i].info);
		inorder(t,2*i+2);
	}
}

int check(node_t *t)
{
        int i;
        for(i=0;i<t[i].used;i++)
        {
                if(t[i].info>t[2*i+1].info && t[i].info<t[2*i+2].info)
                {
                        printf("Binary Search Tree\n");
                }
                else
                {
                        printf("Binary Tree\n");
                }
        }
}

int main()
{
	node_t t[MAX];
	init(t);
	create_t(t);
	inorder(t,0);
	printf("\n");
	check(t);
	return 0;
}
