#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N, K;

    scanf("%d %d", &N, &K);

    int* coin = (int*)malloc(sizeof(int) * N);
    for (int i = N-1; i >= 0; i--)
        scanf("%d", &coin[i]);
    int count = 0;
    int i=0;
    while (K > 0)
    {
        
        if(K >= coin[i])
        {
            count += K/coin[i];
            K = K % coin[i];
        }
        else i++;
    }
    free(coin);
    printf("%d\n", count);
}