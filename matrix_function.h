#ifndef MATRIX_FUNCTION_H
#define MATRIX_FUNCTION_H

// Function Declaration

void getRowColumn(int *row, int *column);
void inputMatrix(int row, int column, int matrix[row][column]);

void MATRIX(int row, int column, int Matrix[row][column]);

// void virtualMatrixConversion(int row, int column, int matrix[row][column], int digit_count[row][column], int max_digit_count[], char v_matrix[v_row][v_column]);

// void storeDigitsNumberIntoMatrix(int row, int column, int matrix[row][column], int digit_matrix[row][column]);
// void storeMaxDigitIntoMatrix(int row, int column, int digit_matrix[row][column], int max_digits_matrix[]);
// void printVirtualMatrix(char matrix[v_row][v_column]);
// int countNumberOfDigits(int number);
// int maxNumber(int row, int numbers[]);
// int additionOfDigits(int column, int numbers[]);
// void separateNumberIntoDigits(int number, int digits[]);

void matrixAddition(int row, int column, int matrix_1[row][column], int matrix_2[row][column], int matrix_result[row][column]);
void matrixSubtraction(int row, int column, int matrix_1[row][column], int matrix_2[row][column], int matrix_result[row][column]);
void matrixMultiplication(int row_1, int column_1, int row_2, int column_2, int matrix_1[row_1][column_1], int matrix_2[row_2][column_2], int matrix_result[row_1][column_2]);

#endif