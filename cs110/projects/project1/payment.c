#include <stdio.h>
#include <math.h>

int main(){
    int quarters, dimes, nickels, pennies;

    //inputs
    printf("Enter the number of quarters:\n");
    scanf("%d", &quarters);
    printf("Enter the number of dimes:\n");
    scanf("%d", &dimes);
    printf("Enter the number of nickels:\n");
    scanf("%d", &nickels);
    printf("Enter the number of pennies:\n");
    scanf("%d", &pennies);

    //variables
    int dollars=0;
    int twenties=0;
    int tens=0;
    int fives=0;
    int ones=0;
    int totalmoneyrounded;
    double totalmoney=0, coinweightgrams=0, coinweightpounds=0,grams=0, pounds=0;
    double cents=0;

    //calculations
    totalmoney = 0.25*quarters + 0.1*dimes + 0.05*nickels + 0.01*pennies;
    coinweightgrams = 5.67*quarters + 2.268*dimes + 5.0*nickels + 2.5*pennies;
    coinweightpounds = coinweightgrams * 0.00220462;
    dollars = (int)totalmoney;
    cents = (totalmoney-dollars)*100;
    
    totalmoneyrounded = (int)round(totalmoney);
    twenties = totalmoneyrounded/20;
    tens = (totalmoneyrounded-(20*twenties))/10;
    fives = (totalmoneyrounded-(20*twenties)-(10*tens))/5;
    ones = (totalmoneyrounded-(20*twenties)-(10*tens)-(5*fives));

    grams = twenties + tens + fives + ones;
    pounds = grams * 0.00220462;

    //output
    printf("Total payment is %d dollars and %d cents.\n", dollars, (int)round(cents));
    printf("Total weight of all the coins is %lf pounds.\n", coinweightpounds);
    printf("It is recommended to use the following payment form:\n");
    printf("\t%d twenty-dollar bills\n", twenties);
    printf("\t%d ten-dollar bills\n", tens);
    printf("\t%d five-dollar bills\n", fives);
    printf("\t%d one-dollar bills\n", ones);
    printf("It achieves the minimal weight of %d grams or %lf pounds.\n", (int)grams, pounds);

}