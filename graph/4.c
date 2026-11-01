#include <stdio.h>
#include <stdlib.h>

struct node
{
    int vertex;
    struct node *next;
};

struct node *head[10];
int visited[10];

void insert(int u, int v)
{
    struct node *newnode;

    newnode = malloc(sizeof(struct node));
    newnode->vertex = v;
    newnode->next = head[u];
    head[u] = newnode;

    newnode = malloc(sizeof(struct node));
    newnode->vertex = u;
    newnode->next = head[v];
    head[v] = newnode;
}

void DFS(int v)
{
    struct node *temp;

    visited[v] = 1;
    printf("%d ", v);

    temp = head[v];
while(temp != NULL)
    {        if(visited[temp->vertex] == 0)
        {
            DFS(temp->vertex);
        }

        temp = temp->next;
    }
}

int main()
{int n, e, u, v, i, start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

   for(i = 0; i < n; i++)
    {        head[i] = NULL;
        visited[i] = 0;
    }

    printf("Enter number of edges: ");
    scanf("%d", &e);

    for(i = 0; i < e; i++)
    {
        printf("Enter edge: ");
        scanf("%d%d", &u, &v);

        insert(u, v);
    }

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    printf("DFS Traversal: ");
    DFS(start);

    return 0;
}