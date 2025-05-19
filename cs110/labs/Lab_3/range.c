#include <stdio.h>
#include <string.h>
#include <limits.h>

int main() {
    int i=0;
    int max=INT_MIN, min=INT_MAX, range;

    while (1) {       
        scanf("%d", &i);
        if (feof(stdin)) break;
        if (i<min) min=i;
        if (i>max) max=i;
    }

    range = max-min;
    printf("Range of input = %d\n", range);

}