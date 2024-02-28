#include <conio.h>
#include "matrix_function.h"

int main()
{
    int row, column;
    int v_row, v_column;

    getRowColumn(&row, &column);
    int M1[row][column];
    inputMatrix(row, column, M1);
    MATRIX(row, column, &v_row, &v_column, M1);

    getch();
    return 0;
}