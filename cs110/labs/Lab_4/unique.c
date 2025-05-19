#include <stdio.h>
#include <string.h>

int main() {
    //initialization
    char input[51];
    int alphabet[26], i, numunique=0;
    for (i=0; i<26; i++) {
        alphabet[i] = 0;
    }

    //input
    printf("Enter a string: ");
    scanf("%s", input);

    //computation
    for (i=0; i<strlen(input); i++) {
        alphabet[input[i]-'a'] += 1;
    }

    printf("Unique characters include:");
    for (i=0; i<26; i++) {
        if (alphabet[i] == 1) {
            printf(" %c", i+'a');
            numunique += 1;
        }
    }

    if (numunique==0) printf(" NONE\n");
    else printf("\n");

    return 0;
}