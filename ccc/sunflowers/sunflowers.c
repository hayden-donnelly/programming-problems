#include<stdio.h>
#include<stdlib.h>

void print_table_horizontal_lead(int x_start, int x_increment, int x_finish, int y_start, int y_increment, int y_finish, int **table)
{
    for(int y = y_start; y != y_finish; y += y_increment)
    {
        for(int x = x_start; x != x_finish; x += x_increment)
        {
            printf("%d ", table[y][x]);
        }
        printf("\n");
    }
}
void print_table_vertical_lead(int x_start, int x_increment, int x_finish, int y_start, int y_increment, int y_finish, int **table)
{
    for(int y = y_start; y != y_finish; y += y_increment)
    {
        for(int x = x_start; x != x_finish; x += x_increment)
        {
            printf("%d ", table[x][y]);
        }
        printf("\n");
    }
}

int main()
{
    int n = 0;
    scanf("%d", &n);
    int **table = (int**)malloc(sizeof(int*)*n);
    for(int y = 0; y < n; y++)
    {
        table[y] = (int*)malloc(sizeof(int)*n);
        for(int x = 0; x < n; x++)
        {
            scanf("%d", &table[y][x]);
        }
    }

    if(table[0][0] < table[0][n-1])
    {
        if(table[0][0] < table[n-1][0])
        {
            // No rotation
            print_table_horizontal_lead(0, 1, n, 0, 1, n, table);
        }
        else
        {
            // 90 degree rotation
            print_table_vertical_lead(n-1, -1, -1, 0, 1, n, table);
        }
    }
    else
    {
        if(table[0][0] < table[n-1][0])
        {
            // 270 degree rotation
            print_table_vertical_lead(0, 1, n, n-1, -1, -1, table);
        }
        else
        {
            // 180 degree rotation
            print_table_horizontal_lead(n-1, -1, -1, n-1, -1, -1, table);
        }
    }
}