#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int **allocSpace(int numRows, int numCols)
{
    int **array;
    array=malloc(numRows*sizeof(int *));
    for (int a=0; a<numRows; a++) {
        array[a]=malloc(numCols*sizeof(int));
    }
    return array;
}

void freeSpace(int **array, int numRows, int numCols)
{
    for (int a=0; a<numRows; a++) {
        free(array[a]);
    }
    free(array);
}

void readArray(FILE *fp, int **array, int numRows, int numCols)
{
    for (int r=0; r<numRows; r++) {
        for (int c=0; c<numCols; c++) {
            int num;
            fscanf(fp, "%d", &num);
            array[r][c]=num;
        }
    }
}

void printArray(int **array, int numRows, int numCols)
{
    for (int r=0; r<numRows; r++) {
        for (int c=0; c<numCols; c++) {
            printf(" %3d", array[r][c]);
        }
        printf("\n");
    }
}

void subMatrixMinMax(int **array, int r1, int c1, int r2, int c2, int *pMin, int *pMax);

int main(int argc, char **argv)
{
    if (argc!=6) {
        printf("Usage: %s matrix_file r1, c1, r2, c2\n", argv[0]);
        return 1;
    }
    FILE *fp=fopen(argv[1], "r");
    if (fp==NULL) {
        printf("Unable to open %s for reading\n", argv[1]);
        return 2;
    }

    int numRows, numCols;
    fscanf(fp, "%d", &numRows);
    fscanf(fp, "%d", &numCols);
    int **x=allocSpace(numRows, numCols);
    readArray(fp, x, numRows, numCols);
    // printArray(x, numRows, numCols);

    int r1=atoi(argv[2]);
    int c1=atoi(argv[3]);
    int r2=atoi(argv[4]);
    int c2=atoi(argv[5]);
    if (r1<0 || r1>=numRows || c1<0 || c1>=numCols ||
        r2<0 || r2>=numRows || c2<0 || c2>=numCols) {
        printf("Invalid submatrix: (%d, %d) to (%d, %d)\n", r1, c1, r2, c2);
        return 3;
    }

    int min, max;
    subMatrixMinMax(x, r1, c1, r2, c2, &min, &max);
    printf("Min is %d, and Max is %d\n", min, max);

    freeSpace(x, numRows, numCols);

    return 0;
}
// do not change anything above this line

void subMatrixMinMax(int **array, int r1, int c1, int r2, int c2, int *pMin, int *pMax)
{
    int startRow, endRow, startCol, endCol;
    if (r1<r2) {
        startRow = r1;
        endRow = r2;
    }
    else {
        startRow = r2;
        endRow = r1;
    }
    if (c1<c2) {
        startCol = c1;
        endCol = c2;
    }
    else {
        startCol = c2;
        endCol = c1;
    }

    int min=INT_MAX, max=INT_MIN, temp=0;
    for (int r=startRow; r<=endRow; r++) {
        for (int c=startCol; c<=endCol; c++) {
            temp = array[r][c];
            if (temp<min) min=temp;
            if (temp>max) max=temp;
        }
    }
    
    *pMin = min;
    *pMax = max;
}