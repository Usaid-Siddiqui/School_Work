#include <stdio.h>
#include <math.h>

int main(){
    // input
    int temp_f;
    printf("Enter a temperature in Fahrenheit: ");
    scanf("%d", &temp_f);

    // computation
    double temp_c;
    temp_c=(5.0/9)*(temp_f-32);


    // output
    printf("%d degrees Fahrenheit is %lf degrees Celsius\n", temp_f, temp_c);
    printf("%d degrees Fahrenheit is %d degrees Celsius\n", temp_f, (int)round(temp_c));

    return 0;
}