#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isInteger(char word[]){
    int s=0;
    if ((word[0] == '+' || word[0]=='-') && strlen(word)>1) s=1;

    for(int n=s; n<strlen(word); n++) {
        if (word[n] == '\n') return 1;

        if (word[n]=='0' || word[n]=='1' || word[n]=='2' || word[n]=='3' || word[n]=='4' || word[n]=='5' || word[n]=='6' || word[n]=='7' || word[n]=='8' || word[n]=='9') {
            continue;
        }
        else return 0;
    }
}

int main(int argc, char *argv[]) {

    FILE *fp1 = fopen(argv[1], "r");
    FILE *fp2 = fopen("integers", "w");
    char inputword[51];

    while(1) {
        int result = fscanf(fp1, "%s", inputword);
        if (result<0) break;

        if (isInteger(inputword)) fprintf(fp2, "%s ", inputword);
    }

    fclose(fp1);
    fclose(fp2);
}