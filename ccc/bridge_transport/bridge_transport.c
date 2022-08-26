#include<stdio.h>

int main()
{
    int w = 0;
    int n = 0;
    scanf("%d %d", &w, &n);
    int weights[n];
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &weights[i]);
    }

    int cars_can_cross = 0;
    int weight_sum = 0;
    for(int i = 0; i < n; i++)
    {
        int weight_sum = 0;
        for(int k = 0; k < 4; k++)
        {
            weight_sum += weights[i+k];
            if(weight_sum > w)
            {
                printf("%d\n", cars_can_cross);
                return 0;
            }
        }
        if(i == 0)
        {
            cars_can_cross += (n >= 4) ? 4 : n;
        }
        else
        {
            cars_can_cross += 1;
        }
    }
    printf("%d\n", cars_can_cross);
}