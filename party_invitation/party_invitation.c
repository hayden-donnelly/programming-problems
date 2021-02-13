#include<stdio.h>
#include<stdlib.h>

void remove_invitees(int k, int i, int m, int *invitees)
{
    if(i == m)
    {
        for(int j = 0; j < k; j++)
        {
            printf("%d\n", invitees[j]);
        }
        return;
    }

    int removal = 0;
    int people_retained = 0;
    scanf("%d", &removal);
    for(int j = 1; j <= k; j++)
    {
        if(j % removal == 0)
        {
            continue;
        }
        invitees[people_retained] = invitees[j-1];
        people_retained++;
    }
    remove_invitees(people_retained, ++i, m, invitees);
}

int main()
{
    int k = 0;
    int m = 0;
    scanf("%d %d", &k, &m);

    int *invitees = (int*)malloc(sizeof(int)*k);
    for(int i = 0; i < k; i++)
    {
        invitees[i] = i+1;
    }
    remove_invitees(k, 0, m, invitees);
}