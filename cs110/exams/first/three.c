#include <stdio.h>
#include <string.h>

int main() {
    int i, n, maxlength=0;
    char inputword[25], longestword[25];

    printf("How many words: ");
    scanf("%d", &n);

    printf("Enter %d words: ", n);
    for (i=0; i<n; i++) {
        scanf("%s", inputword);
        if (strlen(inputword)>=maxlength) {
            maxlength = strlen(inputword);
            strcpy (longestword, inputword);
        }

    }
    printf("The longest word is \"%s\", and its length is %d.\n", longestword, maxlength);
    return 0;
}