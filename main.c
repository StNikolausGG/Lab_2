#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int** CreateMx(size_t rows, size_t columns, int A, int B)
{
    int **dmas = (int **)calloc(rows, sizeof(int*));
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

void printMx(int** Mx, int rows, int columns)
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

void FreeMx(int **Mx, size_t rows)
{
    for (size_t i = 0; i < rows; i++)
    {
        free(Mx[i]);
        Mx[i] = NULL;
    }
}

int** Multiplication(int **Mx1, int **Mx2)
{
    int **dmas = (int**)calloc(15, sizeof(int*));
    for (size_t i = 0; i < 15; i++)
    {

    }
}

int main()
{
    int** Mx1 = NULL;
    int** Mx2 = NULL;
    srand(time(0));
    Mx1 = CreateMx(15, 15, -10, 10);
    //Mx2 = CreateMx(10, 10, 5, 15);
    printMx(Mx1, 15, 15);
    printf("\n");
    //printMx(Mx2, 15, 15);
    return 0;
}
