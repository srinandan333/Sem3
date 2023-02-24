#include<stdio.h>
#include<stdlib.h>
#include"PES1UG20CS596_H.h"

int main()
{
    int count=0;
    int i1,j1,i2,j2;
    graph_t g1;
    read(&i1,&j1,&i2,&j2, &g1,&(count));
    for(int i=0;i<count;i++)
    {
        for(int j=i;j<count;j++)
        {
            if(((g1.arr[j].head->row==g1.arr[i].head->row) &&(g1.arr[j].head->col==g1.arr[i].head->col + 1))|| ((g1.arr[j].head->row==g1.arr[i].head->row+1)&& (g1.arr[j].head->col==g1.arr[i].head->col)))
            {
            insert(&g1,i,j);
            }
        }
    }
    printf("Adjacency List : \n");
    for(int i=0;i<count;i++)
    {
        node_t *p;
        p=g1.arr[i].head;
        printf("%d",p->id);
        p=p->link;
        while(p!=NULL)
        {
            printf("->%d ",p->id);
            p=p->link;
        }
        printf("\n");
    }
    graph_t g2=g1;
    finddfs(&g1, count);
    printf("\n\n");
    findbfs(&g2, count);
    return 0;
}   
