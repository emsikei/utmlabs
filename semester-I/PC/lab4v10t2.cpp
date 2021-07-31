#include <iostream>
#include <ctime>
#include <iomanip>
using namespace std;

void printMenu();
int inputInt();
void allocate(int ***A, int N, int M);
void fillRand(int **A, int N, int M);
void fillUser(int **A, int N, int M);
void printArr(int **A, int N, int M);
void freeArr(int **A, int N);
void sortArr(int **A, int N, int M);
void exitProg();

int main()
{
    int **A, N, M;
    printMenu();
    int choice;
    cout << "Выберите пункт меню: ";
    choice = inputInt();

    bool isActive = false;
    bool isFree = false;
    while (!isActive)
    {
        if (choice == 1)
        {
            isActive = true;
            cout << "Введите количество строк: ";
            N = inputInt();
            cout << "Введите количество столбцов: ";
            M = inputInt();
            allocate(&A, N, M);
        }
        else
        {
            cout << "Необходимо активировать первый пункт меню. Нажмите 1: ";
            choice = inputInt();
        }

        while (isActive)
        {
            cout << "Выберите следующий пункт меню: ";
            choice = inputInt();

            if (choice == 1)
            {

                if (isFree)
                {
                    cout << "Введите количество строк: ";
                    N = inputInt();
                    cout << "Введите количество столбцов: ";
                    M = inputInt();
                    allocate(&A, N, M);
                    isFree = false;
                }
                else
                {
                    while (choice != 6)
                    {
                        cout << "Перед выделением памяти под новый массив необходимо осбодить выделенную память под старый массив! Для этого нажмите 6: ";
                        choice = inputInt();
                    }
                }
            }

            if (choice == 2)
            {
                fillUser(A, N, M);
                choice = inputInt();
            }
            else if (choice == 3)
            {
                fillRand(A, N, M);
            }
            else if (choice == 4)
            {
                sortArr(A, N, M);
            }
            else if (choice == 5)
            {
                printArr(A, N, M);
            }
            else if (choice == 6)
            {
                freeArr(A, N);
                isFree = true;
            }
            else if (choice == 7)
            {
                if (isFree)
                {
                    exitProg();
                }
                else
                {
                    cout << "Перед завершением программы необходимо освободить память! Для этого нажмите 6: ";
                    choice = inputInt();
                    if (choice == 6)
                    {
                        freeArr(A, N);
                        isFree = true;
                        exitProg();
                    }
                }
            }
        }
    }
}

void printMenu()
{
    cout << "1. Динамическое выделение памяти для двумерного массива" << endl;
    cout << "2. Ввод элементов массива с клавиатуры" << endl;
    cout << "3. Заполнение массива случайными числами" << endl;
    cout << "4. Сортировка элементов массива" << endl;
    cout << "5. Вывод элементов массива на экран" << endl;
    cout << "6. Освобождение памяти, выделенной для массива" << endl;
    cout << "7. Окончание работы программы" << endl;
}

int inputInt()
{
    char s[100];
    scanf("%s", s);
    int num;
    while (sscanf(s, "%d", &num) != 1)
    {
        printf("Неправильный ввод. Повторите: ");
        scanf("%s", s);
    }
    return num;
}

void allocate(int ***A, int N, int M)
{
    *A = new int *[N];
    for (int i = 0; i < N; ++i)
    {
        (*A)[i] = new int[M];
    }
}

void fillRand(int **A, int N, int M)
{
    srand(time(0));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            A[i][j] = -5 + rand() % 15;
}

void fillUser(int **A, int N, int M)
{
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            cout << "A[" << i << "][" << j << "] = ";
            A[i][j] = inputInt();
        }
        cout << endl;
    }
}

void sortArr(int **A, int N, int M)
{
    int tmp = 0;
    int i, j, k = 0;
    for (j = 1; j <= M; j += 2)
    {
        for (i = 0; i < N; ++i)
        {
            for (k = i + 1; k < N; ++k)
            {
                if (A[i][j] < A[k][j])
                {
                    tmp = A[i][j];
                    A[i][j] = A[k][j];
                    A[k][j] = tmp;
                }
            }
        }
    }
}

void printArr(int **A, int N, int M)
{
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            cout << A[i][j] << setw(2) << "\t";
        }
        cout << endl;
    }
}

void freeArr(int **A, int N)
{
    for (int i = 0; i < N; ++i)
    {
        delete[] A[i];
    }
    delete[] A;
}

void exitProg()
{
    cout << "Программа успешно завершена";
    exit(0);
}




