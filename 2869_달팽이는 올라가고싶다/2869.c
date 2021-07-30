#include <stdio.h>

int main()
{
    int v, a, b;

    scanf("%d %d %d", &a, &b, &v);

    printf("%d", (v-b-1)/(a-b)+1);
}