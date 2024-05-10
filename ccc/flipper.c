/*
# Flipper

Problem is from the Canadian Computing Competition's online grader.

Time limit: 1 seconds.

All test cases passed.

## Problem Descripion

You are trying to pass the time while at the optomotrist. You notice there is a grid of 
four numbers:

```
1 2
3 4
```

You see lots of mirrors and lenses at the optometrist, and wonder how flipping the grid 
horizontally or vertically would change the grid.

Specifically, a "horizontal" flip (across the horizontal centre line) would take the original 
grid of four numbers and result in:

```
3 4
1 2
```

A "vertical" flip (across the vertical centre line) would take the original grid of four 
numbers and result in:

```
2 1
4 3
```

Your task is to determine the final orientation of the numbers in the grid after a sequence 
of horizontal and vertical flips.

## Input Specification

The input consists of one line, composed of a sequence of at least one and at most 1,000,000 
characters. Each character is either H, representing a horizontal flip, or V, representing a 
vertical flip.

For 8 of the 15 available marks, there will be at most 1,000 characters in the input.

## Output Specification

Output the final orientation of the four numbers. Specifically, each of the two lines of 
output will contain two integers, separated by one space.

## Sample Input 1

HV

## Output for Sample Input 1

```
4 3
2 1
```

## Sample Input 2

VVHH

## Output for Sample Input 2

```
1 2
3 4
```
*/

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
