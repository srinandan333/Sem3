#include<stdio.h>
#include "header.h"
int main()
{
        stu a[50];
        int n;
        char s[20];
        printf(" Enter the no of students : ");
        scanf("%d",&n);
        printf(" Enter student details: ");
        read(a,n);
        printf(" Student details are : ");
        disp(a,n);
        printf(" Enter subject code to find average : ");
        printf(" Subject codes are : ");
        printf(" CS101\n CS102\n CS103\n CS104\n CS105\n");
        scanf("%s",s);
        avg(a,s,n);
        sort(a,n);
        printf(" After sorting student record is :\n");
        disp1(a,n);
        return 0;
}
        