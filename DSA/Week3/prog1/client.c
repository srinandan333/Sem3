#include<stdio.h>
#include<stdlib.h>
#include"header.h"
int main()
{
	int ch;
	list l;
	l.no_of_nodes=0;
	init(&l);
	do{
	        printf("\n1.Insert\n2.Display\n3.Exit");
	        printf("\nEnter your ch:  ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("Enter name: ");
				char name[20];
				
				scanf("%s",name);
				fflush(stdin);
				printf("\nEnter phone Number: ");
				char ph_no[20];
				
				scanf("%s",ph_no);
				fflush(stdin);
				printf("\nEnter address: ");
				char address[50];
				
				scanf("%s",address);
				fflush(stdin);
				printf("\nEnter area: ");
				char area[20];
				
				scanf("%s",area);
				fflush(stdin);
				ordered_insert(&l,name,ph_no,address,area);
			
				break;
			case 2:
				display(&l);
				break;
		
		}
		
	}
	while(ch!=3);
	dinit(&l);
}
