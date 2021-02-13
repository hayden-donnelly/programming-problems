#include<stdio.h>

int invitees[100];

int main()
{
    int k = 0;
    int m = 0;
    scanf("%d %d", &k, &m);
    for(int i = 0; i < m; i++)
    {
        int removal = 0;
        scanf("%d", &removal);
        for(int j = 0; j < k+1; j += removal)
        {
            invitees[j] = -1;
        }
    }

    for(int i = 0; i < k; i++)
    {
        if(invitees[i] != -1)
        {
            printf("%d\, ", i);
        }
    }
}