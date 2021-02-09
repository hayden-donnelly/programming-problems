#include<stdio.h>

const int max_input_len = 200000;
static char input[max_input_len];
static char n[max_input_len];
int n_len = 0;
static char h[max_input_len];
int h_len = 0;

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

int main()
{
    get_input(n, &n_len);
    get_input(h, &h_len);

    for(int x = 0; x < h_len; x++)
    {
        for(int y = 0; y < n_len; y++)
        {

        }
    }
}

