#include <stdio.h>

int max(int a, int b)
{
    if(a > b) return a;
    else return b;
}

int main()
{
    int N;
    int arr[1002];
    int bis[1002][2];
    


    scanf("%d", &N);

    for (int i=1; i<=N; i++)
    {
        scanf("%d", &arr[i]);
    }

    for (int i=1; i<=N; i++)
    {
        for(int j=0; j<i; j++)
        {
            if(arr[i]>arr[j])
                bis[i][0] = max(bis[i][0], bis[j][0] + 1);
        }
    }


    for (int i=N; i>=1; i--)
    {
        for(int j=N+1; j>i; j--)
        {
            if(arr[i]>arr[j])
                bis[i][1] = max(bis[i][1], bis[j][1] + 1);
        }
    }

    int result = 0;

    for (int i=1; i<=N; i++)
    {
        result = max(result, bis[i][0]+bis[i][1]);
    }

    printf("%d\n", result);


}