#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int row, column;
int v_row, v_column;

void getRowColumn();
void MATRIX(int Matrix[row][column]);
void inputMatrix(int matrix[row][column]);
void storeDigitsNumberIntoMatrix(int matrix[row][column], int digit_matrix[row][column]);
void storeMaxDigitIntoMatrix(int digit_matrix[row][column], int max_digits_matrix[]);
void printVirtualMatrix(char matrix[v_row][v_column]);
int countNumberOfDigits(int number);
int maxNumber(int numbers[]);
int additionOfDigits(int numbers[]);
void separateNumberIntoDigits(int number, int digits[]);
void virtualMatrixConversion(int matrix[row][column], int digit_count[row][column], int max_digit_count[], char v_matrix[v_row][v_column]);

int main()
{
    getRowColumn();
    int M1[row][column];
    inputMatrix(M1);
    MATRIX(M1);

    getch();
    return 0;
}

void getRowColumn()
{
    printf("Enter Number Of Rows : ");
    scanf("%d", &row);
    printf("Enter Numbers Of Columns : ");
    scanf("%d", &column);
}

void MATRIX(int Matrix[row][column])
{
    int number_of_digits[row][column];
    storeDigitsNumberIntoMatrix(Matrix, number_of_digits);

    int max_number_of_digits[column];
    storeMaxDigitIntoMatrix(number_of_digits, max_number_of_digits);

    v_column = additionOfDigits(max_number_of_digits) + column + 3;
    v_row = row + 2;

    char Virtual_Matrix[v_row][v_column];

    virtualMatrixConversion(Matrix, number_of_digits, max_number_of_digits, Virtual_Matrix);

    printVirtualMatrix(Virtual_Matrix);
}

void inputMatrix(int matrix[row][column])
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

void storeDigitsNumberIntoMatrix(int matrix[row][column], int digit_matrix[row][column])
{
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<column; j++)
        {
            digit_matrix[i][j] = countNumberOfDigits(matrix[i][j]);
        }
    }
}

void storeMaxDigitIntoMatrix(int digit_matrix[row][column], int max_digits_matrix[])
{
    for(int i=0; i<column; i++)
    {
        int col[row];

        for(int j=0; j<row; j++)
        {
            col[j] = digit_matrix[j][i];
        }

        max_digits_matrix[i] = maxNumber(col);
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

void virtualMatrixConversion(int matrix[row][column], int digit_count[row][column], int max_digit_count[], char v_matrix[v_row][v_column])
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