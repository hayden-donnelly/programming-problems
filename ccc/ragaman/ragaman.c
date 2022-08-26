#include<stdio.h>

char first[100];
char second[100];

int main()
{
    scanf("%s", first);
    scanf("%s", second);

    int asterisk_count = 0;
    int characters_removed = 0;
    int i = 0;
    for(i = 0; first[i] != 0; i++)
    {
        if(second[i] == '*')
        {
            asterisk_count++;
        }
        else
        {
            for(int k = 0;; k++)
            {
                if(first[k] == 0)
                {
                    printf("N\n");
                    return 0;
                }
                else if(second[i] == first[k])
                {
                    first[k] = '.';
                    characters_removed++;
                    break;
                }
            }
        }
    }

    if(asterisk_count == i-characters_removed)
    {
        printf("A\n");
        return 0;
    }
    printf("N\n");
    return 0;
}