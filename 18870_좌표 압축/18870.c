#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void *a, const void *b);

int main()
{
    int n;

    scanf("%d", &n);

    int *array = (int *)malloc(sizeof(int) * n);

    for (int i=0; i<n; i++)
    {
        scanf("%d", &array[i]);
    }

    qsort(array, n, sizeof(int), compare);



    for (int i=0; i<n; i++)
    {
        printf("%d ", array[i]);
    }

}


int compare(const void *a, const void *b)    // 오름차순 비교 함수 구현
{
    int num1 = *(int *)a;    // void 포인터를 int 포인터로 변환한 뒤 역참조하여 값을 가져옴
    int num2 = *(int *)b;    // void 포인터를 int 포인터로 변환한 뒤 역참조하여 값을 가져옴

    if (num1 < num2)    // a가 b보다 작을 때는
        return -1;      // -1 반환
    
    if (num1 > num2)    // a가 b보다 클 때는
        return 1;       // 1 반환
    
    return 0;    // a와 b가 같을 때는 0 반환
}
