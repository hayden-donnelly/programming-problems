#include<stdio.h>

int main()
{
    int grid[] = { 1, 2, 3, 4 };
    int temp = 0;
    int max_input = 1000000;
    char input[max_input];
    scanf("%s", input);

    for(int i = 0; i < max_input; i++)
    {
        if(input[i] == 'V')
        {
            // Vertical Swap
            temp = grid[0];
            grid[0] = grid[1];
            grid[1] = temp;
            temp = grid[2];
            grid[2] = grid[3];
            grid[3] = temp;
        }
        else if(input[i] == 'H')
        {
            // Horizontal Swap
            temp = grid[0];
            grid[0] = grid[2];
            grid[2] = temp;
            temp = grid[1];
            grid[1] = grid[3];
            grid[3] = temp;
        }
        else
        {
            break;
        }
    }

    printf("%d %d\n%d %d", grid[0], grid[1], grid[2], grid[3]);
}