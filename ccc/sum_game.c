/*
# Sum Game

Problem is from the Canadian Computing Competition's online grader.

Time limit: 1 second.

All test cases passed.

## Problem Description

Annie has two favourite baseball teams: the Swifts and the Semaphores. She has followed 
them throughout the season, which is now over. The season lasted for N days. Both teams 
played exactly one game on each day.

For each day, Annie recorded the number of runs scored by the Swifts on that day. 
She also recorded this information for the Semaphores.

She would like you to determine the largest integer K such that K ≤ N and the Swifts and 
the Semaphores had scored the same total number of runs K days after the start of the season. 
The total number of runs scored by a tea, after K days is the sum of the number of runs 
scored by the team in all games before or on the K-th day.

For example, if the Swifts and the Semaphores have the same total number of runs at the end 
of the season, then you should output N. If the Swifts and the Semaphores never had the same 
number of runs after K games, for any value of K ≤ N, then output 0.

## Input Specification

The first line of input will contain an integer N (1 ≤ N ≤ 100,000). The second line will 
contain N space-separated non-negative integers representing the number of runs scored by 
the Swifts on each day, in order. The third line will contain N space-separated non-negative 
integers representing the number of runs scored by the Semaphores on each day, in order. 
You may assume that each team scored at most 20 runs in any single game.

For 7 of the 15 points available, N ≤ 1,000.

## Output Specification

Output the largest integer K such that K ≤ N and the Swifts and the Semaphores have the 
same total number of runs after K days.

## Sample Input 1

```
3
1 3 3
2 2 6
```

## Output for Sample Input 1

```
2
```

## Explanation for Output for Sample Input 1

After 2 days, each team had scored a total of 4 runs.

## Sample Input 2

```
3
1 2 3
4 5 6
```

## Output for Sample Input 2

```
0
```

## Explanation for Output for Sample Input 2

The only time when the Swifts and the Semaphores had scored the same number of runs was 
the beginning of the season.

## Sample Input 3

```
4
1 2 3 4
1 3 2 4
```

## Output for Sample Input 3

```
4
```

## Explanation for Output for Sample Input 3

The Swifts and the Semaphores have the same number of total runs after the first game, 
and after the third game, and after the fourth game. We take the largest of these values 
(1, 3 and 4) and output 4.
*/

#include<stdio.h>

int main()
{
    int n = 0;
    scanf("%d", &n);
    int swifts[n];
    int semaphores[n];
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &swifts[i]);
    }
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &semaphores[i]);
    }

    int k = 0;
    int swifts_sum = 0;
    int semaphores_sum = 0;
    for(int i = 0; i < n; i++)
    {
        swifts_sum += swifts[i];
        semaphores_sum += semaphores[i];
        if(swifts_sum == semaphores_sum)
        {
            k = i+1;
        }
    }
    printf("%d\n", k);
}
