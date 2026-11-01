// Calculate the sum of natural numbers till 10 using recursion
#include<stdio.h>

int sum(int n)
{
    if(n == 0)
    {
        return 0;
    }
    else
    {
        return n + sum(n - 1);
    }
}

int main()
{
    int result;

    result = sum(10);

    printf("Sum of natural numbers = %d", result);

    return 0;
}