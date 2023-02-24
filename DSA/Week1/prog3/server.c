#include<stdio.h>
#include<string.h>
#include"header.h"
void read(stu *a,int n)
{
        int i;
        for(i=0;i<n;i++)
        {
                scanf("%s",a[i].srn);
                scanf("%s",a[i].name);
                scanf("%d",&a[i].sem);
                printf(" Enter subject code and marks :\n"); 
                scanf("%s",a[i].mar.s1);
                fflush(stdin);
                scanf("%d",&a[i].mar.marks1);
                scanf("%s",a[i].mar.s2); 
                fflush(stdin);
                scanf("%d",&a[i].mar.marks2);
                scanf("%s",a[i].mar.s3);
                fflush(stdin);
                scanf("%d",&a[i].mar.marks3);
                scanf("%s",a[i].mar.s4);
                fflush(stdin);
                scanf("%d",&a[i].mar.marks4);
                scanf("%s",a[i].mar.s5);
                fflush(stdin);
                scanf("%d",&a[i].mar.marks5);
         }
}
void disp(stu *a,int n)
{
        int i;
        for(i=0;i<n;i++)
        {
                printf("%s\n",a[i].srn);
                printf("%s\n",a[i].name);
                printf("%d\n",a[i].sem);
                printf("Subject and marks are :\n");
                printf("%s\n",a[i].mar.s1);
                printf("%d\n",a[i].mar.marks1);
                printf("%s\n",a[i].mar.s2);
                printf("%d\n",a[i].mar.marks2);
                printf("%s\n",a[i].mar.s3);
                printf("%d\n",a[i].mar.marks3);
                printf("%s\n",a[i].mar.s4);
                printf("%d\n",a[i].mar.marks4);
                printf("%s\n",a[i].mar.s5);
                printf("%d\n",a[i].mar.marks5);
         }
}
void avg(stu *a,char *s,int n)
{
        int i,avg;
        int sum=0;
        if(strcmp(s,"CS101")==0)
        {
	for(i=0;i<n;i++)
        	{
		sum=sum+a[i].mar.marks1;
	}
	avg=sum/n;
         }
        else if(strcmp(s,"CS151")==0)
        {
	for(i=0;i<n;i++)
        	{
		sum=sum+a[i].mar.marks2;
	}
	avg=sum/n;
         }
        else if(strcmp(s,"CY101")==0)
        {
	for(i=0;i<n;i++)
        	{
		sum=sum+a[i].mar.marks3;
	}
	avg=sum/n;
         }
        else if(strcmp(s,"CV101")==0)
        {
	for(i=0;i<n;i++)
        	{
		sum=sum+a[i].mar.marks4;
	}
	avg=sum/n;
        }
        else
        {
	for(i=0;i<n;i++)
        	{
		sum=sum+a[i].mar.marks5;
	}
	avg=sum/n;
         }
         printf(" Average marks is : %d\n",avg);	
}
void sort(stu *a,int n)
{
             int i,j;
             for(i=0;i<n-1;i++)
             {
	for(j=0;j<n-i-1;j++)
	{
		if((strcmp(a[j].srn,a[j+1].srn))>0)
		{
			stu temp=a[j];
			a[j]=a[j+1];
			a[j+1]=temp;
		}
	}
             }
}
void disp1(stu *a,int n)
{
            int i;
            for(i=0;i<n;i++)
            {
	printf("%s\n",a[i].srn);
             }
}	