#include <stdio.h>
#include <string.h>

int main() {
    char word1 [20];
    char word2 [20];
    char word3 [20];

    printf("Enter your three words:\n");
    scanf("%s %s %s", word1, word2, word3);

    if (strcmp(word1,word2)==0) {
        if (strcmp(word3,word1)==0) {
            printf("All three are the same.\n");
        }
        else {
            printf("Two of them are the same.\n");
        }
    }
    else if (strcmp(word1,word3)==0) {
            printf("Two of them are the same.\n");
        }

    else if (strcmp(word2,word3)==0) {
            printf("Two of them are the same.\n");
        }
    else {
        printf("They are completely different.\n");
    }
}