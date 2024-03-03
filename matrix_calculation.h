#ifndef MATRIX_CALCULATION_H
#define MATRIX_CALCULATION_H

#include <stdio.h>
#include <stdlib.h>
#include "matrix_calculation.h"


void virtualMatrixConversion(int row, int column, int v_row, int v_column, int matrix[row][column], int digit_count[row][column], int max_digit_count[], char v_matrix[v_row][v_column]);
void printVirtualMatrix(int v_row, int v_column, char matrix[v_row][v_column]);

void storeDigitsNumberIntoMatrix(int row, int column, int matrix[row][column], int digit_matrix[row][column]);
void storeMaxDigitIntoMatrix(int row, int column, int digit_matrix[row][column], int max_digits_matrix[]);
int countNumberOfDigits(int number);
int maxNumber(int row, int numbers[]);
int additionOfDigits(int column, int numbers[]);
void separateNumberIntoDigits(int number, int digits[]);

void interchangeRow(int row, int column, int matrix[row][column], int row_1, int row_2);
void interchangeColumn(int row, int column, int matrix[row][column], int column_1, int column_2);




void swap(int *num1, int *num2)
{
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

void virtualMatrixConversion(int row, int column, int v_row, int v_column, int matrix[row][column], int digit_count[row][column], int max_digit_count[], char v_matrix[v_row][v_column])
{
    int *digits, *d;
    int n = 1;

    digits = (int*) malloc (n * sizeof(int));

    printf("\n");

    for(int i=0; i<v_row; i++)
    {
        for(int j=0; j<v_column; j++)
        {
            if(((i == 0) || (i == v_row-1)) && ((j == 1) || (j == v_column-2)))
            {
                v_matrix[i][j] = '-';
            }
            else if(((i == 0) || (i == v_row-1)) && ((j == 0) || (j == v_column-1)))
            {
                v_matrix[i][j] = '+';
            }
            else if(((i > 0) && (i < v_row-1)) && ((j == 0) || (j == v_column-1)))
            {
                v_matrix[i][j] = '|';
            }
            else if(((i > 0) && (i < v_row-1)) && ((j > 1) && (j < v_column-2)))
            {
                for(int  x=0, a=1; x<row; x++, a++)
                {
                    for(int y=0, b=2; y<column; y++)
                    {
                        digits = (int*) realloc (digits, (n * digit_count[x][y]) * sizeof(int));
                        separateNumberIntoDigits(matrix[x][y], digits);

                        for(int k=0; k<digit_count[x][y]; k++, b++)
                        {
                            v_matrix[a][b] = digits[k] + 48;
                        }

                        for(int m=0; m<=max_digit_count[y]-digit_count[x][y]; m++, b++)
                        {
                            v_matrix[a][b] = ' ';
                        }
                    }
                }
            }
            else
            {
                v_matrix[i][j] = ' ';
            }
        }
    }
}

void storeDigitsNumberIntoMatrix(int row, int column, int matrix[row][column], int digit_matrix[row][column])
{
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<column; j++)
        {
            digit_matrix[i][j] = countNumberOfDigits(matrix[i][j]);
        }
    }
}

void storeMaxDigitIntoMatrix(int row, int column, int digit_matrix[row][column], int max_digits_matrix[])
{
    for(int i=0; i<column; i++)
    {
        int col[row];

        for(int j=0; j<row; j++)
        {
            col[j] = digit_matrix[j][i];
        }

        max_digits_matrix[i] = maxNumber(row, col);
    }
}

void printVirtualMatrix(int v_row, int v_column, char matrix[v_row][v_column])
{
    for(int i=0; i<v_row; i++)
    {
        for(int j=0; j<v_column; j++)
        {
            printf("%c", matrix[i][j]);
        }
        printf("\n");
    }
}

int countNumberOfDigits(int number)
{
    int digit = 0;

    if(number == 0)
    {
        digit = 1;
    }
    else
    {
        if(number < 0)
        {
            digit = 1;

            while(number != 0)
            {
                digit++;
                number /= 10;
            }
        }
        else
        {
            while(number != 0)
            {
                digit++;
                number /= 10;
            }
        }
    }

    return digit;
}

int maxNumber(int row, int numbers[])
{
    int max = 0;

    for(int i=0; i<row; i++)
    {
        if(numbers[i] > max)
        {
            max = numbers[i];
        }
    }

    return max;
}

int additionOfDigits(int column, int numbers[])
{
    int result = 0;

    for(int i=0; i<column; i++)
    {
        result += numbers[i];
    }

    return result;
}

void separateNumberIntoDigits(int number, int *digits)
{
    int num = number;

    if(number < 0)
    {
        num -= (2*num);
    }

    for(int i=countNumberOfDigits(number)-1; (number < 0) ? (i>0) : (i>=0); i--)
    {
        digits[i] = num % 10;
        num /= 10;
    }

    if(number < 0)
    {
        digits[0] = -3;
    }
}



void interchangeRow(int row, int column, int matrix[row][column], int row_1, int row_2)
{
    for(int i=0; i<row; i++)
    {
        int count = 0;

        for(int j=0; j<column; j++)
        {
            if(i == row_1-1)
            {
                swap(&matrix[row_1-1][j], &matrix[row_2-1][j]);
                count++;
            }
            else if(i == row_2-1)
            {
                swap(&matrix[row_2-1][j], &matrix[row_1-1][j]);
                count++;
            }
        }

        if(count > 0)
        {
            break;
        }
    }
}

void interchangeColumn(int row, int column, int matrix[row][column], int column_1, int column_2)
{
    for(int j=0; j<column; j++)
    {
        int count = 0;

        for(int i=0; i<row; i++)
        {
            if(j == column_1-1)
            {
                swap(&matrix[i][column_1-1], &matrix[i][column_2-1]);
                count++;
            }
            else if(j == column_2-1)
            {
                swap(&matrix[i][column_2-1], &matrix[i][column_1-1]);
                count++;
            }
        }

        if(count > 0)
        {
            break;
        }
    }
}




#endif