#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int info;
	struct node *left;
	struct node *right;
}node_t;

typedef struct tree
{
	node_t *root;
}tree_t;

void init(tree_t *pt)
{
	pt->root=NULL;	
}

void create_t(tree_t *pt)
{
	node_t *temp;node_t *p;node_t *q;
	int ch;
	pt->root=(node_t*)malloc(sizeof(node_t));
	pt->root->left=pt->root->right=NULL;	
	printf("Enter the root node:\n");
	scanf("%d",&pt->root->info);
	do
	{
		temp=(node_t*)malloc(sizeof(node_t));
		temp->left=temp->right=NULL;
		printf("Enter the next node:\n");
		scanf("%d",&temp->info);
		q=NULL;
		p=pt->root;
		while(p!=NULL)
		{
			q=p;
			if(temp->info<p->info)
				p=p->left;
			else
				p=p->right;	
		}
		if(temp->info<q->info)
			q->left=temp;
		else
			q->right=temp;
		printf("Do you want to continue?:\n");
		scanf("%d",&ch);
	}while(ch);
}

void preorder(node_t *pres)
{
    if(pres->right==NULL && pres->left==NULL)
    {
        printf("%d ",pres->info);
        return;
    }
    else
    {
        printf("%d ",pres->info);
        if(pres->left!=NULL)
        {
            preorder(pres->left);
        }
        if(pres->right!=NULL)
        {
            preorder(pres->right);
        }
    }
}

node_t* del_node(node_t *r,int ele)
{
	node_t *temp;node_t *p;
	if(r==NULL) return r;
	else if(ele<r->info)
		r->left=del_node(r->left,ele);
	else if(ele>r->info)
		r->right=del_node(r->right,ele);
	else
	{
		if(r->left==NULL)
		{
			temp=r->right;
			free(r);
			return temp;
		}
		else if(r->right==NULL)
		{
			temp=r->left;
			free(r);
			return temp;
		}
		else
		{
			p=r->right;
			while(p->left!=NULL)
			{
				p=p->left;
			}
			r->info=p->info;
			r->right=del_node(r->right,p->info);
		}
	}
	return r;
}

void del(tree_t *t,int ele)
{
	t->root=del_node(t->root,ele);
}

int main()
{
	tree_t t; int ele;
	init(&t);
	create_t(&t);
	printf("Preorder display of the tree:\n");
	preorder(t.root);
	printf("\n");
	int ch=1;
	printf("Do you want to delete an element?\n");
	scanf("%d",&ch);
	while(ch!=0)
	{
	    printf("Enter the element to delete:\n");
	    scanf("%d",&ele);
	    del(&t,ele);
	    printf("Tree after deletion:\n");
	    preorder(t.root);
	    printf("\n");
	    printf("Do you want to delete an element?\n");
	    scanf("%d",&ch);
	}
	return 0;
}
