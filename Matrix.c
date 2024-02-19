#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int row, column;
int v_row, v_column;

void printMatrix(int matrix[row][column]);
void printVirtualMatrix(char matrix[v_row][v_column]);
int countNumberOfDigits(int number);
int maxNumber(int numbers[]);
int additionOfDigits(int numbers[]);
void separateNumberIntoDigits(int number, int digits[]);

int main()
{
    printf("Enter Number Of Rows : ");
    scanf("%d", &row);
    printf("Enter Numbers Of Columns : ");
    scanf("%d", &column);

    printf("\n");

    int Matrix[row][column];

    for(int i=0; i<row; i++)
    {
        for(int j=0; j<column; j++)
        {
            printf("Enter A%d%d Element : ", i+1, j+1);
            scanf("%d", &Matrix[i][j]);
        }
    }

    printMatrix(Matrix);
    printf("\n");

    int number_of_digits[row][column];

    for(int i=0; i<row; i++)
    {
        for(int j=0; j<column; j++)
        {
            number_of_digits[i][j] = countNumberOfDigits(Matrix[i][j]);
        }
    }

    printMatrix(number_of_digits);
    printf("\n");

    int max_number_of_digits[column];

    for(int i=0; i<column; i++)
    {
        int col[row];

        for(int j=0; j<row; j++)
        {
            col[j] = number_of_digits[j][i];
        }

        max_number_of_digits[i] = maxNumber(col);
    }

    printf("%d %d %d\n\n", max_number_of_digits[0], max_number_of_digits[1], max_number_of_digits[2]);

    int *digits, *d;
    int n = 1;

    digits = (int*) malloc (n * sizeof(int));

    for(int  i=0; i<row; i++)
    {
        for(int j=0; j<column; j++)
        {
            digits = (int*) realloc (digits, (n * number_of_digits[i][j]) * sizeof(int));
            separateNumberIntoDigits(Matrix[i][j], digits);

            for(int k=0; k<number_of_digits[i][j]; k++)
            {
                printf("%d, ", digits[k]);
            }

            printf("\n");
        }
    }

    printf("\n");

    v_column = additionOfDigits(max_number_of_digits) + column + 3;
    v_row = row + 2;

    char Virtual_Matrix[v_row][v_column];

    for(int i=0; i<v_row; i++)
    {
        for(int j=0; j<v_column; j++)
        {
            if(((i == 0) || (i == v_row-1)) && ((j == 1) || (j == v_column-2)))
            {
                Virtual_Matrix[i][j] = '-';
            }
            else if(((i == 0) || (i == v_row-1)) && ((j == 0) || (j == v_column-1)))
            {
                Virtual_Matrix[i][j] = '+';
            }
            else if(((i > 0) && (i < v_row-1)) && ((j == 0) || (j == v_column-1)))
            {
                Virtual_Matrix[i][j] = '|';
            }
            else
            {
                Virtual_Matrix[i][j] = ' ';
            }
        }
    }

    printVirtualMatrix(Virtual_Matrix);

    getch();
    return 0;
}

void printMatrix(int matrix[row][column])
{
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<column; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void printVirtualMatrix(char matrix[v_row][v_column])
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

    while(number != 0)
    {
        digit++;
        number /= 10;
    }

    return digit;
}

int maxNumber(int numbers[])
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

int additionOfDigits(int numbers[])
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
    for(int i=countNumberOfDigits(number)-1; i>=0; i--)
    {
        digits[i] = num % 10;
        num /= 10;
    }
}