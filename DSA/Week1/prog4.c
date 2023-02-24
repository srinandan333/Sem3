#include<stdio.h>
#include<stdlib.h>
void hanoi(int n, char rodFrom, char rodMiddle, char rodTo);

 int main()
 {
     int n;
     printf("Enter number of disks:\n");
     scanf("%d",&n);
     hanoi(n,'A','B','C');
     return 0;
 }

 void hanoi(int n, char rodFrom, char rodMiddle, char rodTo)
 {
     if(n==1)
     {
         printf("Disk 1 moved from %c to %c.\n", rodFrom, rodTo);
         return;
     }
     hanoi(n-1, rodFrom, rodTo, rodMiddle);
     printf("Disk %d moved from %c to %c.\n");
     hanoi(n-1, rodMiddle, rodFrom, rodTo);
 }