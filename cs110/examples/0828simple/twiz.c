#include <stdio.h>
#include <math.h>

int main(){
    // input
    double distMiles;
    printf("How far is Tuscaloosa from your hometown, in miles?");
    scanf("%lf", &distMiles);

    // computation
    int distPackageInch=25*7;
    int distInch=distMiles*5280*12;
    double numPackages=(double)distInch/distPackageInch;

    // output
    printf("Your hometown is %d whole packages of twizzlers away from Tuscaloosa\n", (int)ceil(numPackages));
    printf("To be exact, it is %lf twizzler packages away\n", numPackages);

    return 0;
}