
#include <stdio.h>

#define MAX 20

int graph[MAX][MAX], visited[MAX];
char files[MAX][30];
int n;

void BFS(int start, int target)
{
    int q[MAX], front=0, rear=0, found=0;

    for(int i=0;i<n;i++) visited[i]=0;

    q[rear++]=start;
    visited[start]=1;

    printf("\nBFS: ");

    while(front<rear)
    {
        int v=q[front++];
        printf("%s ",files[v]);

        if(v==target) found=1;

        for(int i=0;i<n;i++)
            if(graph[v][i] && !visited[i])
            {
                visited[i]=1;
                q[rear++]=i;
            }
    }

    if(found) printf("\nFile Found using BFS\n");
    else printf("\nFile Not Found using BFS\n");
}

void DFS(int v,int target,int *found)
{
    visited[v]=1;
    printf("%s ",files[v]);

    if(v==target) *found=1;

    for(int i=0;i<n;i++)
        if(graph[v][i] && !visited[i])
            DFS(i,target,found);
}

int main()
{
    int start,target,found=0;

    printf("Enter number of files: ");
    scanf("%d",&n);

    printf("Enter file names:\n");
    for(int i=0;i<n;i++)
        scanf("%s",files[i]);

    printf("Enter adjacency matrix:\n");
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%d",&graph[i][j]);

    printf("Enter starting node: ");
    scanf("%d",&start);

    printf("Enter target node: ");
    scanf("%d",&target);

    BFS(start,target);

    for(int i=0;i<n;i++) visited[i]=0;

    printf("\nDFS: ");
    DFS(start,target,&found);

    if(found) printf("\nFile Found using DFS\n");
    else printf("\nFile Not Found using DFS\n");

    return 0;
}
