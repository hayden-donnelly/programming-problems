/*
# Part Invitation

Problem is from the Canadian Computing Competition's online grader.

Time limit: 5 seconds.

All test cases passed.

## Problem Description

You are hosting a party an do not have room to invite all of your friends. 
You use the following unemotional mathematical method to determine which friends to invite.

Number your friends 1, 2,..., K and place them in a list in this order. Then perform m rounds. 
in each round, use a number to determine which friends to remove from the ordererd list.

The rounds will use numbers r<sub>1</sub>, r<sub>2</sub>,..., r<sub>m</sub>. In round i remove 
all the remaining people in positions that are multiples of r<sub>i</sub> 
(that is, r<sub>i</sub>, 2r<sub>i</sub>, 3r<sub>i</sub>,...). 
The beginning of the list s position 1.

Output the numbers of the friends that remain after this removal process.

## Input Specification

The first line of input contains the integer K (1 ≤ K ≤ 100). The second line of input contains 
the integer m (1 ≤ m ≤ 10), which is the number of rounds of removal. The next m lines each 
contain one integer. The ith of these lines (1 ≤ i ≤ m) contains r<sub>i</sub> 
(2 ≤ r<sub>i</sub> ≤ 100) indicating that every person at a position which is multiple of 
r<sub>i</sub> should be removed.

## Output Specification

The output is the integers assigned to friends who were not removed. One integer is printed 
per line in increasing sorted order.

## Sample Input

```
10
2
2
3
```

## Output for Sample Input

```
1
3
7
9
```

## Explanation of Ouput for Sample Input

Initially, our list of invitees is 1, 2, 3, 4, 5, 6, 7, 8, 9. 10. There will be two rounds 
of removals. After the first round of removals, we remove the even positions 
(i.e., every second position), which causes our list of invitees to be 1, 3, 5, 7, 9. 
After the second round of removals, we remove every 3rd remaining invitee: thus, 
we keep 1 and 3, remove 5 and keep 7 and 9, which leaves us with an invitee list of 1, 3, 7, 9.
*/

#include<stdio.h>
#include<stdlib.h>

void remove_invitees(int k, int i, int m, int *invitees)
{
    if(i == m)
    {
        for(int j = 0; j < k; j++)
        {
            printf("%d\n", invitees[j]);
        }
        return;
    }

    int removal = 0;
    int people_retained = 0;
    scanf("%d", &removal);
    for(int j = 1; j <= k; j++)
    {
        if(j % removal == 0)
        {
            continue;
        }
        invitees[people_retained] = invitees[j-1];
        people_retained++;
    }
    remove_invitees(people_retained, ++i, m, invitees);
}

int main()
{
    int k = 0;
    int m = 0;
    scanf("%d %d", &k, &m);

    int *invitees = (int*)malloc(sizeof(int)*k);
    for(int i = 0; i < k; i++)
    {
        invitees[i] = i+1;
    }
    remove_invitees(k, 0, m, invitees);
}
