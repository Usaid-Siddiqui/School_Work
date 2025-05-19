#include <stdio.h>
#include <string.h>

int main() {
    int size, i=0, j=0;
    printf("Enter a positive non zero integer:\n");
    scanf("%d", &size);

    //first line
    for (i=0; i<size-1; ++i) {
        printf("X");
    }
    printf("X\n");

    i=0;

    //middle
    for (i=0; i<size-2; ++i) {
        printf("X");
        for (j=0; j<size-2; ++j) {
        printf(" ");
        }
        printf("X\n");
    }

    i=0;
    //last line
    for (i=0; i<size-1; ++i) {
        printf("X");
    }
    printf("X\n");

}