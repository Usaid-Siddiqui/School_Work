#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int **allocateMatrix(int numRows, int numCols)
{
   int** matrix = (int**)malloc(numRows*sizeof(int*));
   for (int i=0; i<numRows; i++) {
      matrix[i] = (int*)malloc(numCols * sizeof(int));
   }
   return matrix;
}

void freeMatrix(int **matrix, int numRows, int numCols)
{
   for (int i=numRows-1; i>=0; i--) {
      free(matrix[i]);
   }
   free(matrix);
}

void readMatrix(FILE *fp, int **matrix, int numRows, int numCols)
{
   int temp;
   for (int i=0; i<numRows; i++) {              //creates array containing pointers to more arrays storing each respective row
      for (int j=0; j<numCols; j++) {
         fscanf(fp,"%d", &temp);
         matrix[i][j] = temp;
      }
   }
}

void printMatrix(int **matrix, int numRows, int numCols)
{
   for (int r=0; r<numRows; r++) {
        for (int c=0; c<numCols; c++) {
            printf(" %d", matrix[r][c]);
        }
        printf("\n");
    }
}

int rangeRow(int **matrix, int numRows, int numCols, int r)
{
   int max = INT_MIN;
   int min = INT_MAX;

   for (int c=0; c<numCols; c++) {
      if (matrix[r][c] < min) min = matrix[r][c];
      if (matrix[r][c] > max) max = matrix[r][c];
   }

   return max-min;
}

void printCorners(int **matrix, int numRows, int numCols)
{
   int topleft = matrix[0][0], topright = matrix[0][numCols-1], bottomleft = matrix[numRows-1][0], bottomright = matrix[numRows-1][numCols-1];
   printf("%d %d\n", topleft, topright);
   printf("%d %d\n", bottomleft, bottomright);
}

int sumSubMatrix(int **matrix, int startRow, int endRow, int startCol, int endCol)
{
   int sum=0, temp=0;
   for (int r=startRow; r<=endRow; r++) {
      for (int c=startCol; c<=endCol; c++) {
         temp = matrix[r][c];
         sum = sum + temp;
      }
   }
   return sum;
}
