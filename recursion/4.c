// c
#include<stdio.h>

void binary(int n)
{
    if(n > 1)
    {
        binary(n / 2);
    }

    printf("%d", n % 2);
}

int main()
{
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    if(num < 0)
    {
        printf("Enter a positive number.");
    }
    else
    {
        printf("Binary number: ");
        binary(num);
    }

    return 0;
}