#include <cstdio>
#include <math.h>

int main()
{
    float a = 0;
    float b = 0;
    float c = 0;
    float d;
    double x1, x2;

    std::puts("enter the coefficients of the square equation separated by a space");
    std::scanf("%f %f %f", &a, &b, &c);

    d = b * b - 4 * a * c;

    if (d < 0)
    {
        std::puts("negative discriminant");
    }
    else
    {
        x1 = (-b + sqrt(d)) / (2 * a);
        x2 = (-b - sqrt(d)) / (2 * a);
        if (x1 == x2)
        {
            std::printf("Solution is x1 = x2 = %lf\n", x1);
        }
        else
        {
            std::printf("Solution is x1 = %lf and x2 = %lf\n", x1, x2);
        }
    }
}