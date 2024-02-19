#include <stdio.h>
#include <conio.h>

int row, column;

void printVirtualMatrix(int matrix[row][column]);
int countNumberOfDigits(int number);
int maxNumber(int numbers[]);

void main()
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

    printVirtualMatrix(Matrix);
    printf("\n");

    int number_of_digits[row][column];

    for(int i=0; i<row; i++)
    {
        for(int j=0; j<column; j++)
        {
            number_of_digits[i][j] = countNumberOfDigits(Matrix[i][j]);
        }
    }

    printVirtualMatrix(number_of_digits);
    printf("\n");

    int max_number_of_digits[row];

    for(int i=0; i<column; i++)
    {
        int col[row];

        for(int j=0; j<row; j++)
        {
            col[j] = number_of_digits[j][i];
        }

        max_number_of_digits[i] = maxNumber(col);
    }

    printf("%d %d %d", max_number_of_digits[0], max_number_of_digits[1], max_number_of_digits[2]);

    getch();
}

void printVirtualMatrix(int matrix[row][column])
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