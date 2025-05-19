#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int upper=0, lower=0, digits=0;
int main(int argc, char **argv) {
    int i=0;
    while(1) {
        if (*((*(argv+1))+i)=='\0') break;
        else if (islower(*((*(argv+1))+i))) lower++;
        else if (isupper(*((*(argv+1))+i))) upper++;
        else if (isdigit(*((*(argv+1))+i))) digits++;
        i++;
    }
    
    printf("Uppers = %d\n", upper);
    printf("Lowers = %d\n", lower);
    printf("Digits = %d\n", digits);

    return 0;
}