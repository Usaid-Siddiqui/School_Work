#include <stdio.h>

int main(){
    double wage, weeklypay=0;
    int hours;
    printf("Enter your hourly wage as well as the number of hours worked per week: \n");
    scanf("%lf %d", &wage, &hours);
    if (hours<=40) {
        weeklypay = hours*wage;
    }
    else if (hours<=50) {
        weeklypay = (40*wage)+((hours-40)*wage*1.5);
    }
    else if (hours>50) {
        weeklypay = (40*wage)+(10*1.5*wage)+((hours-50)*wage*2);
    }

    //output
    printf("%lf\n", weeklypay);
}