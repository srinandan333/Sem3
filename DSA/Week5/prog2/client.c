#include<stdio.h>
#include<stdlib.h>
#include"header.h"

int main()
{
	struct pq p;
	init(&p);
	struct comp c;
	int ch;
	printf("1.Book vaccine slot\t2.Conduct Vaccination\t3.Display\t4.Exit\n");
	while(1)
	{
	        printf("Enter choice:\n");
	        scanf("%d",&ch);
		switch(ch)
		{
			case 1:	printf("Enter name and age and morbidity:\n");
				scanf("%s %d %s",c.name,&(c.age),&(c.morb));
				enqueue(&p,&c);
				break;
			case 2: dequeue(&p);
				break;
			case 3: disp(&p);
				break;
			case 4: exit(0);
		}
	}
	return 0;
}
