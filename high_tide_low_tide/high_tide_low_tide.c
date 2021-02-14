#include<stdio.h>
#include<stdlib.h>

int compare(const void *a, const void *b)
{
    return(*(int*)b - *(int*)a);
}

int main()
{
    int n = 0;
    scanf("%d", &n);
    int half_n = (n % 2 == 0) ? n/2 : n/2+1;
    int measurements[n];
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &measurements[i]);
    }

    qsort(measurements, n, sizeof(measurements[0]), compare);

    for(int i = 0; i < half_n; i++)
    {
        int index = half_n + i;
        if(index < n)
        {
            printf("%d ", measurements[index]);
        }
        index = half_n - 1 - i;
        if(index > -1)
        {
            printf("%d ", measurements[index]);
        }
    }
    printf("\n");
}