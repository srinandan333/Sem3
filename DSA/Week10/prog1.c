#include<stdio.h> 
#include<stdlib.h>
#define SIZE 10

void read(int a[SIZE][SIZE],int n)
{ 
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
}

void dfs(int a[SIZE][SIZE],int n, int visited[SIZE],int source)
{ 
    visited[source]=1;
    printf("%d",source); 
    for(int i=0;i<n;i++)
    {
        if(a[source][i] && !visited[i])
        { 
            dfs(a,n,visited,i);
        }
    }
}

int conn(int a[SIZE][SIZE],int n, int visited[SIZE],int source)
{ 
    int count =1;
    dfs(a,n,visited,source); 
    for(int i=0;i<n;i++)
    { 
        if(!visited[i])
        {
            count++; 
            dfs(a,n,visited,i);
        }
    }
    return count;
}

int main()
{
    int a[SIZE][SIZE],n,visited[SIZE]={0},source; 
    printf("Enter the number of nodes: "); 
    scanf("%d",&n);
    printf("Enter the adjacency matrix:\n"); 
    read(a,n);
    printf("Enter the source: "); 
    scanf("%d",&source);
    printf("DFS traversal\n");
    int count=conn(a,n,visited,source); 
    printf("\nConnectivity:");
    printf("\n %d",count);
    return 0;
}
