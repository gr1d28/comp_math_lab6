#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

const double PI = 3.14159265358979323846;

double getrand()
{
    return (double)rand() / RAND_MAX;
}

double func(double x, double y)
{
    return exp(x - y);
}

void monte_karlo(int degree)
{
    int n;
    if (degree == 1)
    {
        n = 10000000;
    }
    else if (degree == 2)
    {
        n = 100000000;
    }
    printf("Numerical integration by Monte Carlo method: n = %d\n", n);

    int in = 0;
    double s = 0;
    
    for (int i = 0; i < n; i++)
    {
        double x = getrand() - 1;
        double y = getrand();
        if (y <= 1)
        {
            in++;
            s += func(x, y);
        }
    }

    double v = PI * in / n;
    double res = v * s / in;
    printf("Result: %.12f, n %d\n", res, n);
}

int main()
{
    monte_karlo(1);
    monte_karlo(2);

    return 0;
}