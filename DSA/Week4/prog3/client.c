#include<stdio.h>
#include<ctype.h>
#include"header.h"

void init(stack_t *ps)
{
	ps->top=-1;
	int i=0;
	while(i<MAX)
	{
		ps->counter[i]=0;
		ps->temp[i]=0;
		i++;
	}
}
int push(stack_t *ps,int e)
{
	if(ps->top==MAX-1) 
	{	
		return 0;
	}
	ps->top++;
	ps->s[ps->top]=e; 
	return 1;
}
void pop(stack_t *ps,int *pe)
{
	if(ps->top==-1)
 	{
		printf("Garage is empty.\n");
	}
  	*pe=ps->s[ps->top];
  	--ps->top;
  
}
void empty(stack_t *ps)
{
	ps->top==-1;
}
void stackTop(stack_t *ps)
{
	ps->s[ps->top];
}

void check(stack_t *ps,int m)
{
	int pe,z=0,j,l,w,te;int i=0;
	while(i<MAX && ps->s[i]!=m)
	{	
		i++;
	}
	if(ps->s[i]==m)
	{
		l=ps->top;
		te=ps->counter[i];
		for(int j=0;j<l-i;j++)
		{		
			pop(ps,&pe);
			printf("Car %d has been moved out.\n",pe);
			ps->temp[z]=pe;
			ps->counter[ps->top]+=1;
			z++;
		}
		pop(ps,&pe);
		printf("The car %d has departed and was popped out %d times to let the other cars depart.\n",pe,te);
		for(w=z-1;w>-1;w--)
		{		
			push(ps,ps->temp[w]);
			printf("Car %d has been moved in succesfully.\n",ps->temp[w]);
		}
	}
	else
	{
		printf("This car does not exist in the garage.\n");
	}
	
}



void disp(stack_t *ps)
{	
	if(ps->top==-1)
		printf("Garage is empty.\n");
	else
	{
		for(int i=0;i<=ps->top;++i)
		{
			printf("%d ",ps->s[i]);
		}
		printf("\n");
	}
}
