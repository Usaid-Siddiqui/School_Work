#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char inputword[51];
int i=0, n=0, firstword=0;

int main(int argc, char *argv[]) {

    FILE *fp = fopen(argv[1], "r");
    FILE *fp2 = fopen(argv[2], "w");
    
    if (fp==NULL) {
        printf("Cannot open file '%s'\n", argv[1]);
        return 1;
    }
    if (fp2==NULL) {
        printf("Cannot open file '%s'\n", argv[2]);
        return 1;
    }

    while(1) {
        i = fscanf(fp, "%s", inputword);
        if (i<1) break;
        n=0;
        for (char *ptr=inputword; *ptr!='\0'; ptr++) {
            if (!isalpha(*ptr)) n++;
        }
        if (n==0) {
            if (firstword==0) {
                fprintf(fp2, "%s", inputword);
                firstword=1;
            }
            else fprintf(fp2, " %s", inputword);
        }
    }
    fclose(fp);
    fclose(fp2);

    return 0;
}