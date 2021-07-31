#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int _get_random_range(int lower, int upper) {

    return lower + ( rand() % (upper - lower) );
}

int main()
{
    const int MAX_ROWS = 4;
    const int MAX_COLUMNS = 5;
    int m[MAX_ROWS][MAX_COLUMNS];
    int i, j;
   
    srand( time(0) );
    for (i = 0; i < MAX_ROWS; ++i) {
        for (j = 0; j < MAX_COLUMNS; ++j) {
            m[i][j] = _get_random_range(1, 10);
        }
    }
  
    for (i = 0; i < MAX_ROWS; ++i) {
        for (j = 0; j < MAX_COLUMNS; ++j) {
            printf("%d\t", m[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    int counter = MAX_COLUMNS;
    for (j = 0; j < MAX_COLUMNS; ++j) {
        for (i = 0; i < MAX_ROWS; ++i) {
            if (m[i][j] == 0) {
                counter--;
                break;
            }
        }
    }

    printf("Кол-во столбов без 0: %d\n\n", counter); 


    int sum[MAX_ROWS];
    int k;
    i = 0;
    for (k = 0; k < MAX_ROWS; ++k) {
        for (i, j = 0, sum[i] = 0; j < MAX_COLUMNS; ++j) {
            if (m[i][j] > 0 && m[i][j] % 2 == 0) {
                sum[i] += m[i][j];
            }
        }
        ++i;   
    }

    for (i = 0; i < MAX_ROWS; ++i) {
        printf("Сумма %d-ой строки: %d\n", i + 1, sum[i]);
    }
    printf("\n");

    int tmp;
    for (int i = 0; i < MAX_ROWS; ++i) {
        for (int j = MAX_ROWS - 1; j >= i; j--) {
            if (sum[j] < sum[j - 1]) {
                for (int k = 0; k < MAX_COLUMNS; ++k) {
                    tmp = m[j][k];
                    m[j][k] = m[j - 1][k];
                    m[j - 1][k] = tmp;  
                }
                tmp = sum[j];
                sum[j] = sum[j - 1];
                sum[j - 1] = tmp; 
                }
            }
    }

    printf("Отсортированные по возрастанию характеристики: ");
    for (i = 0; i < MAX_ROWS; ++i) {
        printf("%3d", sum[i]);
    }
    printf("\n\n");

    for (i = 0; i < MAX_ROWS; ++i) {
        for (j = 0; j < MAX_COLUMNS; ++j) {
            printf("%d\t", m[i][j]);
        }
        printf("\n");
    }
    return 0;
}


