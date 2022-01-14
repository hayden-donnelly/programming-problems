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

