/*
# Ragaman

Problem is from the Canadian Computing Competition's online grader.\

Time limit: 3 seconds.

All test cases passed.

## Problem Description

An anagram of a string is formed by rearranging the letters in the string. 
For example, the anagarams of aab are aab, aba, and baa.

A wildcard anagram of a string is an anagram of the string where some of the letters 
might have been replaced with an asterisk (\*). For example, two possible anagrams of 
aab are \*ab and \*b\*.

Given two strings, determine whether the second string is a wildcard anagram of the 
first string.

## Input Specification

The first two lines of input will both consist of N (1 ≤ N ≤ 100) characters. Each character 
in the first line will be a lowercase letter. Each character in the second line will be either 
a lowercase letter or an asterisk.

For 8 of the 15 available marks, the second line will not contain any asterisk characters.

## Output Specification

Output the character A if the string on the second line is a wildcard anagram of the string 
on the first line. Other wise, output the character N.

## Sample Input 1

```
abba
baaa
```

## Output for Sample Input 1

```
N
```

## Sample Input 2

```
cccrocks
socc*rk*
```

## Output for Sample Input 2

```
A
```
*/

#include<stdio.h>

char first[100];
char second[100];

int main()
{
    scanf("%s", first);
    scanf("%s", second);

    int asterisk_count = 0;
    int characters_removed = 0;
    int i = 0;
    for(i = 0; first[i] != 0; i++)
    {
        if(second[i] == '*')
        {
            asterisk_count++;
        }
        else
        {
            for(int k = 0;; k++)
            {
                if(first[k] == 0)
                {
                    printf("N\n");
                    return 0;
                }
                else if(second[i] == first[k])
                {
                    first[k] = '.';
                    characters_removed++;
                    break;
                }
            }
        }
    }

    if(asterisk_count == i-characters_removed)
    {
        printf("A\n");
        return 0;
    }
    printf("N\n");
    return 0;
}
