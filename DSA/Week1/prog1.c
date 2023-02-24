#include<stdio.h>
int substr(char *s1,char *s2);
int main()
{
        char s1[50];
        char s2[10];
        printf(" Enter the string : ");
        scanf("%[^\n]s",s1);
        fflush(stdin);
        printf(" Enter sub string : ");
        scanf("%s",s2);
        int ch=substr(s1,s2);
        if(ch==1)
        {
        printf("True\n");
        }
        else
        {
        printf("False\n");
        }
        return 0;
}

int substr(char *s1,char *s2)
{
       int i=0;
       while(*s1!='\0')
       {
       	if(*s1==*s2)
       	{
		while(*s2!='\0')
        		{
			i++;
			return substr(s1+i,s2+i);
		}      
         		return 1;     
 	}
       	else if(*s1!=*s2)
       	{
       		while(*s2!='\0')
       		{	
       			i++;
       			return substr(s1+i,s2);
      		 }
       		return 1;
       	}
      	else
       	{
       		return 1;
       	}
       }
   }