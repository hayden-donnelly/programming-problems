#include<stdio.h>
#include<stdlib.h>

int compare(const void *a, const void *b)
{
    return(*(int*)a - *(int*)b);
}

int main()
{
    int question = 0;
    int n = 0;
    scanf("%d %d", &question, &n);
    int first_country[n];
    int second_country[n];
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &first_country[i]);
    }
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &second_country[i]);
    }

    qsort(first_country, n, sizeof(first_country[0]), compare);
    qsort(second_country, n, sizeof(second_country[0]), compare);

    int speed_sum = 0;
    if(question == 1)
    {
        for(int i = 0; i < n; i++)
        {
            int first_speed = first_country[i];
            int second_speed = second_country[i];
            speed_sum += (first_speed > second_speed) ? first_speed : second_speed;
        }
    }
    else if(question == 2)
    {
        for(int i = 0; i < n; i++)
        {
            int first_speed = first_country[i];
            int second_speed = second_country[n-1-i];
            speed_sum += (first_speed > second_speed) ? first_speed : second_speed;
        }
    }

    printf("%d\n", speed_sum);
}