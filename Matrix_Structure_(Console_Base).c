#include <stdio.h>
#include <conio.h>
#include "matrix_function.h"

int main()
{
    int row_1, column_1;
    int row_2, column_2;

    getRowColumn(&row_1, &column_1);
    int M1[row_1][column_1];
    inputMatrix(row_1, column_1, M1);
    MATRIX(row_1, column_1, M1);

    printf("\n");

    getRowColumn(&row_2, &column_2);
    int M2[row_2][column_2];
    inputMatrix(row_2, column_2, M2);
    MATRIX(row_2, column_2, M2);

    int MR[row_1][column_2];
    matrixMultiplication(row_1, column_1, row_2, column_2, M1, M2, MR);
    MATRIX(row_1, column_2, MR);

    getch();
    return 0;
}