#include <stdio.h>

int main(){
    int score;
    printf("Enter your score: ");
    scanf("%d", &score);

    if (score>=60) {
        printf("You Passed.\n");
        printf("Good Work!\n");
    }

    return 0;
}