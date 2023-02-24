#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
#define MAX 50

typedef struct stack
{
 char s[MAX];
 int top;
}stack_t;

void init(stack_t *ps)
{
 ps->top=-1;
}

int push(stack_t *ps,char e)
{
 if(ps->top==MAX-1) 
 {
   return 0;
 }
 ps->top++;
 ps->s[ps->top]=e;
 return 1;
}

int pop(stack_t *ps,char *pe)
{
 if(ps->top==-1) 
 {
   return 0;
 }
 *pe=ps->s[ps->top];
 ps->top--;
 return 1;
}

int empty(stack_t *ps)
{
 return ps->top==-1;
}

char stackTop(stack_t *ps)
{
 return ps->s[ps->top];
}

int preced(char st,char curr)
{
  switch(curr)
   {
     case '*':
     case '/':if(st=='*' || st=='/')
               return 1;
              return 0;
     
     case '+':
     case '-':if(st=='*' ||st=='/'||st=='+'||st=='-')
                return 1;
               return 0;
     case '(':return 0;
   
     case ')': if(st=='(')
                return 0;
               return 1;
   }
}

int eval(char postfix[50])
{
  stack_t s; int i=0; int op1;int op2;
	init(&s);
	int res;
	while(postfix[i]!='\0')
	{
		if(isdigit(postfix[i]))	
		{
			push(&s,postfix[i]-'0');
		}
		else
		{
			pop(&s,&op2);
			pop(&s,&op1);
		
			switch(postfix[i])
			{
				case '+': res=op1+op2;
					break;
		
				case '-': res=op1-op2;
					break;
			
				case '*': res=op1*op2;
					break;
			
				case '/': res=op1/op2;
					break;
			}
			push(&s,res);
		}
	++i;	
	}
	pop(&s,&res);
	printf("res=%d\n",res);
}

char convert(char infix[50])
{
    char postfix[50];
    int i=0,k=0; char discard;
    stack_t s;
    init(&s);
    while(infix[i])
    {
        if(isalnum(infix[i]))
        postfix[k++]=infix[i];
        else
        {
            while(!empty(&s) && preced(stackTop(&s),infix[i]))
            {    
              pop(&s,&postfix[k++]);
            }
            if(infix[i]==')')
            {
                pop(&s,&discard);
            }
            else
            {
                push(&s,infix[i]);
            }
        }
        i++;
    }
    while(!empty(&s))
    {
        pop(&s,&postfix[k++]);
    }
    postfix[k]='\0';
    return postfix[50];
}

int main()
{
    char infix[50];
    char postfix[50];
    printf("Enter the Infix expression:\n");
    scanf("%s",infix);
    convert(infix[50]);
    eval(postfix[50]);
    return 0;
}
 
