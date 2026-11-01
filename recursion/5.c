// 7. Enter a number and add all digits using recursion
#include<stdio.h>

int sum(int n)
{
    if(n == 0)
    {
        return 0;
    }
    else
    {
        return (n % 10) + sum(n / 10);
    }
}

int main()
{
    int num, result;

    printf("Enter a number: ");
    scanf("%d", &num);

    result = sum(num);

    printf("Sum of digits = %d", result);

    return 0;
}