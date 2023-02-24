#include<stdio.h>
#include<stdlib.h>

void read(int a[],int n)
{
        printf("Enter elements:\n");
        for(int i=0; i<n;++i)
        {
                scanf("%d",&a[i]);
        }
}

void disp(int a[],int n)
{
        for(int i=0; i<n;++i)
        {
                printf("%d ",a[i]);
        }
        printf("\n");
}

void heapify(int a[],int n)
{
        int ele;
        for(int i=1;i<n;i++)
        {
                ele=a[i];
                int c=i;
                int p= (c-1) / 2;
                while(c>0 && a[p] >ele)
                {
                        a[c]=a[p];
                        c=p;
                        p=(c-1)/2;
                }
                a[c]=ele;
        }
}

int main()
{
        int a[20];
        int n;
        printf("Enter the number of elements:");
        scanf("%d",&n);
        read(a,n);
        printf("Before Heapfication:\n");
        disp(a,n);
        heapify(a,n);
        printf("After Heapification:\n");
        disp(a,n);
        return 0;
}