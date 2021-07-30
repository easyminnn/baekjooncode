#include <stdio.h>
#include <stdlib.h>

int compare(int a, int b)
{
    return (a>b)? a: b;
}
int main()
{
    int N = 0;
    int max = 0;
    int result = 0; 
    scanf("%d", &N);

    int *arr = (int*)malloc(sizeof(int) * N);
    int *dp = (int*)malloc(sizeof(int) * N);

    for (int i=0; i<N; i++)
    {
        max = 0;
        scanf("%d", &arr[i]);
        
        for (int j=0; j<i; j++){
            if(arr[i]>arr[j])
            {
                if(dp[j] > max)
                    max = dp[j];
            }
        }
        dp[i] = max+1;
        result = compare(result, dp[i]);
    }

    printf("%d", result);
    free(arr);
    free(dp);
}