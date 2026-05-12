#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void freeMx(int*** Mx, size_t rows)
{
    if (Mx && *Mx && rows != 0)
    {
        for (size_t i = 0; i < rows; i++)
        {
            free((*Mx)[i]);
            (*Mx)[i] = NULL;
        }
        free(*Mx);
        *Mx = NULL;
    }
}

int** CreateMx(size_t rows, size_t columns, int A, int B)
{
    int **dmas = (int **)calloc(rows, sizeof(int*));
    if (dmas && rows != 0 && columns != 0)
    {
        for (size_t i = 0; i < rows; i++)
        {
            dmas[i] = (int *)calloc(columns, sizeof(int));
            for (size_t k = 0; k < columns; k++)
            {
                dmas[i][k] = A + rand() % (B - A + 1);
            }
        }
    }
    else
    {
        freeMx(&dmas, rows);
    }
    return dmas;
}

void printMx(int** Mx, size_t rows, size_t columns)
{
    if (Mx && rows != 0 && columns != 0)
    {
        for (size_t ix = 0; ix < rows; ix++)
        {
            if (Mx[ix])
            {
                for (size_t kx = 0; kx < columns; kx++)
                {
                    printf("%d ", Mx[ix][kx]);
                }
            }
            else
            {
                printf("Null");

            }
            printf("\n");
        }
    }
    else
    {
        printf("Empty Matrix");
    }
}

int** Transponate(int **Mx, size_t rows, size_t columns)
{
    int** TrspMx = NULL;
    if (Mx && rows != 0 && columns != 0)
    {
        TrspMx = (int **) calloc (columns, sizeof (int*));

        if (TrspMx)
        {
            for (size_t i = 0; i < rows; i++)
            {
                if (!Mx[i]) Mx[i] = (int*)calloc(columns, sizeof (int));
            }

            for (size_t i = 0; i < columns; i++)
            {
                TrspMx[i] = (int *)calloc(rows, sizeof (int));
                for (size_t k = 0; k < rows; k++)
                {
                    TrspMx[i][k] = Mx[k][i];
                }
            }
        }
        else
        {
            freeMx(&TrspMx, columns);
        }
    }
    return TrspMx;
}

int main()
{
    //Проверка функции freeMx
    int rows = 3;
    int cols = 3;
    int** Mx = CreateMx(rows, cols, 1, 10);
    freeMx(&Mx, rows);
    printMx(Mx, rows, cols);
    printf("\n");

    //Проверка функций createMx и printMx
//    int rows = 3;
//    int cols = 3;
//    int** Mx = CreateMx(rows, cols, 1, 10);
//    printMx(Mx, rows, cols);
//    printf("\n");


    //Проверка транспонирования матрицы
//    int rows = 3;
//    int cols = 3;
//    int** Mx = CreateMx(rows, cols, 1, 10);

//    printMx(Mx, rows, cols);
//    printf("\n");

//    int** newMx = Transponate(Mx, rows, cols);
//    if (!newMx) printf("Null adress recieved!");
//    printMx(newMx, cols, rows);

    //Транспонирование разреженной матрицы
//    int rows = 3;
//    int cols = 3;
//    int** Mx = CreateMx(rows, cols, 1, 10);
//    free(Mx[0]);
//    Mx[0] = NULL;
//    free(Mx[0]);
//    Mx[2] = NULL;

//    printMx(Mx, rows, cols);
//    printf("\n");

//    int** newMx = Transponate(Mx, rows, cols);
//    if (!newMx) printf("Null adress recieved!");
//    else printMx(newMx, cols, rows);

    //Транспонирование полностью разреженной матрицы
//    int rows = 3;
//    int cols = 4;
//    int** Mx = CreateMx(rows, cols, 1, 10);
//    free(Mx[0]);
//    Mx[0] = NULL;
//    free(Mx[1]);
//    Mx[1] = NULL;
//    free(Mx[0]);
//    Mx[2] = NULL;

//    printMx(Mx, rows, cols);
//    printf("\n");

//    int** newMx = Transponate(Mx, rows, cols);
//    if (!newMx) printf("Null adress recieved!");
//    else printMx(newMx, cols, rows);

//    Нулевые адреса
//    int rows = 3;
//    int cols = 3;
//    int** Mx = NULL;

//    printMx(Mx, rows, cols);
//    printf("\n");

//    int** newMx = Transponate(Mx, rows, cols);
//    if (!newMx) printf("Null adress recieved!");
//    else printMx(newMx, cols, rows);


    return 0;
}
