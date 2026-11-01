#include <stdio.h>

int main()
{
    int a[10][10], n, e;
    int i, j, u, v;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &e);

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            a[i][j] = 0;
        }
    }

    for(i = 0; i < e; i++)
    {
        printf("Enter edge (u v): ");
        scanf("%d%d", &u, &v);

        a[u][v] = 1;
        a[v][u] = 1;
    }

    printf("\nAdjacency Matrix:\n");

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    return 0;
}