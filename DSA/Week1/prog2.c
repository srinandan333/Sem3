#include<stdio.h>
#include<string.h>
void swap(char *x,char* y);
void permute(char* s,int l, int n);
int main()
{
        char s[10];
        printf("Enter the string whose permutations need to be found: ");
        scanf("%s",s);
        printf("The possible permutations are:\n");
        permute(s,0,strlen(s)-1);
        return 0;
}

void swap(char *x,char* y)
{
        char temp;
        temp=*x;
        *x=*y;
        *y=temp;
}

void permute(char* s,int l, int n)
{
        int i;
        if(l==n)
                printf("%s\n",s);
        else
        {
                for(i=l;i<=n;i++)
                {
                        swap(s+l,s+i);
                        permute(s,l+1,n);
                        swap(s+l,s+i);
                }
         }
}
