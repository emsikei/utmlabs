#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define N 4
#define BUFF_SIZE 80

struct trafic
{
    char begst[BUFF_SIZE];
    char term[BUFF_SIZE];
    int numer;
};

struct trafic tmpMarsh;
struct trafic marsh[N];
char buff[BUFF_SIZE];
char input[BUFF_SIZE];

int main()
{
    for (int i = 0; i < N; ++i)
    {
        printf("Запись #%d. Введите начальный, конечный пункт маршрута и его номер: ", i + 1);
        fgets(buff, BUFF_SIZE, stdin);
        sscanf(buff, "%s %s %d", marsh[i].begst, marsh[i].term, &marsh[i].numer);
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
        printf("%s -> %s (№%d)\n", marsh[i].begst, marsh[i].term, marsh[i].numer);
    }

    printf("Номер какого маршрута вам интересен?: ");
    int ask;
    fgets(buff, BUFF_SIZE, stdin);
    sscanf(buff, "%d", &ask);
    bool isMarsh = false;
    for (int i = 0; i < N; ++i)
    {
        if (ask == marsh[i].numer)
        {
            isMarsh = true;
            printf("%s -> %s (№%d)\n", marsh[i].begst, marsh[i].term, marsh[i].numer);
        }
    }

    if (!isMarsh)
    {
        printf("Информации о данном маршруте не обнаружено");
    }
}

/* struct znak
{
    char name[BUFF_SIZE];
    char zodiac[BUFF_SIZE];
    int bday[3];
}; */

// #define M 4

/* typedef struct trafic {
    char * begst;
    char * term;
    int    numer;
    } marsh, tmpMarsh; */

//TODO: 1) Сделать проверку на номер маршрута
//TODO: 2) Сделать проверку

/* marsh ** array = (marsh **)malloc(N * sizeof(marsh *));
    int sum = 0;
    for (int i = 0; i < N; ++i) {

        array[i] = (marsh *)malloc(M * sizeof(marsh));

        for (int j = 0; j < M; ++j) {
            char buf_begst[80] = {};
            scanf("%s", buf_begst);

            size_t inputSize = strlen(buf_begst) + 1;
            array[i][j].begst = (char *)malloc(inputSize);
            strcpy(array[i][j].begst, buf_begst);

            char buf_term[80] = {};
            scanf("%s", buf_term);

            inputSize = strlen(buf_term) + 1;
            array[i][j].term = (char *)malloc(inputSize);
            strcpy(array[i][j].term, buf_term);

            char buf_numer[80] = {};
            char *numer_ptr;
            int num;
            scanf("%s", buf_numer);
            // array[i][j].numer = strtol(buf_numer, &numer_ptr, 10);
            sscanf(buf_numer, "%d", &num);
            array[i][j].numer = num;

            // printf("%s\t%s\t#%d\n", array[i][j].begst, array[i][j].term, array[i][j].numer);
            
        }
    }

    marsh tmpArray;
    for (int i = 0, k = 1; i < N; ++i, ++k) {
        for (int j = 0, q = 1; j < M; ++j, ++q) {
            if (array[i][j].numer > array[k][q].numer) {
                tmpArray = array[i][j];
                array[i][j] = array[k][q];
                array[k][q] = tmpArray;
            } 
        }
    }

    printf("\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; ++j) {
            printf("%s  %s  #%d\n", array[i][j].begst, array[i][j].term, array[i][j].numer);
        }
    } */