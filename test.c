#include <stdio.h>
#include <conio.h>
#include <matrix.h>

/*
    EITHER "matrix.h" OR <matrix.h>
*/

int main()
{
    int row_1, column_1;
    int row_2, column_2;

    getRowColumn(&row_1, &column_1);
    int M1[row_1][column_1];
    inputMatrix(row_1, column_1, M1);
    MATRIX(row_1, column_1, M1);

    scalarRowMultiplication(row_1, column_1, M1, 3, 2);
    MATRIX(row_1, column_1, M1);

    scalarColumnMultiplication(row_1, column_1, M1, 2, 3);
    MATRIX(row_1, column_1, M1);

    getch();
    return 0;
}