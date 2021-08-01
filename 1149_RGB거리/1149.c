#include <stdio.h>


int min(int a, int b)
{
    if (a > b) return  b;
    else return a;
}


int main()
{
    int N;
    int arr[3];
    int dp1[3];
    int dp2[3];

    dp1[0] = dp1[1] = dp1[2] = 0;

    scanf("%d", &N);

    for (int i = 0; i<N; i++)
    {
        scanf("%d %d %d", &arr[0], &arr[1], &arr[2]);

        dp2[0] = dp1[0];
        dp2[1] = dp1[1];
        dp2[2] = dp1[2];

        dp1[0] = min(dp2[1], dp2[2]) + arr[0];
        dp1[1] = min(dp2[2], dp2[0]) + arr[1];
        dp1[2] = min(dp2[0], dp2[1]) + arr[2];

    }
    
    
    int minnum = min(min(dp1[0], dp1[1]), dp1[2]);
    
    printf("%d\n", minnum);

}