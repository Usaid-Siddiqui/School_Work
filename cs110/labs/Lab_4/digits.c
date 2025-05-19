#include <stdio.h>
#include <string.h>

int main() {
    char inputnum[20];
    int digits[10]={0,0,0,0,0,0,0,0,0,0}, i, duplicate=0;
    printf("Enter your integer: ");
    scanf("%s", inputnum);

    for (i=0;i<strlen(inputnum);i++) {
        digits[inputnum[i]-48] += 1;
    }
    
    /*for (i=0; i<10; i++) {
        printf("%d\n", digits[i]);
    }
    */

    for (i=0; i<10; i++) {
        if (digits[i]>1) {
            duplicate = 1;
            break;
        }
    }

    if (duplicate==1) printf("Duplicate digits found\n");
    else printf("No duplicate digits found\n");
}