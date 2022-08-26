#include<stdio.h>

int main()
{
    int n = 0;
    scanf("%d", &n);
    int swifts[n];
    int semaphores[n];
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &swifts[i]);
    }
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &semaphores[i]);
    }

    int k = 0;
    int swifts_sum = 0;
    int semaphores_sum = 0;
    for(int i = 0; i < n; i++)
    {
        swifts_sum += swifts[i];
        semaphores_sum += semaphores[i];
        if(swifts_sum == semaphores_sum)
        {
            k = i+1;
        }
    }
    printf("%d\n", k);
}