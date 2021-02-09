#include<stdio.h>
#include<stdlib.h>

int m, n;
int *room;

int check_escapable(int x, int y)
{
    int room_id = x + y * n;
    int current_number = room[room_id];
    if(current_number == -1)
    {
        return 0;
    }
    else if(x+1 == n && y+1 == m)
    {
        return 1;
    }
    room[room_id] = -1;

    for(int i = 1; i <= current_number && (i <= m || i <= n); i++)
    {
        if(current_number % i == 0)
        {
            int factor1 = i;
            int factor2 = current_number/i;
            if(factor1 <= n && factor2 <= m && check_escapable(factor1-1, factor2-1))
            {
                return 1;
            }
        }
    }
    return 0;
}

int main()
{
    scanf("%d", &m);
    scanf("%d", &n);

    room = (int*)malloc(sizeof(int)*m*n);

    int length = m*n;
    for(int i = 0; i < length; i++)
    {
        scanf("%d", &room[i]);
    }

    if(check_escapable(0, 0))
    {
        printf("yes");
    }
    else
    {
        printf("no");
    }

    return 0;
}