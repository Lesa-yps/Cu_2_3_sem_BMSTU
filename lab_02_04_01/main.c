//including header files
#include <stdio.h>
#include <stddef.h>
#include <math.h>

//creating macros
#define N_MAX 10
#define OK 0
#define ERR_LEN 1
#define FLAG 100

//function declarations
int read(int a[], size_t *n);
void sort(int a[], size_t n);
void print(int a[], size_t n);

//main function
int main(void)
{
    int a[N_MAX];
    size_t n = 0;
    int res = read(a, &n);
    if (n == 0)
    {
        printf("Error: list is empty\n");
        return ERR_LEN;
    }
    sort(a, n);
    print(a, n);
    return res;
}

//the function reads the elements of the array by trailer
int read(int a[], size_t *n)
{
    *n = 0;
    printf("Input elements of list:\n");
    while (scanf("%d", &a[*n]) == 1)
    {
        (*n)++;
        if (*n == N_MAX)
            break;
    }
    int x;
    if ((scanf("%d", &x) == 1) && (*n == N_MAX))
        return FLAG;
    return OK;
}

//function sorts array by insertion method
void sort(int a[], size_t n)
{
    for (size_t i = 1; i < n; i++)
        for (size_t j = i; j > 0; j--)
            if (a[j] < a[j - 1])
            {
                int x = a[j];
                a[j] = a[j - 1];
                a[j - 1] = x;
            }
}

//function outputs sorted array
void print(int a[], size_t n)
{
    printf("Sorted list:\n");
    for (size_t i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}
