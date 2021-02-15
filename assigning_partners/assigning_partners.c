#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    struct pair
    {
        char first_name[20];
        char second_name[20];
    };

    int n = 0;
    scanf("%d", &n);

    struct pair **names = (struct pair**)malloc(sizeof(struct pair*)*n); 
    for(int i = 0; i < n; i++)
    {
        names[i] = (struct pair*)malloc(sizeof(struct pair)*20);
        scanf("%s", names[i]->first_name);
    }
    for(int i = 0; i < n; i++)
    {
        scanf("%s", names[i]->second_name);
        if(strcmp(names[i]->first_name, names[i]->second_name) == 0)
        {
            printf("bad\n");
            return 0;
        }
        for(int k = i-1; k > -1; k--)
        {
            if(strcmp(names[i]->second_name, names[k]->first_name) == 0
                && strcmp(names[i]->first_name, names[k]->second_name) != 0)
            {
                printf("bad\n");
                return 0;
            }
        }
    }
    printf("good\n");
    return 0;
}