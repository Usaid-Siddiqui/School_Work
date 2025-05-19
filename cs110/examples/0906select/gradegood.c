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
    if (score>=90) 
        letter='A';
    else if (score>=80) 
        letter='B';
    else if (score>=70)
        letter='C';
    else if (score>=60)
        letter='D';
    else
        letter='F';

    printf("The letter grade is %c\n", letter);
    
    return 0;
}