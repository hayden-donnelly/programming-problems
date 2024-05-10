/*
# Searching for Strings

## Problem Description

You're given a string N, called the needle, and a string H, called the haystack, both of 
which contain only lowercase letters "a"..."z".

Write a program to count the number of distinct permutations of N which appear as a substring 
of H at least once. Note that N can have anywehre between 1 and |N|! distinct permutations 
in total -- for example, the string "aab" has 3 distinct permutations ("aab, "aba" and "baa").

## Input Specification

The first line contains N (1 ≤ |N| ≤ 200 000), the needle string.

The second line contains H (1 ≤ |H| ≤ 200 000), the haystack string.

For 3 of the 15 available marks, |N| ≤ 8 and |H| ≤ 200.

For an additional 2 of the 15 available marks, |N| ≤ 200 and |H| ≤ 200.

For an additional 2 of the 15 available marks, |N| ≤ 2 000 and |H| ≤ 2 000.

## Output Specification

Output consists of one integer, the number of distinct permutations of N which appear as a 
substring of H.

## Sample Input

```
aab
abacabaa
```

## Output for Sample Input

```
2
```

## Explanation for Sample Input

The permutations "aba" and "baa" each appear as substrings of H (the former appears twice), 
while the permutation "aab" does not appear.
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

const int max_input_len = 200000;
int needle_len;
int haystack_len;
char *needle;
char *haystack;
int permutations_found;

void get_input(char dest[], int *len_var)
{
    scanf("%s", dest);
    for(int i = 0; i < max_input_len; i++)
    {
        if(dest[i] == 0)
        {
            *len_var = i;
            break;
        }
    }
}

void swap(char *first, char *second)
{
    char temp = *first;
    *first = *second;
    *second = temp;
}

// Source: https://www.geeksforgeeks.org/distinct-permutations-string-set-2/
void permute(int i, char a[], int n)
{
    if(i == n)
    {
        for(int w = 0; w <= haystack_len-needle_len; w++)
        {
            for(int k = 0; k < needle_len; k++)
            {
                if(haystack[w+k] != a[k])
                {
                    //w+=k;
                    break;
                }
                else if(k == needle_len-1)
                {
                    permutations_found++;
                    return;
                }
            }
        }
        return;
    }

    char prev = '*';

    for(int j = i; j < n; j++)
    {
        char temp[n];
        memcpy(&temp, a, n);
        if(j > i && a[i] == a[j])
        {
            continue;
        }
        if(prev != '*' && prev == a[j])
        {
            continue;
        }

        swap(&a[i], &a[j]);
        prev = a[j];
        permute(i + 1, a, n);
    }
}

void second_permute(char a[], int size, int n)
{
    if(size == 1)
    {
        for(int w = 0; w <= haystack_len-needle_len; w++)
        {
            for(int k = 0; k < needle_len; k++)
            {
                if(haystack[w+k] != a[k])
                {
                    //w+=k-1;
                    break;
                }
                else if(k == needle_len-1)
                {
                    permutations_found++;
                    return;
                }
            }
        }
        return;
    }

    for(int i = 0; i < size; i++)
    {
        second_permute(a, size-1, n);

        if(size % 2 == 1)
        {
            swap(&a[0], &a[size-1]);
        }
        else
        {
            swap(&a[i], &a[size-1]);
        }
    }
}

int pstrcmp( const void* a, const void* b )
{
  return strcmp( *(const char**)a, *(const char**)b );
}

int main()
{
    permutations_found = 0;
    needle = (char*)malloc(sizeof(char)*max_input_len);
    haystack = (char*)malloc(sizeof(char)*max_input_len);
    get_input(needle, &needle_len);
    get_input(haystack, &haystack_len);

    if(needle_len <= haystack_len)
    {
        permute(0, needle, needle_len);
        //second_permute(needle, needle_len, needle_len);
    }
    printf("%d\n", permutations_found);
    return 0;
}

