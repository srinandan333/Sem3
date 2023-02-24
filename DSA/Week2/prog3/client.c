#include<stdio.h> 
#include<stdlib.h> 
#include"header.h"

int main()
{
    list_t  poly[2]; 
    for(int  i=0;i<2;i++)
    {
        printf("Enter  the  number  of  terms :\n");
        int  n; 
        scanf("%d",&n);
        poly[i].head  =  malloc(sizeof(node_t)); 
        if(n==0)
        {
            poly[i].head  =  NULL;
        }
        if(n>0)
        {
            printf("Enter  the  co-efficient  and  the  powers  of  x  and  y:\n"); 
            scanf("%d  %d  %d",&poly[i].head->coeff,&poly[i].head->powx,&poly[i].head->powy); 
            poly[i].head->next  =  (node_t  *)malloc(sizeof(node_t));
            node_t  *q  =  poly[i].head->next;
            node_t  *p; 
            for(int  i=0;i<n-1;i++)
            {
                scanf("%d  %d  %d",&q->coeff,&q->powx,&q->powy); q->next  =  malloc(sizeof(node_t));
                p  =  q;
                q  =  q->next;
            }
            p->next  =  NULL; 
            free(q);
        }
    }
    printf("The  polynomials  are:\n"); 
    for(int  i=0;i<2;i++)
    {
        printf("polynomial  %d\n",i+1); 
        disp(&poly[i]);
    }
    list_t  res;
    res.head  =  malloc(sizeof(node_t)); 
    add_pol(&res,&poly[0],&poly[1]); 
    printf("The  resultant  polynomial  is:\n");
    disp(&res);
}




