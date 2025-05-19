#include <stdio.h>

int main(void)
{
    int score;
    printf("Enter a score: ");
    scanf("%d", &score);

    if (score<0 || score>100) {
        printf("%d is an invalid score\n", score);
        return 1;
    }

    char letter;
    if (score>=90) letter='A';
    if (score>=80 && score<90) letter='B';
    if (score>=70 && score<80) letter='C';
    if (score>=60 && score<70) letter='D';
    if (score<60) letter='F';

    printf("The letter grade is %c\n", letter);
    
    return 0;
}