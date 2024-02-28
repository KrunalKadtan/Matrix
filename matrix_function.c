#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include "matrix_function.h"

// Function Definition

void getRowColumn(int *row, int *column)
{
    printf("Enter Number Of Rows : ");
    scanf("%d", row);
    printf("Enter Numbers Of Columns : ");
    scanf("%d", column);
}

void MATRIX(int row, int column, int *v_row, int *v_column, int Matrix[row][column])
{
    int number_of_digits[row][column];
    storeDigitsNumberIntoMatrix(row, column, Matrix, number_of_digits);

    int max_number_of_digits[column];
    storeMaxDigitIntoMatrix(row, column, number_of_digits, max_number_of_digits);

    *v_column = additionOfDigits(column, max_number_of_digits) + column + 3;
    *v_row = row + 2;

    char Virtual_Matrix[*v_row][*v_column];

    virtualMatrixConversion(row, column, *v_row, *v_column, Matrix, number_of_digits, max_number_of_digits, Virtual_Matrix);

    printVirtualMatrix(*v_row, *v_column, Virtual_Matrix);
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