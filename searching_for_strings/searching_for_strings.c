#include<stdio.h>

const int max_input_len = 200000;
static char input[max_input_len];
static char needle[max_input_len];
static char haystack[max_input_len];
int needle_len = 0;
int haystack_len = 0;

void get_input(char *dest, int *len_var)
{
    scanf("%s", input);
    for(int i = 0; i < max_input_len; i++)
    {
        if(input[i] == 0)
        {
            *len_var = i-1;
            break;
        }
        dest[i] = input[i];
    }
}

void print_array(char a[], int n)
{
    for(int i = 0; i < n; i++)
    {
        printf("%s ", a[i]);
    }
    printf("\n");
}

void swap(char *first, char *second)
{
    char *temp = first;
    first = second;
    second = temp;
}


// Heap's algo: https://www.geeksforgeeks.org/heaps-algorithm-for-generating-permutations/?ref=leftbar-rightbar
void heap_permutation(char a[], int size, int n)
{
    if(size == 1)
    {
        print_array(a, n);
        return;
    }

    for(int i = 0; i < size; i++)
    {
        heap_permutation(a, size-1, n);
    
        if(size % 2 == 1)
        {
            swap(a[0], a[size-1]);
        }
        else
        {
            swap(a[i], a[size-1]);
        }
    }
}

int main()
{
    get_input(needle, &needle_len);
    get_input(haystack, &haystack_len);

    heap_permutation(needle, needle_len, needle_len);
    return 0;
}

