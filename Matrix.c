#include <stdio.h>
#include <conio.h>

int row, column;

int main()
{
    printf("Enter Number Of Rows : ");
    scanf("%d", &row);
    printf("Enter Numbers Of Columns : ");
    scanf("%d", &column);

    int Matrix[row][column];

    for(int i=0; i<row; i++)
    {
        for(int j=0; j<column; j++)
        {
            printf("Enter A%d%d Element : ", i+1, j+1);
            scanf("%d", &Matrix[i][j]);
        }
    }

    getch();
    return 0;
}