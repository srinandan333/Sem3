#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node
{
        char srn[15];
        struct node* l;
        struct node* r;
}node_t;

typedef struct tree
{
        node_t* root;
}tree_t;

void init(tree_t* p)
{
        p->root=NULL;
}

void display(tree_t *p);
void inorder(node_t* pt);
void find(node_t *pt, char key[]);

node_t* create(tree_t* p)
{
        p->root=(node_t*)malloc(sizeof(node_t));
        p->root->l=NULL;
        p->root->r=NULL;
        node_t* temp;
        node_t* a;
        node_t* b;
        int N,i,j;
        printf("Enter number of elements:");
        scanf("%d",&N);
        printf("Enter root node srn:");
        scanf("%s",p->root->srn);
        while(N>1)
        {
                temp=(node_t*)malloc(sizeof(node_t));
                temp->l=temp->r=NULL;
                printf("Enter srn:");
                scanf("%s",temp->srn);
                b=NULL;
                a=p->root;
                while(a!=NULL)
                {
                        b=a;
                        if(strcmp(temp->srn,p->root->srn)<0)
                        {
                                a=a->l;
                        }
                        else
                        {
                                a=a->r;
                        }
                        if(strcmp(temp->srn,b->srn)<0)
                        {
                                b->l=temp;
                        }
                        else
                        {
                                b->r=temp;
                        }
                }
                N--;
        }
        return p->root;
}

void display(tree_t *p)
{
        inorder(p->root);
        printf("\n");
}

void inorder(node_t* pt)
{
        if(pt!=NULL)
        {
                inorder(pt->l);
                printf("%s ",pt->srn);
                inorder(pt->r);
        }
}

void find(node_t *pt, char key[])
{
        if(pt != NULL)
        {
                find(pt->l, key);
                if(strcmp(pt->srn, key) == 1)
                {
                        printf("Found\n");
                }
                find(pt->r, key);
        }
}

int main()
{
        tree_t p;
        char ele[20];
        init(&p);
        node_t *pt=create(&p); 
        display(&p);       
        printf("Enter the srn to be searched:");
        scanf("%s",ele);
        find(pt,ele);
        return 0;
}


