#include <iostream>
#include <cmath>

double func(double x);
double funcDerivativeOne(double x);
double funcDerivativeTwo(double x);

double NewtonMethod(double a, double b, double Eps);
double hordeMethod(double a, double b, double Eps);
double secantMethod(double a, double b, double Eps);

void inputData(double &a, double &b);
void getResults(double a, double b, double x);

int main()
{
    double a = 0.0;
    double b = 0.0;

    double x = 0.0;

    inputData(a, b);
    getResults(a, b, x);

    while (true)
    {
        char decision;
        std::cout << "Do you want to continue? Y/N: ";
        std::cin >> decision;
        switch (decision)
        {
        case 'Y':
        case 'y':
            inputData(a, b);
            getResults(a, b, x);
            break;
        case 'N':
        case 'n':
            return 0;
        }
    }
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

double NewtonMethod(double a, double b, double Eps)
{
    // if (func(a) * func(b) > 0)
    // {
    //     std::cout << "Wrong Interval\n";
    //     return 0;
    // }
    double x_current = 0.0;
    double x_next = 0.0;

    int k = 0;

    if (func(a) * funcDerivativeTwo(a) > 0)
    {
        x_current = a;
    }
    else
    {
        x_current = b;
    }

    x_next = x_current - (func(x_current) / funcDerivativeOne(x_current));
    k++;

    while (fabs(x_next - x_current) > Eps)
    {
        x_current = x_next;
        x_next = x_current - (func(x_current) / funcDerivativeOne(x_current));
        k++;
    }

    std::cout << "x = " << x_next << ";\t"
              << "f(x) = " << func(x_next) << ";\t "
              << "Epsilon = " << Eps << ";\t" << k << " iterations";
    return x_next;
}

double hordeMethod(double a, double b, double Eps)
{
    // if (func(a) * func(b) > 0)
    // {
    //     std::cout << "Wrong Interval\n";
    //     return 0;
    // }

    double x = 0.0;
    int k = 0;

    do
    {
        x = a - ((b - a) * func(a)) / (func(b) - func(a));
        if (func(a) * func(b) <= 0)
        {
            b = x;
            k++;
        }
        else
        {
            a = x;
            k++;
        }
    } while (fabs(func(x)) > Eps);

    std::cout << "x = " << x << ";\t"
              << "f(x) = " << func(x) << ";\t "
              << "Epsilon = "
              << Eps << ";\t" << k << " iterations";

    return x;
}

double secantMethod(double a, double b, double Eps)
{
    // if (func(a) * func(b) > 0)
    // {
    //     std::cout << "Wrong Interval\n";
    //     return 0;
    // }

    double x_current = 0.0;
    double x_next = 0.0;
    double x_prev = 0.0;

    int k = 0;

    if (func(a) * funcDerivativeTwo(a) > 0)
    {
        x_prev = a;
        x_current = a + Eps;
    }
    else
    {
        x_prev = b;
        x_current = b - Eps;
    }

    x_next = x_current - (func(x_current) * (x_current - x_prev)) / (func(x_current) - func(x_prev));
    k++;

    while (fabs(x_next - x_current) > Eps)
    {
        x_prev = x_current;
        x_current = x_next;
        x_next = x_current - (func(x_current) * (x_current - x_prev)) / (func(x_current) - func(x_prev));
        k++;
    }

    std::cout << "x = " << x_next << ";\t"
              << "f(x) = " << func(x_next) << ";\t "
              << "Epsilon = " << Eps << ";\t" << k << " iterations";
    return x_next;
}

void getResults(double a, double b, double x)
{
    int i = -1;
    while (i >= -3)
    {
        double Eps = 0.1 * pow(10, i);

        std::cout << "Horde Method\t";

        x = hordeMethod(a, b, Eps);

        std::cout << "\n";

        std::cout << "Newton Method\t";
        x = NewtonMethod(a, b, Eps);

        std::cout << "\n";

        std::cout << "Secant Method\t";
        x = secantMethod(a, b, Eps);

        std::cout << "\n\n";

        i--;
    }
}

void inputData(double &a, double &b)
{
    std::cout << "Enter interval [a, b]: ";
    std::cin >> a >> b;
    std::cout << "\n";

    while (func(a) * func(b) > 0)
    {
        std::cout << "Wrong interval. Enter another one: ";
        std::cin >> a >> b;
        std::cout << "\n";
    }
}