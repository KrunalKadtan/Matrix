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

    getch();
    return 0;
}