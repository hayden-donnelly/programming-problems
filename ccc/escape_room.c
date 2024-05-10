/*
# Escape Room

Problem is from the Canadian Computing Competition's online grader.

Time limit: 2 seconds.

All test cases passed.

## Problem Description

You have to determine if it is possible ot escape from a room. The room is an M-by-N grid with 
each position (cell) containing a positive integer. The rows are numbered 1,2,...,M and the
columns are numbered 1,2,...,N. We use (r,c) to refer to the cell in row r and column c.

You start in the top left corner at (1,1) and exit from the bottom right corner at (M,N). 
If you are in a cell containing the value x, then you can jump to any cell (a,b) satisfying 
a • b = x. For example, if you are in a cell containing a 6, you can jump to cell (2,3).

Note that from a cell containing a 6, there are up to four cells you can jump to: 
(2,3), (3,2), (1,6), or (6,1). If the room is a 5-by-6 grid, there isn't a row 6 so only the 
first three jumps would be possible.

## Input Specification

The first line of the input will be an integer M (1 ≤ M ≤ 1000). The second line of the input 
will be an integer N(1 ≤ N ≤ 1000). The remaining input gives the positive integers in the 
cells of the room with M rows and N columns. It consists of M lines where each line contains 
N positive integers, each less than or equal to 1 000 000, separated by single spaces.

For 1 of the 15 available marks, M = 2 and N = 2.

For an additional 2 of the 15 available marks, M = 1.

For an additional 4 of the 15 available marks, all of the integers in the cells will be unique.

For an additional 4 of the 15 marks, M ≤ 200 and N ≤ 200.

## Output Specification

Output yes if it is possible to escape from the room. Otherwise, output no.

## Sample Input

```
3
4
3 10  8 14
1 11 12 12
6  2  3  9
```

## Output for Sample Input

```
yes
```
*/
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
