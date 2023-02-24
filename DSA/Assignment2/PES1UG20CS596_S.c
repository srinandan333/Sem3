#include<stdio.h>
#include<stdlib.h>
#include"PES1UG20CS596_H.h"

void push(node_t * stack_t[],node_t *p, int *top)
{
    (*top)++;
    stack_t[*top]=p;
}

node_t* pop(node_t *stack_t[], int* top)
{
    node_t *p=stack_t[*top];
    (*top)--;
    return p;
}

void enqueue(node_t* q[],node_t *p, int * rear)
{
    (*rear)++;
    q[(*rear)]=p;
}

node_t * dequeue(node_t* q[], int * rear)
{
    node_t *p=q[0];
    for(int i=0;i<=(*rear)-1;i++)
    {
        q[i]=q[i+1];
    }
    (*rear)--;
    return p;
}

void insert(graph_t *g, int i, int j)
{
    node_t *p;
    p=g->arr[i].head;
    node_t *q= malloc(sizeof(node_t));
    q->ver=g->arr[j].head;
    q->row=g->arr[j].head->row;
    q->col=g->arr[j].head->col;
    q->id=g->arr[j].head->id;
    q->link=NULL;
    node_t *r;
    r=NULL;
    if(p->link==NULL)
    {
        p->link=q;
    }
    else
    {
        r=p;
        p=p->link;
        r->link=q;
        q->link=p;
    }
}

node_t *read(int *i0,int *j0,int *ifi, int *jf, graph_t *g, int *count)
{
    FILE *fp;
    int i1,j1,i2,j2;
    fp=fopen("input.txt","r");
    fscanf(fp,"%d %d", &i1, &j1);
    fscanf(fp,"%d %d", &i2, &j2);
    *i0=i1;
    *j0=j1;
    *ifi=i2;
    *jf=j2;
    int id=0;
    for(int i=i1;i<=i2;i++)
    {
        for(int j=j1;j<=j2;j++)
        {
            int a;
            fscanf(fp,"%d",&a);
            if(a==0)
            {
                (*count)+=1;
            }
        }
    }
    g->v=(*count);
    g->arr= malloc((*count) * (sizeof(list_t)));
    for (int i=0; i<(*count);i++)
    {
        g->arr[i].head=NULL;
    }
    fclose(fp);
    int a,b,c,d;
    fp=fopen("input.txt","r");
    fscanf(fp,"%d %d %d %d",&a,&b,&c,&d);
    for(int i=i1;i<=i2;i++)
    {
        for(int j=j1;j<=j2;j++)
        {
            int a;
            fscanf(fp,"%d",&a);
            if(a==0)
            {
                id+=1;
                node_t *p=malloc(sizeof(node_t));
                p->id=id;
                p->row=i;
                p->col=j;
                p->link=NULL;
                g->arr[id-1].head=p;
                p->ver=g->arr[id-1].head;
            }
        }
    }
    fclose(fp);
}

void finddfs( graph_t *g, int count)
{
    node_t * stack_t[100];
    int path[count];
    int top=-1;
    node_t *q;
    push(stack_t,g->arr[0].head, &(top));
    int z=0;
    node_t * a= g->arr[0].head;
    while(top!=-1 && a->id!=g->arr[count-1].head->id)
    {
        a=pop(stack_t,&top);
        a=a->ver;
        if((!(a->link==NULL))||(a->id==count))
        {
            path[z]=a->id;
        }
        else
        {
            z-=1;
            q=a->link;
        }
        while(q!=NULL)
        {
            push(stack_t, q->ver, &(top));
            q=q->link;
        }
        z+=1;
    }
    storedfs(g,path, z, count);
}

void findbfs(graph_t *g, int count)
{
    node_t * q1[100];
    int visited[count];
    for(int i=0;i<count;i++)
    {
        visited[i]=0;
    }
    int prev[count];
    int rear=-1;
    enqueue(q1,g->arr[0].head,&(rear));
    node_t * a= g->arr[0].head;
    visited[a->id -1]=1;
    while(rear!=-1 && visited[55]!=1)
    {
        node_t * a= dequeue(q1, &(rear));
        node_t *p = a;
        while(p->link!=NULL)
        {
            node_t * q=p->link;
            enqueue(q1,q->ver,&(rear));
            if(visited[q->id-1]==0)
            {
                prev[q->id -1]=a->id;
            }
            visited[q->id -1]=1;
            p=q;
        }
    }
    int j=count;
    int y=1;
    int path[count];
    path[0]=j;
    while(j>1)
    {
        j=prev[j-1];
        path[y]=j;
        y++;
    }
    storebfs(g,path,y, count);
}

void storedfs(graph_t *g, int path[], int z, int count)
{
    FILE *f;
    if(path[z-1]==count)
    {
        f=fopen("dfs.txt", "w");
        for(int i=0;i<z;i++)
        {
            int a=path[i]-1;
            fprintf(f,"%d %d\n",g->arr[a].head->row,g->arr[a].head->col);
            fprintf(f, "\n");
        }
        fclose(f);
        }
    else
    {
        f=fopen("dfs.txt", "w");
        fprintf(f,"-1");
        fclose(f);
    }
}

void storebfs(graph_t *g, int path[], int y, int count)
{
    FILE *f;
    if(path[0]==count && path[y-1]==1)
    {
        f=fopen("bfs.txt", "w");
        for(int i=y-1;i>=0;i--)
        {
            int a=path[i]-1;
            fprintf(f,"%d %d\n",g->arr[a].head->row,g->arr[a].head->col);
            fprintf(f, "\n");
        }
        fclose(f);
    }
    else
    {
        f=fopen("dfs.txt", "w");
        fprintf(f,"-1");
        fclose(f);
    }
}

