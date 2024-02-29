#ifndef MATRIX_FUNCTION_H
#define MATRIX_FUNCTION_H

// Function Declaration

void getRowColumn(int *row, int *column);
void inputMatrix(int row, int column, int matrix[row][column]);

void MATRIX(int row, int column, int Matrix[row][column]);

void matrixAddition(int row, int column, int matrix_1[row][column], int matrix_2[row][column], int matrix_result[row][column]);
void matrixSubtraction(int row, int column, int matrix_1[row][column], int matrix_2[row][column], int matrix_result[row][column]);
void matrixMultiplication(int row_1, int column_1, int row_2, int column_2, int matrix_1[row_1][column_1], int matrix_2[row_2][column_2], int matrix_result[row_1][column_2]);


#endif