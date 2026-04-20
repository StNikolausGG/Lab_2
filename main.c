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

void printMx(int** Mx, size_t rows, size_t columns)
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

int** Transponation(int **Mx, size_t rows, size_t columns)
{
    if (Mx)
    {
        int** TrspMx = (int **) calloc (columns, sizeof (int*));
        if (TrspMx)
        {
            for (size_t i = 0; i < columns; i++)
            {
                TrspMx[i] = (int *) calloc (rows, sizeof (int));
                for (size_t k = 0; k < rows; k++)
                {
                    TrspMx[i][k] = Mx[k][i];
                }
            }
            return TrspMx;
        }
        else
        {
            freeMx(TrspMx, rows);
        }
    }
}


int main()
{
    int** Mx = NULL;
    int rows = 6;
    int cols = 6;
    Mx = CreateMx(rows, cols, 1, 10);
    printMx(Mx, rows, cols);
    printf("\n");
    int** newMx = NULL;
    newMx = Transponation(Mx, rows, cols);
    printMx(newMx, cols, rows);
    return 0;
}
