#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct 
{
    int start;
    int end;
}arr;

int compare(const void* a, const void* b);


int main()
{
    int N, x, y;
    int count= 0;
    int last = 0;

    scanf("%d", &N);

    arr* array1 = (arr*)malloc(sizeof(int) * 2 * N);

    for (int i=0; i<N; i++)
    {
        scanf("%d %d", &x, &y);
        array1[i].start = x;
        array1[i].end = y;
    }

    qsort(array1, N, sizeof(arr), compare);



    for(int i = 0; i<N; i++)
    {
        if(array1[i].start >= last)
        {
            count++;
            last = array1[i].end;
        }
    }

    printf("%d\n", count);
    free(array1);

    return 0;

}




///////////////////////////////////////////////////////
int compare(const void* a, const void* b)
{
    arr *n1 = (arr*) a;
    arr *n2 = (arr*) b;

    if(n1->end != n2->end)
    {
        if(n1->end < n2->end) return -1;
        else return 1;
    }

    else
   {
       if(n1->start < n2->start) return -1;
       else if(n1->start == n2->start) return 0;
       else return 1;
   }
    
}
