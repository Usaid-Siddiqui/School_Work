// USAID SIDDIQUI
//      This program dynamically allocates 2d arrays in the heap. The first stores the crossword puzzle itself, 
//      while the second keep tracks of where each word was found. In order to actually locate the words themselves,
//      one main function parses through the entire crossword index by index, using a helper function to check whether
//      a word can be located in any of the eight directions from that point. Once a word is completely found, it goes
//      throguh and marks the corresponding locations on the marker matrix, in order to print it. It also indexes and
//      keeps track of the number of words found in each directional search.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//GLOBAL VARIABLES
char word[101];
char *directionNames[8] = {"northward", "southward", "eastward", "westward", "northeastward", "southeastward", "southwestward", "northwestward"};
int directions[8][2] = {
    {-1, 0},    // North
    {1, 0},     // South
    {0, 1},     // East
    {0, -1},    // West
    {-1, 1},    // Northeast
    {1, 1},     // Southeast
    {1, -1},    // Southwest
    {-1, -1}    // Northwest
};
int count[8] = {0};         //array keeping track of number of words found in each direction, corresponds with previous array



int getPuzzleSize(char file[]) {
    FILE *fp = fopen(file, "r");
    char c;
    int n = 0;
    while(1) {
        fscanf(fp, "%c", &c);
        if (c=='\n') break;
        n++;
    }
    fclose(fp);
    return n;
}

char **allocSpace(int puzzleSize) {
    char **array = malloc(puzzleSize*sizeof(char *));
    for (int r=0; r<puzzleSize; r++) {
        array[r]=malloc(puzzleSize*sizeof(char));
    }
    return array;
}

void scanPuzzle(char **arr, FILE *fp1, int puzzleSize) {
    char c;
    for (int i=0; i<puzzleSize; i++) {
        for (int j=0; j<=puzzleSize; j++) {
            fscanf(fp1, "%c", &c);
            if (c != '\n') arr[i][j]=c;
        }
    }
}

void printPuzzle(char **arr1, char **arr2, int puzzleSize) {            //prints out the primary matrix using the secondary one as a guide as to which characters to print/replace with dashes
    for (int i=0; i<puzzleSize; i++) {
        for (int j=0; j<puzzleSize; j++) {
            if (arr2[i][j] == 'T') printf("%c", arr1[i][j]);
            else printf("-");
        }
        printf("\n");
    }
}

int searchFrom(char **arr, int startRow, int startCol, int rowDir, int colDir, int size) {          //function that takes the index of any letter in the given crossword and searches in a given direction from that point
    int len = strlen(word);

    for (int i = 0; i < len; i++) {
        int row = startRow + i * rowDir;
        int col = startCol + i * colDir;
        
        // Boundary check
        if (row < 0 || row >= size || col < 0 || col >= size || arr[row][col] != word[i])
            return 0;
    }
    return 1;
}

void puzzleSearch(char **puzzle, char **markerMatrix, int size) {                 //finds the words, notes thier locaitons, updates counts of words found in each direction.
    for (int row=0; row<size; row++) {
        for (int col=0; col<size; col++) {
            for (int d=0; d<8; d++) {
                if (searchFrom(puzzle, row, col, directions[d][0], directions[d][1], size)) {
                    count[d]++;


                    for (int i=0; i<strlen(word); i++) {            //updates the marker matrix with locations of found words
                        int r = row + i * directions[d][0];
                        int c = col + i * directions[d][1];
                        markerMatrix[r][c] = 'T';
                    }
                }
            }
        }
    }
}




int main(int argc, char* argv[]) {
    int size = getPuzzleSize(argv[1]);
    FILE *fp = fopen(argv[1],"r");
    
    char **primaryMatrix = allocSpace(size);
    char **switchMatrix = allocSpace(size);
    for (int i=0; i<size; i++) {
        for (int j=0; j<size; j++) {
            switchMatrix[i][j] = 'T';               //each corresponding element in the switchmatrix stores either a T or F to indicate whether the letter at that index shall be printed
        }
    }

    scanPuzzle(primaryMatrix, fp, size);            //scans puzzle from file and stores it in 2D array     
    fclose(fp);
    printPuzzle(primaryMatrix, switchMatrix, size);
    printf("\n\n");

    
    while (1) {
        printf("Enter a word to search in the puzzle (or CRTL-D to exit): ");
        if (scanf("%s", word) == EOF) break;
        
        for (int i=0; i<size; i++) {
            for (int j=0; j<size; j++) {
                switchMatrix[i][j] = 'F';
            }
        }
        puzzleSearch(primaryMatrix, switchMatrix, size);

        printf("\"%s\" was found as below.\n", word);
        for (int d = 0; d < 8; d++) {
            printf("%d times in the %s direction\n", count[d], directionNames[d]);
        }
        printf("\n");
        
        printPuzzle(primaryMatrix, switchMatrix, size);
        for (int i=0; i<8; i++) {
            count[i] = 0;
        }
    }
    

    
    return 0;
}