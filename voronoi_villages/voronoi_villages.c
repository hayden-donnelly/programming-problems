#include<stdio.h>
#include<stdlib.h>

int compare(const void *a, const void *b)
{
    return(*(int*)a - *(int*)b);
}

int main()
{
    int n = 0;
    scanf("%d", &n);
    int v[n];
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &v[i]);
    }
    qsort(v, n, sizeof(v[0]), compare);

    float smallest_size = -1.0f;
    for(int i = 1; i < n-1; i++)
    {
        //zprintf("%d\n%d\n%d\n", v[i-1], v[i], v[i+1]);
        float size_left = (float)(v[i] - v[i-1]) * 0.5;
        float size_right = (float)(v[i+1] - v[i]) * 0.5;
        float size = size_left + size_right;
        smallest_size = (size < smallest_size || smallest_size < 0) ? size : smallest_size;
    }
    printf("%.1f\n", smallest_size);
}