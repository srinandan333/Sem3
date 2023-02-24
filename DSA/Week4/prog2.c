#include<stdio.h>
#define MAX 10
typedef struct stack
{
	int a[MAX];
	int top;
}stack_t;
void init(stack_t *ps)
{
	ps->top=-1;	
}
int isEmpty(stack_t *ps)
{
	return ps->top==-1;	
}
int isFull(stack_t *ps)
{
	return ps->top==MAX-1;	
}
int push(stack_t *ps,int ele)
{
	if(isFull(ps))
		return	0;
	ps->top++;
	ps->a[ps->top]=ele;
	return 1;
}
int pop(stack_t *ps)
{
	if(isEmpty(ps)) return 0;
	return ps->a[ps->top--];
}
int paran_match(char paran[])
{
	stack_t s; char ch;char ch1;
	init(&s);
	int i=0;
	while(paran[i]!='\0')
	{
		ch=paran[i];
		if(ch=='{' || ch=='[' || ch =='(')
		{
			push(&s,ch);
		}
		else if(ch=='}')
		{
			if(isEmpty(&s))
			{
				return 0;
			}
			else{
			ch1=pop(&s);
			if(ch1!='{')
				return 0;
			}
		}
		else if(ch==']')
		{
			if(isEmpty(&s))
			{
				return 0;
			}
			else{
			ch1=pop(&s);
			if(ch1!='[')
				return 0;
			}
		}
		else if(ch==')')
		{
			if(isEmpty(&s))
			{
				return 0;
			}
			else{
			ch1=pop(&s);
			if(ch1!='(')
				return 0;
			}
		}
		++i;
	}
	if(isEmpty(&s))
		return 1; //matched one
	else
		return 0; //not matched
	
}
int main()
{
	char paran[10];	
	printf("Enter input\n");
	scanf("%s",paran);
	if(paran_match(paran))
		printf("valid\n");
	else
		printf("Invalid\n");
	return 0;
}



