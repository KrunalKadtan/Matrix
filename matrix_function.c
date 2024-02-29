#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include "matrix_conversion_calculation.h"
#include "matrix_function.h"

int v_row, v_column;

// Function Definition

void getRowColumn(int *row, int *column)
{
    printf("Enter Number Of Rows : ");
    scanf("%d", row);
    printf("Enter Numbers Of Columns : ");
    scanf("%d", column);
}

void inputMatrix(int row, int column, int matrix[row][column])
{
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<column; j++)
        {
            printf("Enter A%d%d Element : ", i+1, j+1);
            scanf("%d", &matrix[i][j]);
        }
    }
}



void MATRIX(int row, int column, int Matrix[row][column])
{
    int number_of_digits[row][column];
    storeDigitsNumberIntoMatrix(row, column, Matrix, number_of_digits);

    int max_number_of_digits[column];
    storeMaxDigitIntoMatrix(row, column, number_of_digits, max_number_of_digits);

    v_column = additionOfDigits(column, max_number_of_digits) + column + 3;
    v_row = row + 2;

    char Virtual_Matrix[v_row][v_column];

    virtualMatrixConversion(row, column, v_row, v_column, Matrix, number_of_digits, max_number_of_digits, Virtual_Matrix);

    printVirtualMatrix(v_row, v_column, Virtual_Matrix);
}



void matrixAddition(int row, int column, int matrix_1[row][column], int matrix_2[row][column], int matrix_result[row][column])
{
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<column; j++)
        {
            matrix_result[i][j] = matrix_1[i][j] + matrix_2[i][j];
        }
    }
}

void matrixSubtraction(int row, int column, int matrix_1[row][column], int matrix_2[row][column], int matrix_result[row][column])
{
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<column; j++)
        {
            matrix_result[i][j] = matrix_1[i][j] - matrix_2[i][j];
        }
    }
}

void matrixMultiplication(int row_1, int column_1, int row_2, int column_2, int matrix_1[row_1][column_1], int matrix_2[row_2][column_2], int matrix_result[row_1][column_2])
{
    if(column_1 == row_2)
    {
        for(int i=0; i<row_1; i++)
        {
            for(int j=0; j<column_2; j++)
            {
                matrix_result[i][j] = 0;
            
                for(int k=0; k<row_1; k++)
                {
                    matrix_result[i][j] += (matrix_1[i][k] * matrix_2[k][j]);
                }
            }
        }
    }
    else
    {
        printf("Multiplication Not Possible as %d not equal to %d ..!", column_1, row_2);
    }
}