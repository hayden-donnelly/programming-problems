#include<stdio.h>

void find_pairs(int number)
{
    int goal = number*2;
    int a = 2;
    int b = 2;

    for(int i = 2; i <= a; i++)
    {
        if(a % i == 0 && i != a)
        {
            a++;
            i = 1;
            continue;
        }
        else if(i == a)
        {
            if(a > number)
            {
                break;
            }
            else
            {
                b = a;
                for(int k = 2; a+b <= goal; k++)
                {
                    if(b % k == 0 && k != b)
                    {
                        b++;
                        k = 1;
                        continue;
                    }
                    else if(k == b)
                    {
                        if(a+b == goal)
                        {
                            printf("%d %d\n", a, b);
                            return;
                        }
                        else
                        {
                            b++;
                            k = 1;
                        }
                    }
                }
            }
            a++;
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