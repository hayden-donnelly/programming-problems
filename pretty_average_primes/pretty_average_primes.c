#include<stdio.h>

void find_pairs(int number)
{
    int goal = number*2;
    int a = 2;
    int b = 0;

    for(int i = 2; i <= a; i++)
    {
        if(i == a)
        {
            b = goal - a;
            for(int k = 2; k <= b; k++)
            { 
                if(k == b)
                {
                    printf("%d %d\n", a, b);
                    return;
                }
                else if(b % k == 0)
                {
                    if(a == 2)
                    {
                        a += 1;
                    }
                    else
                    {
                        a += 2;
                    }
                    i = 1;
                    break;
                }  
            }
        }
        else if(a % i == 0)
        {
            if( a == 2)
            {
                a += 1;
            }
            else
            {
                a += 2;
            }
            i = 1;
        }   
    }
}

int main()
{
    int t = 0;
    scanf("%d", &t);
    int n[t];
    for(int l = 0; l < t; l++)
    {
        scanf("%d", &n[l]);
    }

    for(int i = 0; i < t; i++)
    {
        find_pairs(n[i]);
    }
}