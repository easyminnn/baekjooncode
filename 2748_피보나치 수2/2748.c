#include <stdio.h>

long long int fibonacci1(int n)
{
    long long int a = 0, b = 1, tmp;

    if (n == 1) return 1;
    if (n == 0) return 0;

    for (int i = 0; i < n-1; i++)
    {
        tmp = b;
        b = a + b;
        a = tmp;

    }

    return b;
}

int main()
{
    int n;
    scanf("%d", &n);
    printf("%lld", fibonacci1(n));
}