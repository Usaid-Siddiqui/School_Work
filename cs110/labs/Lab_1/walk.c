#include <stdio.h>

int main(){
    //inputs
    int start_time_h, start_time_m, end_time_h, end_time_m;
    printf("Enter the start time: ");
    scanf("%d %d", &start_time_h, &start_time_m);
    printf("Enter the end time: ");
    scanf("%d %d", &end_time_h, &end_time_m);

    //calculations
    int total_start_min, total_end_min, min_walked;
    total_start_min = start_time_h*60 + start_time_m;
    total_end_min = end_time_h*60 + end_time_m;

    min_walked = total_end_min - total_start_min;
    double hrs_walked, miles_walked;
    hrs_walked = min_walked/60.0;
    miles_walked = hrs_walked * 4.0;

    //output
    printf("You have walked %lf miles.\n", miles_walked);
}