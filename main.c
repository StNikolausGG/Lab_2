#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void freeMx(int** Mx, size_t rows)
{
    if (Mx)
    {
        for (size_t i = 0; i < rows; i++)
        {
            free(Mx[i]);
        }
    }
    free(Mx);
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
        return dmas;
    }
    else
    {
        freeMx(dmas, rows);
    }
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
}

int** Multiplication(int **Mx1, int **Mx2, size_t rowsA, size_t colA, size_t rowsB, size_t colB)
{
    if (Mx1 && Mx2)
    {
        int **MulMx = (int**)calloc(rowsA, sizeof(int*));
        if (MulMx)
        {
            if (rowsA == colB)
            {
                for (size_t i = 0; i < rowsB; i++)
                {
                    if (Mx2[i] == NULL) Mx2[i] = (int *)calloc(colB, sizeof (int));
                }

                for (size_t i = 0; i < rowsA; i++)
                {
                    if (Mx1[i] == NULL)
                    {
                        Mx1[i] = (int *)calloc(colB, sizeof (int));
                    }
                    MulMx[i] = (int *)calloc(colB, sizeof(int));
                    for (size_t j = 0; j < colB; j++)
                    {
                        int sum = 0;
                        for (size_t k = 0; k < rowsA; k++)
                        {
                            sum += Mx1[i][k] * Mx2[k][j];
                        }
                        MulMx[i][j] = sum;
                    }
                }
                return MulMx;
            }
        }
        else
        {
            freeMx(MulMx, rowsA);
        }
    }
}

int main()
{
    //Проверка работы с квадратными матрицами
//    int rows1 = 3;
//    int cols1 = 3;
//    int rows2 = 3;
//    int cols2 = 3;
//    int** Mx1 = CreateMx(rows1, cols1, 1, 10);
//    int** Mx2 = CreateMx(rows2, cols2, 1, 10);
//    srand(time(0));

//    printMx(Mx1, rows1, cols1);
//    printf("\n");
//    printMx(Mx2, rows2, cols2);
//    printf("\n");

//    int** Mx3 = Multiplication(Mx1, Mx2, rows1, cols1, rows2, cols2);
//    printMx(Mx3, rows1, cols2);

    //Проверка работы с прямоугольными матрицами
    //    int rows1 = 2;
    //    int cols1 = 3;
    //    int rows2 = 3;
    //    int cols2 = 2;
    //    int** Mx1 = CreateMx(rows1, cols1, 1, 10);
    //    int** Mx2 = CreateMx(rows2, cols2, 1, 10);
    //    srand(time(0));

    //    printMx(Mx1, rows1, cols1);
    //    printf("\n");
    //    printMx(Mx2, rows2, cols2);
    //    printf("\n");

    //    int** Mx3 = Multiplication(Mx1, Mx2, rows1, cols1, rows2, cols2);
    //    printMx(Mx3, rows1, cols2);

    //Нулевой указатель
    int rows1 = 3;
    int cols1 = 3;
    int rows2 = 3;
    int cols2 = 3;
    int** Mx1 = CreateMx(rows1, cols1, 1, 10);
    int** Mx2 = NULL;
    srand(time(0));

    printMx(Mx1, rows1, cols1);
    printf("\n");
    printMx(Mx2, rows2, cols2);
    printf("\n");

    int** Mx3 = Multiplication(Mx1, Mx2, rows1, cols1, rows2, cols2);

    printMx(Mx3, rows1, cols2);


    return 0;
}
