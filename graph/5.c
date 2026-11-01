#include <stdio.h>

int a[10][10], visited[10], queue[100];
int front = -1, rear = -1, n;

void BFS(int start)
{
    int i, v;

    visited[start] = 1;

    queue[++rear] = start;

    front = 0;

    while(front <= rear)
    {
        v = queue[front++];

        printf("%d ", v);

        for(i = 0; i < n; i++)
        {
            if(a[v][i] == 1 && visited[i] == 0)
            {
                visited[i] = 1;
                queue[++rear] = i;
            }
        }
    }
}

int main()
{
    int e, u, v, i, start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &e);

    for(i = 0; i < e; i++)
    {
        printf("Enter edge: ");
        scanf("%d%d", &u, &v);

        a[u][v] = 1;
        a[v][u] = 1;
    }

    for(i = 0; i < n; i++)
        visited[i] = 0;

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    printf("BFS Traversal: ");
    BFS(start);

    return 0;
}