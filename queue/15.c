// Find the Next Greater Element
#include <stdio.h>

int main()
{
    int a[20], n, i, j, found;

    printf("Enter array size: ");
    scanf("%d", &n);

    printf("Enter array elements:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    for (i = 0; i < n; i++)
    {
        found = 0;

        for (j = i + 1; j < n; j++)
        {
            if (a[j] > a[i])
            {
                printf("%d -> %d\n", a[i], a[j]);
                found = 1;
                break;
            }
        }

        if (found == 0)
            printf("%d -> -1\n", a[i]);
    }

    return 0;
}