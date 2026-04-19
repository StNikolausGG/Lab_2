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


int main()
{
    printf("Hello World!\n");
    return 0;
}
