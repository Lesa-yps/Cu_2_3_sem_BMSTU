#include "calc.h"

int calc_mean_n(FILE *file, double *mean, long int *n)
{
    double sum = 0.0;
    double x;
    int rc;
    *n = 0;

    while (!feof(file))
    {
        rc = fscanf(file, "%lf", &x);
        if (rc != 1 && !feof(file))
            return ERR_NUM;
        else if (rc == 1)
        {
            sum += x;
            (*n)++;
        }
    }
    if (*n == 0)
        return EMPTY;

    if (*n == 1)
        return ONLY1;

    *mean = sum / (*n);

    return OK;
}

double calc_stdev(FILE *file, double mean, long int n, int *err)
{
    double stdev;
    double x;
    double sum = 0;
    *err = 0;

    for (long int i = 0; i < n; i++)
    {
        fscanf(file, "%lf", &x);
        sum += (x - mean) * (x - mean);
    }

    stdev = sqrt(sum / n);

    if ((stdev < EPS) && (stdev > -EPS))
        *err = NULL_STDEV;

    return stdev;
}

int calc_res(FILE *file, double mean, double stdev, long int n)
{
    double max_dev = mean + 3 * stdev;
    double min_dev = mean - 3 * stdev;
    double x;
    long int count = 0;

    for (long int i = 0; i < n; i++)
    {
        fscanf(file, "%lf", &x);
        if (x < min_dev || max_dev < x)
        {
            count++;
            return 0;
        }
    }

    return 1;
}
