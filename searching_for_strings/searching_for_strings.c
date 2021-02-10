#include<stdio.h>
#include<stdlib.h>
#include<string.h>

const int max_input_len = 200000;
int needle_len;
int haystack_len;
char *needle;
char *haystack;
char **needle_permutations;
int current_permutation;
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
        needle_permutations[current_permutation] = (char*)malloc(sizeof(char)*n);
        for(int i = 0; i < n; i++)
        {
            needle_permutations[current_permutation][i] = a[i];
        }
        current_permutation++;
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

        swap(&temp[i], &temp[j]);
        prev = a[j];
        permute(i + 1, temp, n);
    }
}

void check_for_permutation(int i)
{
    for(int k = 0; k < current_permutation; k++)
    {
        if(needle_permutations[k] == NULL)
        {
            continue;
        }
        for(int w = 0; w < needle_len; w++)
        {
            if(haystack[i+w] != needle_permutations[k][w])
            {
                break;
            }
            else if(w == needle_len-1)
            {
                permutations_found++;
                needle_permutations[k] = NULL;
                return;
            }
        }
    }
}

int main()
{
    permutations_found = 0;
    needle = (char*)malloc(sizeof(char)*max_input_len);
    haystack = (char*)malloc(sizeof(char)*max_input_len);
    get_input(needle, &needle_len);
    get_input(haystack, &haystack_len);

    int needle_len_fact = needle_len;
    for(int i = needle_len-1; i > 0; i--)
    {
        needle_len_fact *= i;
    }
    needle_permutations = (char**)malloc(sizeof(char*)*needle_len_fact);

    permute(0, needle, needle_len);

    for(int i = 0; i <= haystack_len-needle_len; i++)
    {
        check_for_permutation(i);
    }
    printf("%d\n", permutations_found);
    return 0;
}

