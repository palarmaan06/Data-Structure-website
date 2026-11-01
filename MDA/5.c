// Enter a Matrix from user, copy it in another matrix of same size?
#include <stdio.h>

int main()
{
    int a[10][10], b[10][10];
    int r, col, i, j;

    printf("Enter rows and columns: ");
    scanf("%d%d", &r, &col);

    printf("Enter matrix elements:\n");

    for(i = 0; i < r; i++)
    {
        for(j = 0; j < col; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    for(i = 0; i < r; i++)
    {
        for(j = 0; j < col; j++)
        {
            b[i][j] = a[i][j];
        }
    }

    printf("Copied matrix:\n");

    for(i = 0; i < r; i++)
    {
        for(j = 0; j < col; j++)
        {
            printf("%d\t", b[i][j]);
        }
        printf("\n");
    }

    return 0;
}