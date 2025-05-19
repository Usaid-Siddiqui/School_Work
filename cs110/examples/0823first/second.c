#include <stdio.h>

int main(){
    int a, b;
    printf("Enter the first integer: ");
    scanf("%d", &a);
    printf("Enter the second integer: ");
    scanf("%d", &b);
    int sum;
    sum=a/b;
    printf("The result is %d\n", sum);
    return 0;
}