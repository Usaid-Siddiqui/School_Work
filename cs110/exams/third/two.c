#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int num1, num2;

int main(int argc, char *argv[]) {
    FILE* fp = fopen(argv[1], "r");
    FILE* fp2 = fopen(argv[2], "r");

    fscanf(fp, "%d", &num1);
    fscanf(fp2, "%d", &num2);
    
    int toggle=0;

    printf("The difference is ");
    while (!feof(fp) && !feof(fp2)) {
        if (num1 < num2) {
            printf("%d ", num1);
            fscanf(fp, "%d", &num1);
            toggle++;
        } 
        else if (num1 > num2) fscanf(fp2, "%d", &num2);
        else {
            fscanf(fp, "%d", &num1);
            fscanf(fp2, "%d", &num2);
        }
    }

    while(!feof(fp)) {
        printf("%d ", num1);
        fscanf(fp, "%d", &num1);
        toggle++;
    }

    if (toggle==0) printf("empty\n");
    else printf("\n");


    fclose(fp);
    fclose(fp2);
    return 0;
}