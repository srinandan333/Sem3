 #include<stdio.h> 
 #include<stdlib.h> 
 #include"header.h"

void  add_pol(list_t  *res,list_t  *p1,list_t  *p2)
{
    node_t  *temp1  =  p1->head,*temp2  =  p2->head,*temp_res  =  res->head,*var;
    int  k  =  0;
    while(temp1!=NULL)
    {
        while(temp2!=NULL)
        {
            if((temp1->powx  ==  temp2->powx)  &&  (temp1->powy  ==  temp2->powy))
            {
                temp_res->coeff  =  (temp1->coeff)+(temp2->coeff);
                temp_res->powx  =  temp1->powx;
                temp_res->powy  =  temp1->powy; var  =  temp_res;
                temp_res->next  =  malloc(sizeof(node_t)); 
                temp_res  =  temp_res->next;
                k  =  1;
            }
            temp2  =  temp2->next;
        }
        if(k  ==  0)
        {
            temp_res->coeff  =  temp1->coeff; 
            temp_res->powx  =  temp1->powx; 
            temp_res->powy  =  temp1->powy; 
            var  =  temp_res;
            temp_res->next  =  malloc(sizeof(node_t)); 
            temp_res  =  temp_res->next;
            k  =  0;
        }
        temp2  =  p2->head; 
        temp1  =  temp1->next;
    }
    var->next  =  NULL;
    }




void  disp(list_t  *a)
{
    node_t  *p=a->head; 
    while(p!=NULL)
    {
        printf("%dx^%dy^%d\n",p->coeff,p->powx,p->powy); 
        p  =  p->next;
    }
}
