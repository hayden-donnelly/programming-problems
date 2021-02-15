#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    int n = 0;
    scanf("%d", &n);
    char **names = (char**)malloc(sizeof(char*)*n); 
    for(int i = 0; i < n; i++)
    {
        names[i] = malloc(sizeof(char)*20);
        scanf("%s", names[i]);
    }
    for(int i = 0; i < n; i++)
    {
        char *current_name = malloc(sizeof(char)*20);
        scanf("%s", current_name);
        if(strcmp(names[n-1-i], current_name) != 0 || strcmp(names[i], current_name) == 0)
        {
            printf("bad\n");
            return 0;
        }
    }
    printf("good\n");
    return 0;
}