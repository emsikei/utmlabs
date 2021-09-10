#include <iostream>
#include <math.h>

//? E = 0.1 * 10 ^ (-1)
//? E = 0.1 * 10 ^ (-2)
//? E = 0.1 * 10 ^ (-3)

//! f(x) = 4x^3 - 6x^2 - 6x = 0
// a = -2.5, b = 2.5

//* f(x) = 4*pow(x, 3) - 6 * pow(x, 2) - 6 * x

double func(double x);
double chordeMethod(double a, double b, double E);

int main()
{
    int a = -3;
    int b = 3;
    double E = 0.01;
    double x = 0.0;

    x = chordeMethod(a, b, E);

    std::cout << x << "\n";
}

double f(double x)
{
    return 4 * pow(x, 3) - 6 * pow(x, 2) - 6 * x;
}

double chordeMethod(double a, double b, double E)
{
    double t;
    while (fabs(b - a) >= E)
    {
        t = a + (f(b) * (b - a)) / (f(b) - f(a));
        if (f(a) * f(t) < 0)
        {
            b = t;
            std::cout << "b = " << b << "\n";
        }
        else if (f(t) * f(b) < 0)
        {
            a = t;
            std::cout << "a = " << a << "\n";
        }
        else
            return t;
    }
    return t;
}