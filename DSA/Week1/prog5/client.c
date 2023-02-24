#include<stdio.h>
#include"header.h"
int main()
{
ipl s[10];
int n;
printf("Enter the number of records to be entered: ");
scanf("%d",&n);
read(s,n);
printf("\n");
max_runs(s,n);
printf("\n");
matches(s, n);
}