#include <iostream>
using namespace std;

int **mas, n, m, i, j, k, tmp;
int main()
{
    cout << "Введите количество строк массива: " << endl;
    cin >> n;
    cout << "Введите количество столбцов массива: " << endl;
    cin >> m;

    mas = new int *[n];
    for (i = 0; i < n; i++)
    {
        mas[i] = new int[m];
    }

    cout << "Введите элементы массива: " << endl;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            cout << "[" << i << "][" << j << "]= ";
            cin >> mas[i][j];
        }
    }

    cout << "\nИсходный массив" << endl;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            cout << mas[i][j] << "\t";
        }
        cout << endl;
    }

    for (i = 0; i < n; i++)
    {
        tmp = 0;
        for (j = 0; j < m; j++)
            if (mas[i][j] != 0)
            {
                tmp = 1;
            }

        if (tmp == 0)
        {
            for (k = i; k < n - 1; k++)
            {
                for (j = 0; j < m; j++)
                {
                    mas[k][j] = mas[k + 1][j];
                }
            }
            n--;
        }
    }

    for (j = 0; j < m; j++)
    {
        tmp = 0;
        for (i = 0; i < n; i++)
            if (mas[i][j] != 0)
            {
                tmp = 1;
            }
        if (tmp == 0)
        {
            for (k = j; k < m - 1; k++)
            {
                for (i = 0; i < n; i++)
                {
                    mas[i][k] = mas[i][k + 1];
                }
            }
            m--;
        }
    }
    cout << endl;

    cout << "Полученный массив" << endl;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            cout << mas[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;

    int counter = m;
    for (j = 0; j < m; ++j)
    {
        for (i = 0; i < n; ++i)
        {
            if (mas[i][j] == 0)
            {
                counter--;
                break;
            }
        }
    }

    cout << "Кол-во столбцов без 0: " << counter << "\n" << endl;

    const int SUM_SIZE = n;
    int sum[SUM_SIZE];
    i = 0;
    for (k = 0; k < n; ++k)
    {
        for (i, j = 0, sum[i] = 0; j < m; ++j)
        {
            if (mas[i][j] > 0 && mas[i][j] % 2 == 0)
            {
                sum[i] += mas[i][j];
            }
        }
        ++i;
    }

    for (i = 0; i < n; ++i)
    {
        cout << "Сумма " << i + 1 << "-ой" << " строки: " << sum[i] << endl;
    }
    cout << "\n";

    tmp = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = n - 1; j >= i; j--)
        {
            if (sum[j] < sum[j - 1])
            {
                for (int k = 0; k < m; ++k)
                {
                    tmp = mas[j][k];
                    mas[j][k] = mas[j - 1][k];
                    mas[j - 1][k] = tmp;
                }
                tmp = sum[j];
                sum[j] = sum[j - 1];
                sum[j - 1] = tmp;
            }
        }
    }

    cout << "Отсортированные по возрастанию характеристики: ";
    for (i = 0; i < n; ++i)
    {
        cout << sum[i] << "  ";
    }
    cout << "\n\n";

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            cout << mas[i][j] << "\t";
        }
        cout << endl;
    }

    cout << endl;
    system("pause");
    return 0;
}