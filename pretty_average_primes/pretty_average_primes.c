#include<stdio.h>

int main()
{
    int t = 0;
    scanf("%d", &t);
    int n[t];
    for(int l = 0; l < t; l++)
    {
        scanf("%d", &n[l]);
    }

    /*for(int i = 0; i < t; i++)
    {
        //printf("asdas\n");
        int pair_found = 0;
        int goal = n[i]*2;
        //printf("goal %d\n", goal);
        int a = 2;
        int b = 2;

        for(int k = 2; k <= a; k++)
        {
            if(a % k == 0 && a != k)
            {
                a++;
                k = 2;
            }
            else
            {
                //printf("second tier %d\n", a);
                b = a;
                for(int j = 2; b+a <= goal; j++)
                {
                    if(b % j == 0 && b != j)
                    {
                        //printf("third tier\n");
                        b++;
                        j = 2;
                    }
                    else if(b+a == goal)
                    {
                        pair_found = 1;
                    }
                }
                if(pair_found)
                {
                    //printf("fourth tier\n");
                    printf("%d %d\n", a, b);
                    break;
                }
                else
                {
                    a++;
                    k = 2;
                }
            }
        }
    }*/

    int a = 2;
    for(int i = 2; i <= a; i++)
    {
        if(a % i == 0 && i != a)
        {
            a++;
            i = 2;
        }
        else if(i == a)
        {
            printf("prime: %d\n", a);
            if(a > 100)
            {
                break;
            }
            a++;
            i = 2;
        }
    }
}