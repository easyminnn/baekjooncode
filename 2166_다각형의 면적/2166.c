#include <stdio.h>
#include <stdlib.h>

double absolute(double n)
{
    if(n > 0) return n;
    else return -n;
}
int main()
{
    int N;
    double arr[10001][2];
    double plusing = 0;
    double minusing = 0;

    scanf("%d", &N);


    for (int i=0; i<N; i++)
    {
        scanf("%lf %lf", &arr[i][0], &arr[i][1]);
    }

    arr[N][0] = arr[0][0];
    arr[N][1] = arr[0][1];

    for (int i=0; i<N; i++)
    {
        plusing += arr[i][0] * arr[i+1][1];
        minusing += arr[i][1] * arr[i+1][0];
    }

    printf("%.1lf", absolute(plusing - minusing) / 2);

    return 0;
}