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
                printf("\n");
            }
            else
            {
                printf("Null");
            }
        }
    }
}

int** Multiplication(int **Mx1, int **Mx2, size_t rowsA, size_t colB)
{
    if (Mx1 && Mx2)
    {
        int **MulMx = (int**)calloc(rowsA, sizeof(int*));
        if (MulMx)
        {
            if (rowsA == colB)
            {
                for (size_t i = 0; i < rowsA; i++)
                {
                    MulMx[i] = (int *)calloc(colB, sizeof(int));
                    for (size_t j = 0; j < colB; j++) {
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
    int** Mx1 = NULL;
    int** Mx2 = NULL;
    srand(time(0));

    Mx1 = CreateMx(3, 3, 0, 7);
    Mx2 = CreateMx(3, 3, 5, 10);

    printMx(Mx1, 3, 3);
    printf("\n");
    printMx(Mx2, 3, 3);
    printf("\n");

    int** Mx3 = Multiplication(Mx1, Mx2, 3, 3);
    printMx(Mx3, 3, 3);
    return 0;
}
