#include <stdio.h>
#include <string.h>

int main() {
    char input[51];
    int alphabet[26], i, noneletters=0;
    printf("Enter your input:\n");

    for (i=0; i<26; i++) {
        alphabet[i] = 0;
    }

    while (1) {
        scanf("%s", input);
        if (feof(stdin)) break;
        for (i=0; i<strlen(input); i++) {
            alphabet[input[i]-'a'] += 1;
        }
    }

    for (i=0; i<26; i++) {
        if (alphabet[i] == 0) {
            noneletters += 1;
        }
    }

    if (noneletters!=0) {
        printf("Missing letters:");
        for (i=0; i<26; i++) {
        if (alphabet[i]==0) printf(" %c", i+'a');
        }
        printf("\n");
    }
    else printf("Your input contains all the letters\n");
}