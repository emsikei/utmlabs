#include <iostream>
#include <string>
using namespace std;

#define N 8

struct trafic
{
    string begst;
    string term;
    int numer;
} tmpMarsh, marsh[N];

int main()
{
    for (int i = 0; i < N; ++i)
    {
        cout << "Запись #" << i + 1 << ". Введите начальный, конечный пункт маршрута и его номер: ";
        cin >> marsh[i].begst >> marsh[i].term >> marsh[i].numer;
    }

    for (int i = 0; i < N; ++i)
    {
        for (int j = i + 1; j < N; ++j)
        {
            if (marsh[i].numer > marsh[j].numer)
            {
                tmpMarsh = marsh[i];
                marsh[i] = marsh[j];
                marsh[j] = tmpMarsh;
            }
        }
    }

    for (int i = 0; i < N; ++i)
    {
        cout << " " << marsh[i].begst << " -> " << marsh[i].term << " (№" << marsh[i].numer << ")" << endl;
    }

    cout << "Номер какого маршрута вам интересен?: "; 
    int ask;
    cin >> ask;
    bool isMarsh = false;
    for (int i = 0; i < N; ++i)
    {
        if (ask == marsh[i].numer)
        {
            isMarsh = true;
            cout << " " << marsh[i].begst << " -> " << marsh[i].term << " (№" << marsh[i].numer << ")" << endl;
        }
    }

    if (!isMarsh)
    {
        cout << "Информации о данном маршруте не обнаружено";
    }

    system("pause");
    return 0;
}