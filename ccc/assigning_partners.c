/*
# Assigning Partners

Problem is from the Canadian Computing Competition's online grader.

Time limit: 5 seconds.

All test cases passed.

## Problem Description

The CEMC is organizing a workshop with an activity involving pairs of students. 
They decided to assign partners ahead of time. You need to determine if they did this 
consistently. That is whenever A is a partner of B, then B is also a partner of A, 
and no one is a partner of themselves.

## Input Specification

The input consists of three lines. The first line consists of an integer N (1 ≤ N ≤ 30), 
which is the number of students in the class. The second line contains the first names of 
the N students separated by single spaces. (Names contain only uppercase or lowercase 
letters, and no two students have the same first name). The third line contains the same 
N names in some order, separated by single spaces.

The positions of the names in the last two lines indicate the assignment of partners the 
ith name on the second line is the assigned partner of the ith name on the third line.

## Output Specification

The output will be good if the two lists of names are arranged consistently, and bad if 
the arrangement of partners is not consistent.

## Sample Input 1

```
4
Ada Alan Grace John
John Grace Alan Ada
```

## Output for Sample Input 1

```
good
```

## Explanation for Output for Sample Input 1

Ada and John are partners, and Alan and Grace are partners. This arrangement is consistent.

## Sample Input 2

```
7
Rich Graeme Michelle Sandy Vlado Ron Jacob
Ron Vlado Sandy Michelle Rich Graem Jacob
```

## Output for Sample Input 2

```
bad
```

## Explanation for Output for Sample Input 2

Graeme is partnered with Vlado, but Vlado is partnered with Rich. This is not consistent. 
It is also inconsistent because Jacob is partnered with himself.
*/
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
