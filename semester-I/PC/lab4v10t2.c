#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>

#define BUFF_SIZE 15

void printMenu();
int inputData(int num, char input[]);
int allocate(int **A, int N, int M);
void fillRand(int **A, int N, int M);
void fillUser(int **A, int N, int M);
void print(int **A, int N, int M);
void freeArr(int **A, int N);
void exitProg();

int main()
{
    char input[BUFF_SIZE];
    int **A, N, M;
    printMenu();
    int choice;
    printf("Выберите пункт меню: ");
    choice = inputData(choice, input);

    bool isActive = false;
    while (!isActive)
    {
        if (choice == 1)
        {
            isActive = true;
            printf("Введите количество строк: ");
            N = inputData(N, input);
            printf("Введите количество столбцов: ");
            M = inputData(M, input);
            A = allocate(A, N, M);
        }
        else
        {
            printf("Необходимо активировать первый пункт меню. Нажмите 1: ");
            choice = inputData(choice, input);
        }
    }

    bool isFree = false;
    while (isActive)
    {
        printf("Выберите следующий пункт меню: ");
        choice = inputData(choice, input);
        
        if (choice == 2)
        {
            fillUser(A, N, M);
            choice = inputData(choice, input);
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
                printf("Перед завершением программы необходимо освободить память! Для этого нажмите 6: ");
                choice = inputData(choice, input);
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

int inputData(int res, char input[])
{
    fgets(input, BUFF_SIZE, stdin);
    sscanf(input, "%d", &res);
    memset(input, 0, BUFF_SIZE);

    while (res == 0)
    {
        printf("Неправильный ввод! Введите целое число: ");
        fgets(input, BUFF_SIZE, stdin);
        sscanf(input, "%d", &res);
        memset(input, 0, BUFF_SIZE);
    }
    return res;
}

void printMenu()
{
    printf("1. Динамическое выделение памяти для двумерного массива\n");
    printf("2. Ввод элементов массива с клавиатуры\n");
    printf("3. Заполнение массива случайными числами\n");
    printf("4. Сортировка элементов массива\n");
    printf("5. Вывод элементов массива на экран\n");
    printf("6. Освобождение памяти, выделенной для массива\n");
    printf("7. Окончание работы программы\n");
}

int allocate(int **A, int N, int M)
{
    A = (int **)malloc(N * sizeof(int *));
    for (int i = 0; i < N; ++i)
    {
        A[i] = (int *)malloc(M * sizeof(int));
    }
    return A;
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
            printf("A[%d][%d] = ", i, j);
            scanf("%d", &A[i][j]);
        }
        printf("\n");
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
            printf("%2d\t", A[i][j]);
        }
        printf("\n");
    }
}

void freeArr(int **A, int N)
{
    for (int i = 0; i < N; ++i)
    {
        free(A[i]);
    }
    free(A);
}

void exitProg() {
    printf("Программа успешно завершена!");
    exit(0);
}