#include<stdio.h>
#include<stdlib.h>
#include"header.h"
#include<string.h>

void init(list *p)
{
	p->head=NULL;
	p->tail=NULL;
}

void display(list *p)
{
	node *pres=p->head;
	if(pres==NULL)
	{
		printf("No elements to display\n");
	}else{
		while(pres!=NULL)
		{
			printf("Name: %s\n",pres->name);
			printf("Phone Number: %s\n",pres->ph_no);
			printf("Address :%s\n",pres->address);
			printf("Area: %s\n\n",pres->area);
			pres=pres->next;
		}
	}
}

node* create(char name[20],char ph_no[20],char address[50],char area[10])
{
	node *temp=(node *)malloc(sizeof(node));
	strcpy(temp->name,name);
	strcpy(temp->address,address);
	strcpy(temp->area,area);
	strcpy(temp->ph_no,ph_no);
	temp->prev=NULL;
	temp->next=NULL;
	return temp;
}

void dinit(list *p)
{
	node *pres=p->head;
	while(pres!=NULL)
	{
		p->head=pres->next;
		free(pres);
		pres=p->head;
	}
	p->head=NULL;
}

void ordered_insert(list *p,char name[20],char ph_no[20],char address[50],char area[10])
{
       node *temp=create(name,ph_no,address,area);
        if(p->head==NULL)
        {
                printf("\nNo elements to arrange\n");
                p->head=temp;
                p->tail=temp;
        }
        else
        {
                node *pres=p->head;
                node *prev=NULL;
                while(pres!=NULL && strcmp(pres->name,temp->name)<0 )
                {
                        prev=pres;
                        pres=pres->next;
                        
                }
                if(pres==p->head)
                {
                        temp->next=pres;
                        pres->prev=temp;
                        p->head=temp;
                }else if(pres==NULL)
                {
                        prev->next=temp;
                        temp->prev=prev;
                        temp->next=NULL;            
                }
                else
                {
                temp->prev=prev;
                temp->next=pres;
                prev->next=temp;
                pres->prev=temp;
                }
        }
}
