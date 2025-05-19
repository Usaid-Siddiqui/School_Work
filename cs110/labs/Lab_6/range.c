#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

double max=INT_MIN, min=INT_MAX;
int main(int argc, char *argv[]) {
    if (argc<2) {
        printf("This program requires at least one argument\n");
        return 1;
    }

    for (int i=1; i<argc; i++) {
        double temp=atof(*(argv+i));
        if (temp<min) min = temp;
        if (temp>max) max = temp;
    }

    printf("The range of these %d values is %lf\n", argc-1, max-min);
    return 0;
}