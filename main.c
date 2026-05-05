#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void freeMx(int*** Mx, size_t rows)
{
    if (Mx && *Mx)
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
    if (dmas)
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

void printMx(int** Mx, int rows, int columns)
{
    if (Mx)
    {
        for (int ix = 0; ix < rows; ix++)
        {
            if (Mx[ix])
            {
                for (int kx = 0; kx < columns; kx++)
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
        printf("Empty matrix \n");
    }
}

int** Multiply(int **Mx1, int **Mx2, size_t rowsA, size_t colA, size_t rowsB, size_t colB)
{
    int **MulMx = NULL;
    if (Mx1 && Mx2)
    {
        MulMx = (int**)calloc(rowsA, sizeof (int*));
        if (MulMx)
        {
            if (colA == rowsB)
            {
                for (size_t i = 0; i < rowsB; i++)
                {
                    if (!Mx2[i]) Mx2[i] = (int*)calloc(rowsB, sizeof (int));
                }

                for (size_t i = 0; i < rowsA; i++)
                {
                    if (!Mx1[i]) Mx1[i] = (int*)calloc(rowsA, sizeof (int));
                    MulMx[i] = (int*)calloc(colB, sizeof (int));
                    for (size_t j = 0; j < colB; j++)
                    {
                        int sum = 0;
                        for (size_t k = 0; k < colA; k++)
                        {
                            sum += Mx1[i][k] * Mx2[k][j];
                        }
                        MulMx[i][j] = sum;
                    }
                }
            }
        }
        else
        {
            freeMx(&MulMx, rowsA);
        }
    }
    return MulMx;
}

int main()
{
    //Проверка функции освобождения матрицы
        srand(time(0));
        int rows1 = 3, cols1 = 3;
        int rows2 = 3, cols2 = 3;
        int** Mx1 = CreateMx(rows1, cols1, 1, 10);
        int** Mx2 = CreateMx(rows2, cols2, 1, 10);
        freeMx(&Mx1, rows1);

        printMx(Mx1, rows1, cols1);
        printf("\n");
        printMx(Mx2, rows2, cols2);
        printf("\n");

//        Проверка функций createMx и printMx
//        int rows = 3;
//        int cols = 3;
//        int** Mx = CreateMx(rows, cols, 1, 10);
//        printMx(Mx, rows, cols);
//        printf("\n");

    //Проверка работы с квадратными матрицами
//    srand(time(0));
//    int rows1 = 3, cols1 = 3;
//    int rows2 = 3, cols2 = 3;
//    int** Mx1 = CreateMx(rows1, cols1, 1, 10);
//    int** Mx2 = CreateMx(rows2, cols2, 1, 10);

//    printMx(Mx1, rows1, cols1);
//    printf("\n");
//    printMx(Mx2, rows2, cols2);
//    printf("\n");

//    int** Mx3 = Multiply(Mx1, Mx2, rows1, cols1, rows2, cols2);
//    if (Mx3) printMx(Mx3, rows1, cols2);
//    else printf("Null address recieved!");

    //Проверка работы с прямоугольными матрицами
//        srand(time(0));
//        int rows1 = 2, cols1 = 3;
//        int rows2 = 3, cols2 = 2;
//        int** Mx1 = CreateMx(rows1, cols1, 1, 10);
//        int** Mx2 = CreateMx(rows2, cols2, 1, 10);

//        printMx(Mx1, rows1, cols1);
//        printf("\n");
//        printMx(Mx2, rows2, cols2);
//        printf("\n");

//        int** Mx3 = Multiply(Mx1, Mx2, rows1, cols1, rows2, cols2);
//        if (Mx3) printMx(Mx3, rows1, cols2);
//        else printf("Null address recieved!");

        //Работа с разреженной матрицей
//        srand(time(0));
//        int rows1 = 3, cols1 = 3;
//        int rows2 = 3, cols2 = 3;
//        int** Mx1 = CreateMx(rows1, cols1, 1, 10);
//        int** Mx2 = CreateMx(rows2, cols2, 1, 10);
//        free(Mx1[0]);
//        Mx1[0] = NULL;
//        free(Mx1[0]);
//        Mx1[2] = NULL;
//        printMx(Mx1, rows1, cols1);
//        printf("\n");
//        printMx(Mx2, rows2, cols2);
//        printf("\n");

//        int** Mx3 = Multiply(Mx1, Mx2, rows1, cols1, rows2, cols2);
//        if (Mx3) printMx(Mx3, rows1, cols2);
//        else printf("Null address recieved!");

    //Нулевой указатель
//    srand(time(0));
//    int rows1 = 3, cols1 = 3;
//    int rows2 = 3, cols2 = 3;
//    int** Mx1 = CreateMx(rows1, cols1, 1, 10);
//    int** Mx2 = NULL;

//    printMx(Mx1, rows1, cols1);
//    printf("\n");
//    printMx(Mx2, rows2, cols2);
//    printf("\n");

//    int** Mx3 = Multiply(Mx1, Mx2, rows1, cols1, rows2, cols2);

//    if (Mx3) printMx(Mx3, rows1, cols2);
//    else printf("Null address recieved!");


    return 0;
}
