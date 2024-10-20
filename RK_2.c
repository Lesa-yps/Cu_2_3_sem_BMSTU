#include <stddef.h>
#include <stdio.h>
#include <string.h>

#define COUNT 10
#define MAX_LEN 15

#define OK 0
#define ERR 1
#define EPS 0.5

struct tovar
{
	char name[MAX_LEN];
	double price;
	int colvo;
};

int reading(FILE *file, struct tovar tovs[], size_t *n);
void choose(struct tovar tovs[], size_t *n);
void print_bin(FILE *file_bin, struct tovar tovs[], size_t n);
void read_bin(FILE *file_bin, struct tovar tovs[], size_t *n);
void print(FILE *file, struct tovar tovs[], size_t n);

int main(void)
{
	FILE *file;
	FILE *file_bin;
	size_t n;
	struct tovar tovs[COUNT];

	file = fopen("first.txt", "r");
	if (file == NULL)
		return ERR;
        if (reading(file, tovs, &n) != OK)
            return ERR;
	fclose(file);

	choose(tovs, &n);

	file_bin = fopen("second.bin", "wb");
	if (file_bin == NULL)
		return ERR;
	print_bin(file_bin, tovs, n);
	fclose(file_bin);

	file_bin = fopen("second.bin", "rb");
	if (file_bin == NULL)
		return ERR;
	read_bin(file_bin, tovs, &n);
	fclose(file_bin);

	file = fopen("result.txt", "w");
	if (file == NULL)
		return ERR;
	print(file, tovs, n);
	fclose(file);

	return OK;
}

int reading(FILE *file, struct tovar tovs[], size_t *n)
{
    *n = 0;
    char x;
    while(fscanf(file, "%s%lf%d", tovs[*n].name, &tovs[*n].price, &tovs[*n].colvo) == 3)
    {
        strcat(tovs[*n].name, "\0");
        (*n)++;
    }
    fscanf(file, "%c", &x);
    if (x == EOF)
        return ERR;
    return OK;
}

void choose(struct tovar tovs[], size_t *n)
{
	double maxi = 0.0;
	for (size_t i = 0; i < *n; i++)
		if ((tovs[i].price * tovs[i].colvo) > maxi || i == 0)
			maxi = tovs[i].price * tovs[i].colvo;

	size_t j = 0;
	size_t k;
	while (j < *n)
        {
                if ((tovs[j].price * tovs[j].colvo) + EPS < maxi)
		{
			k = j;
			while (k < (*n - 1))
                        {
                                tovs[k] = tovs[k + 1];
                                k++;
                        }
			j--;
			(*n)--;
		}
		j++;
	}
}

void print_bin(FILE *file_bin, struct tovar tovs[], size_t n)
{
	fwrite(tovs, sizeof(struct tovar), n, file_bin);
}

void read_bin(FILE *file_bin, struct tovar tovs[], size_t *n)
{
	*n = 0;
	while (fread(&tovs[*n], sizeof(struct tovar), 1, file_bin) == 1)
		(*n)++;
}

void print(FILE *file, struct tovar tovs[], size_t n)
{
	for (size_t i = 0; i < n; i++)
		fprintf(file, "%s %lf %d\n", tovs[i].name, tovs[i].price, tovs[i].colvo);
}

