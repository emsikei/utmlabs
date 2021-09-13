#include <iostream>
#include <math.h>

//* 1. Метод Ньютона
//* 2. Метод хорд (1-ая формула)
//* 3. Метод секущих

//? E = 0.1 * 10 ^ (-1)
//? E = 0.1 * 10 ^ (-2)
//? E = 0.1 * 10 ^ (-3)

//! f(x) = 4x^3 - 6x^2 - 6x = 0
// a = -2.5, b = 2.5

//* f(x) = 4*pow(x, 3) - 6 * pow(x, 2) - 6 * x

double func(double x);
double funcDerivativeOne(double x);
double funcDerivativeTwo(double x);

double NewtonMethod(double a, double b, double E);
double chordeMethod(double a, double b, double E);
double secantMethod(double a, double b, double E);

int main()
{
    double a = -2.5;
    double b = 2.5;
    double E = 0.0001;
    double x = 0.0;

    std::cout << "Chorde Method\t";

    x = chordeMethod(a, b, E);

    std::cout << "\n";

    std::cout << "Newton Method\t";
    x = NewtonMethod(a, b, E);

    std::cout << "\n";

    std::cout << "Secant Method\t";
    x = secantMethod(a, b, E);
}

double func(double x)
{
    return 4 * pow(x, 3) - 6 * pow(x, 2) - 6 * x;
}

double funcDerivativeOne(double x)
{
    return 12 * x * x - 12 * x - 6;
}
double funcDerivativeTwo(double x)
{
    return 24 * x - 12;
}

double NewtonMethod(double a, double b, double E)
{
    if (func(a) * func(b) > 0)
    {
        std::cout << "Wrong Interval\n";
        return 0;
    }
    double x_current = 0.0;
    double x_next = 0.0;

    int k = 0;

    if (func(x_current) * funcDerivativeTwo(x_current) > 0)
    {
        x_current = a;
    }
    else
    {
        x_current = b;
    }

    x_next = x_current - (func(x_current) / funcDerivativeOne(x_current));
    k++;

    while (fabs(x_next - x_current) > E)
    {
        x_current = x_next;
        x_next = x_current - (func(x_current) / funcDerivativeOne(x_current));
        k++;
    }

    std::cout << "x = " << x_next << ";\t"
              << "f(x) = " << func(x_next) << ";\t " << k << " iterations";
    return x_next;
}

double chordeMethod(double a, double b, double E)
{
    if (func(a) * func(b) > 0)
    {
        std::cout << "Wrong Interval\n";
        return 0;
    }

    double x = 0.0;
    int k = 0;

    do
    {
        x = a - ((b - a) * func(a)) / (func(b) - func(a));
        if (func(a) * func(b) < 0)
        {
            b = x;
            k++;
        }
        else
        {
            a = x;
            k++;
        }
    } while (fabs(func(x)) > E);

    std::cout << "x = " << x << ";\t"
              << "f(x) = " << func(x) << ";\t " << k << " iterations";

    return x;
}

double secantMethod(double a, double b, double E)
{
    if (func(a) * func(b) > 0)
    {
        std::cout << "Wrong Interval\n";
        return 0;
    }
    double x_current = 0.0;
    double x_next = 0.0;
    double x_prev = 0.0;

    int k = 0;

    if (func(x_current) * funcDerivativeTwo(x_current) > 0)
    {
        x_prev = a;
        x_current = a + E;
    }
    else
    {
        x_prev = b;
        x_current = a - E;
    }

    x_next = x_current - (func(x_current) * (x_current - x_prev)) / (func(x_current) - func(x_prev));
    k++;

    while (fabs(x_next - x_current) > E)
    {
        x_prev = x_current;
        x_current = x_next;
        x_next = x_current - (func(x_current) * (x_current - x_prev)) / (func(x_current) - func(x_prev));
        k++;
    }

    std::cout << "x = " << x_next << ";\t"
              << "f(x) = " << func(x_next) << ";\t " << k << " iterations";
    return x_next;
}