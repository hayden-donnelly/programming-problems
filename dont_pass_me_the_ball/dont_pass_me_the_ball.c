#include<stdio.h>

int main()
{
    int j = 0;
    scanf("%d", &j);
    int combinations = (j >= 5) ? 1 : 0;
    for(int i = 5; i < j; i++)
    {
        combinations += ((i-2) * (i-3)) / 2;
    }
    printf("%d\n", combinations);
}