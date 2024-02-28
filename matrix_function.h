#ifndef MATRIX_FUNCTION_H
#define MATRIX_FUNCTION_H

// Function Declaration

void getRowColumn(int *row, int *column);
void MATRIX(int row, int column, int *v_row, int *v_column, int Matrix[row][column]);
void inputMatrix(int row, int column, int matrix[row][column]);
void storeDigitsNumberIntoMatrix(int row, int column, int matrix[row][column], int digit_matrix[row][column]);
void storeMaxDigitIntoMatrix(int row, int column, int digit_matrix[row][column], int max_digits_matrix[]);
void printVirtualMatrix(int v_row, int v_column, char matrix[v_row][v_column]);
int countNumberOfDigits(int number);
int maxNumber(int row, int numbers[]);
int additionOfDigits(int column, int numbers[]);
void separateNumberIntoDigits(int number, int digits[]);
void virtualMatrixConversion(int row, int column, int v_row, int v_column, int matrix[row][column], int digit_count[row][column], int max_digit_count[], char v_matrix[v_row][v_column]);

#endif