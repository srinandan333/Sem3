#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"header.h"

void init(struct pq *p)
{

	p->head=NULL;
}

void disp(struct pq *p)
{
        if(p->head == NULL)
	{
		printf("No vaccinations scheduled.\n");
	}
	else
	{
	        struct node *q=p->head;
	        printf("Vaccinations scheduled are:\n");
	        while(q!=NULL)
	        {
		        printf("Name:%s Age:%d\n",(q->c).name,(q->c).age);	
		        q=q->link;
	        }
	}
}

void enqueue(struct pq* p,struct comp* c)
{
	struct node *temp=(struct node*)malloc(sizeof(struct node));
	strcpy(temp->c.name,c->name);
	temp->c.age=c->age;
	temp->c.morb=c->morb;
	temp->link=p->head;
	p->head=temp;
}

void dequeue(struct pq* p)
{
	if(p->head == NULL)
	{
		printf("No vaccinations scheduled.\n");
	}
	else
	{
		struct node* pres = p->head;
		struct node* prev = NULL;
		struct node* prev_max = NULL;
		int priority;
		struct comp c;
		if(c.age>=65)
		{
		        priority=3;
		}
		else if(c.age>=45)
		{
		        priority=2;		        
		}
		else if(c.age>=18)
		{
		        priority=1;		        
		}
		if(c.morb==1)
		{
		        priority= priority+1;
		}
		while(pres != NULL)
		{
		        int max=0;
			if(priority>=max)
			{
				max = pres->c.age;
				prev_max = prev;
			}
			prev = pres;
			pres = pres->link;
		}
		struct comp ct;
		if(prev_max != NULL)
		{
			struct node* temp = prev_max->link;
			prev_max->link = temp->link;
			strcpy(ct.name,temp->c.name);
			ct.age = temp->c.age;
			ct.morb = temp->c.morb;
			free(temp);
			temp=NULL;
		}
		else
		{
			struct node* temp = p->head;
			p->head = p->head->link;
			strcpy(ct.name,temp->c.name);
			ct.age = temp->c.age;
			ct.morb = temp->c.morb;
			free(temp);
			temp=NULL;	
		}
		printf("Vaccinated person name is %s and age is %d \n",ct.name,ct.age);
	}
}




















