//including header files
#include <stdio.h>
#include <stddef.h>

//creating macros
#define OK 0
#define ERR_LEN 1
#define ERR_ELEM 2

#define N_MAX 20

//function declarations
int read(int a[], size_t *n);
void adding(int a[], size_t *n);
void print(int a[], size_t n);

//main function
int main(void)
{
    int a[N_MAX];
    size_t n;
    int x = read(a, &n);
    if (x != OK)
    {
        if (x == ERR_LEN)
            printf("Error with scanf size of list.\n");
        else
            printf("Error with scanf elements of list.\n");
        return x;
    }
    adding(a, &n);
    print(a, n);
    return OK;
}

//the function returns the reverse of the number
int revers(int x)
{
    int new_x = 0;
    while (x > 0)
    {
        new_x *= 10;
        new_x += (x % 10);
        x /= 10; 
    }
    return new_x;
}

//the function adds after each positive number in the array its reverse
void adding(int a[], size_t *n)
{
    size_t count = 0;
    size_t save_n = *n;
    for (size_t i = 0; i < save_n; i++)
        if (a[i] > 0)
            count++;
    *n += count;
    int i = *n - 1;
    while (i >= 0)
    {
        if (a[i - count] > 0)
        {
            a[i] = revers(a[i - count]);
            a[i - 1] = a[i - count];
            i--;
            count--;
        }
        else
            a[i] = a[i - count];
        i--;
    }
}

//the function reads the number of array elements and the array elements themselves
int read(int a[], size_t *n)
{
    printf("Input size of list: ");
    if (scanf("%lu", n) != 1 || *n > (N_MAX / 2) || *n < 1)
        return ERR_LEN;
    printf("Input elements of list (int):\n");
    for (size_t i = 0; i < *n; i++)
        if (scanf("%d", &a[i]) != 1)
            return ERR_ELEM;
    return OK;
}

//function outputs the modified array
void print(int a[], size_t n)
{
    printf("Elements of list:\n");
    for (size_t i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}
