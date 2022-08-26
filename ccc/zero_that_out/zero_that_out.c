#include<stdio.h>

int main()
{
    int k = 0;
    scanf("%d", &k);
    int statements[k];
    int statements_length = 0;
    for(int i = 0; i < k; i++)
    {
        int new_statement = 0;
        scanf("%d", &new_statement);
        if(new_statement != 0)
        {
            statements[statements_length] = new_statement;
            statements_length++;
        }
        if(new_statement == 0)
        {
            statements_length--;
        }
    }

    int statements_sum = 0;
    for(int i = 0; i < statements_length; i++)
    {
        statements_sum += statements[i];
    }
    printf("%d\n", statements_sum);
}