#include <stdio.h>

int tribonacci(int M);

int main()
{
    int N, M;
    scanf("%d", &N);

    for(int i=0; i<N; i++)
    {
        scanf("%d", &M);
        printf("%d\n", tribonacci(M));
    }
}

int tribonacci(int M)
{
    if(M == 0) return 0;
    if(M == 1) return 1;
    if(M == 2) return 2;
    if(M == 3) return 4;
    else return tribonacci(M-1) + tribonacci(M-2) + tribonacci(M-3);
}