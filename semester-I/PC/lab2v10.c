#include <stdio.h>
#include <math.h>

int main() {
    const int MAX_SIZE = 15;
    float m[MAX_SIZE];
    int i;

    for (i = 0; i < MAX_SIZE; ++i) {
        printf("m[%d] = ", i);
        scanf("%f", &m[i]);
    }

    int iMin = 0;
    for (i = 0; i < MAX_SIZE; ++i) {
        if (fabs(m[i]) < fabs(m[iMin])) {
            iMin = i;
        }
    }
    
    float sum;
    for (int i = 0; i < MAX_SIZE; ++i){
        if (m[i] == 0) {
            for (i = i + 1; i < MAX_SIZE; ++i)  
                sum += fabs(m[i]);
            break;
        }
    }

    float sortedArr[MAX_SIZE];
    int j = 0;;
    for (i = 0; i < MAX_SIZE; ++i) {
        if (i % 2 == 0) {
            sortedArr[j] = m[i];
            j++;
        } 
    }
    for (i = 0; i < MAX_SIZE; ++i) {
        if (i % 2 != 0) {
            sortedArr[j] = m[i];
            j++;
        }
    }

    printf("Минимальный по модулю элемент: %.2f\n", m[iMin]);
    printf("Сумма элементов после первого элемента равного нулю: %.2f\n\n", sum);

    printf("Отсортированный массив:\n");

    for (i = 0; i < MAX_SIZE; ++i) {
        printf("%.2f ", sortedArr[i]);
    }

    return 0;
}
