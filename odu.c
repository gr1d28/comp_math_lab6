#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

double func(double x, double y)
{
    return 6 * x * x + 5 * x * y;
}

void euler(double x, double y, int n)
{
    double const h = 0.01;

    printf("\tEuler method\n");

    for (int i = 0; i < n; i++)
    {
        x = x + h;
        y = y + h * func(x, y);

        printf("%d. x = %f, y = %f\n", i, x, y);
    }
}

void euler_cauchy(double x, double y, int n)
{
    double const h = 0.01;
    double y_s = 0;

    printf("\tEuler-Cauchy method\n");

    for (int i = 0; i < n; i++)
    {
        x = x + h;
        y_s = y + h * func(x, y);
        y = y + h / 2 * (func(x, y) + func(x + h, y_s));

        printf("%d. x = %f, y = %f\n", i, x, y);
    }
}

void runge_kutte(double x, double y, int n)
{
    double const h = 0.01;
    double delta = 0;
    double k[4];

    printf("\tRunge-Kutte method\n");

    for (int i = 0; i < n; i++)
    {
        k[0] = h * func(x, y);
        k[1] = h * func(x + h / 2, y + k[0] / 2);
        k[2] = h * func(x + h / 2, y + k[1] / 2);
        k[3] = h * func(x + h, y + k[2]);
        delta = (k[0] + 2 * k[1] + 2 * k[2] + k[3]) / 6;

        x = x + h;
        y = y + delta;

        printf("%d. x = %f, y = %f\n", i, x, y);
    }

}

int main()
{
    euler(1, 1, 10);
    euler_cauchy(1, 1, 10);
    runge_kutte(1, 1, 10);

    return 0;
}