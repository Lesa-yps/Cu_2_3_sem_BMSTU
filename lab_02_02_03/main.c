//including header files
#include <stdio.h>
#include <stddef.h>
#include <math.h>

//creating macros
#define MAX_LEN 10
#define OK 0
#define ERR_LEN 1
#define ERR_ELEM 2
#define NO 3
#define NOT_ARM 4

//function declarations
int read(int a[], size_t *n_a);

int made_b(int a[], int b[], size_t n_a, size_t *n_b);

void print(int b[], size_t n_b);

//main function
int main(void)
{
    int a[MAX_LEN];
    int b[MAX_LEN];
    size_t n_a;
    size_t n_b;
    int ind_b;
    int ind_a = read(a, &n_a);
    if (ind_a != OK)
    {
        if (ind_a == ERR_LEN)
            printf("Error with scanf len of list.\n");
        else
            printf("Error with scanf elements of list.\n");
        return ind_a;
    }
    ind_b = made_b(a, b, n_a, &n_b);
    if (ind_b == NO)
    {
        printf("In list a no Armstrong's numbers.\n");
        return NO;
    }
    print(b, n_b);
    return OK;
}

//the function reads the number of array elements and the array elements themselves
int read(int a[], size_t *n_a)
{
    printf("Input size of list: ");
    if (scanf("%lu", n_a) != 1 || *n_a > MAX_LEN || *n_a < 1)
        return ERR_LEN;
    printf("Input elements of list (int):\n");
    for (size_t i = 0; i < *n_a; i++)
        if (scanf("%d", &a[i]) != 1)
            return ERR_ELEM;
    return OK;
}

//function checks if a number is an Armstrong number
int arm(int x)
{
    if (x < 0)
        return NOT_ARM;
    int count = 0;
    int sum = 0;
    int h = 1;
    int slag;
    while (x > pow(10, count))
        count++;
    for (int i = 0; i < count; i++)
    {
        slag = 1;
        for (int j = 0; j < count; j++)
            slag *= x % (h * 10) / h;
        sum += slag;
        h *= 10;
    }
    if (x == sum)
        return OK;
    return NOT_ARM;
}

//function creates a new array of Armstrong numbers
int made_b(int a[], int b[], size_t n_a, size_t *n_b)
{
    *n_b = 0;
    for (size_t i = 0; i < n_a; i++)
        if (arm(a[i]) == 0)
            b[(*n_b)++] = a[i];
    if (*n_b == 0)
        return NO;
    return OK;
}

//function outputs a new array
void print(int b[], size_t n_b)
{
    printf("New list:\n");
    for (size_t i = 0; i < n_b; i++)
        printf("%d ", b[i]);
    printf("\n");
}
