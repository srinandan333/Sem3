#include<stdio.h>
#include<ctype.h>
#include"header.h"
int main()
{
	stack_t s;
	init(&s);
	int ch,a,n,m;

	printf("1:Push\t2:Pop\t3:Display\n");
	printf("Enter your choice:\n");
	scanf("%d",&ch);
	do{
	switch(ch)
	{
		case 1: printf("Enter car no:");
			fflush(stdin);
			scanf("%d",&n);
			a=push(&s,n);
			if(a)
				printf("Car %d has been parked successfully.\n",n);
			else
				printf("No parking space free.\n");
			break;
		case 2: printf("Enter car no to be exited:");
			fflush(stdin);
			scanf("%d",&m);
			check(&s,m);
			break;
		
				
		case 3: disp(&s);
			break;
	}
	printf("1:Push\t2:Pop\t3:Display\n");
	printf("Enter your choice:\n");
	scanf("%d",&ch);

	}while(ch<4);

	return 0;
}
