#include <iostream>
#include <math.h>

//? E = 0.1 * 10 ^ (-1)
//? E = 0.1 * 10 ^ (-2)
//? E = 0.1 * 10 ^ (-3)

//! f(x) = 4x^3 - 6x^2 - 6x = 0
// a = -2.5, b = 2.5

//* f(x) = 4*pow(x, 3) - 6 * pow(x, 2) - 6 * x

double func(double x);
double chordeMethod(int &a, int &b, double E);

int main()
{
    int a = -3;
    int b = 3;
    double E = 0.01;
    double x = 0.0;

    if (func(a) * func(b) > 0)
    {
        std::cout << "Wrong Interval!";
        return 0;
    }

    x = chordeMethod(a, b, E);

    std::cout << x << "\n";
}

double func(double x)
{
    return 4 * pow(x, 3) - 6 * pow(x, 2) - 6 * x;
}

double chordeMethod(int &a, int &b, double E)
{
    // int x;
    // while (abs(func(b) - func(a)) > E)
    // {
    //     x = (func(b) * a - func(a) * b) / (func(b) - func(a));
    //     if ((func(a) * func(x)) > 0)
    //     {
    //         a = x;
    //     }
    //     else
    //     {
    //         b = x;
    //     }
    // }
    // return x;

    double x;
    int N = 0;
    while (abs(func(b) - func(a)) > E)
    {
        x = (func(b) * a - func(a) * b) / (func(b) - func(a));
        if ((func(a) * func(x)) > 0)
            a = x;
        else
            b = x;
        N++;
    }
    return x;
}