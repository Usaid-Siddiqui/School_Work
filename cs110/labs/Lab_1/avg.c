#include <stdio.h>

int main(){

    // inputs
    int first_num, second_num, third_num, fourth_num;
    printf("Enter your first integer: ");
    scanf("%d", &first_num);

    printf("Enter your second second: ");
    scanf("%d", &second_num);

    printf("Enter your third third: ");
    scanf("%d", &third_num);

    printf("Enter your fourth fourth: ");
    scanf("%d", &fourth_num);

    // calculation
    double average;
    average = (first_num + second_num + third_num + fourth_num)/4.0;

    // output
    printf("The average is %lf\n", average);

}