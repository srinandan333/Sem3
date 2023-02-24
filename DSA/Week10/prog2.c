#include<stdio.h> 
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

void bfs(int a[SIZE][SIZE], int n, int visited[SIZE], int source)
{
    int q[n];
    int f=0,r=-1; 
    q[++r]=source; 
    visited[source]=1; 
    int v;
    while(f<=r)
    {
        v=q[f++]; 
        printf("%d",v); 
        for(int i=0;i<n;i++)
        {
            if(a[v][i] && visited[i]==0)
            {
                q[++r]=i; 
                visited[i]=1;
            }
        }
    }
    printf("\n");
}

int main()
{
    int a[SIZE][SIZE],n,visited[SIZE]={0},source; 
    printf("Enter the number of nodes\n"); 
    scanf("%d",&n);
    printf("Enter the adjacent matrix\n"); 
    read(a,n);
    printf("Enter the source\n"); 
    scanf("%d",&source); 
    printf("BFS traversal\n"); 
    bfs(a,n,visited,source);
}