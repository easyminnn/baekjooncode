#include <stdio.h>



int zero = 0, one = 0;
int fibonacci(int N)
{

    if(N==0) zero++;
    else if(N==1) one++;

    else return fibonacci(N-1) + fibonacci(N-2); 
}


int main()
{
    int T, N;

    scanf("%d", &T);
    
    for (int i=0; i<T; i++)
    {
        scanf("%d", &N);
        fibonacci(N);
        printf("%d %d\n", zero, one);
        zero = 0;
        one = 0;
    }
}