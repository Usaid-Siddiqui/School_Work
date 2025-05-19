#include <stdio.h>
#include <string.h>

//Usaid Siddiqui Project 1
//This is a tax filing program based on the Alabama Tax Law in 2023

int filingstatus, dependants, income, fedtaxdeduct, itemdeduct;


int main(){

    //inputs
    printf("Enter filing status 1-4:\n");
    scanf("%d", &filingstatus);
    while (filingstatus<1 || filingstatus>4) {
        printf("Error, enter a number from 1 through 4. Please enter a new value.\n");
        scanf("%d", &filingstatus);
    }

    printf("Enter number of dependants:\n");
    scanf("%d", &dependants);
    if (dependants<0) dependants = 0;

    printf("Enter adjusted gross income:\n");
    scanf("%d", &income);
    if (income<0) income = 0;

    printf("Enter itemized tax deduction:\n");
    scanf("%d", &itemdeduct);
    if (itemdeduct<0) itemdeduct = 0;

    printf("Enter federal tax deduction:\n");
    scanf("%d", &fedtaxdeduct);
    if (fedtaxdeduct<0) fedtaxdeduct = 0;




    //computation
    int bracket, standeduction, personalexemp, dependexemp, taxableincome;
   
    switch (filingstatus) {
    case 1:
    if (income<26000) standeduction=3000;
    else if (income>=35500) standeduction = 2500;
    else {
    bracket = (income-26000)/500 + 1;
    standeduction = 3000 - 25*bracket;
    }
    break;

    case 2:
    if (income<2600) standeduction=8500;
    else if (income>=35500) standeduction = 5000;
    else {
    bracket = (income-26000)/500 + 1;
    standeduction = 8500 - 175*bracket;
    }
    break;

    case 3:
    if (income<13000) standeduction=4250;
    else if (income>=17750) standeduction = 2500;
    else {
    bracket = (income-13000)/500 + 1;
    standeduction = 4250 - 88*bracket;
    }
    break;

    case 4:
    if (income<2600) standeduction=5200;
    else if (income>=35500) standeduction = 2500;
    else {
    bracket = (income-26000)/500 + 1;
    standeduction = 5200 - 135*bracket;
    break;
    }
    }
    printf("Standard deduction=%d\n", standeduction);


    if (filingstatus==1 || filingstatus==3) personalexemp=1500;
    else personalexemp=3000;
    printf("Personal exemption=%d\n", personalexemp);

    if (income>100000) dependexemp = 300*dependants;
    else if (income>50000) dependexemp = 500*dependants;
    else dependexemp = 1000*dependants;
    printf("Dependent exemption=%d\n", dependexemp);

    taxableincome = income - fedtaxdeduct - dependexemp - personalexemp;
    if (standeduction>itemdeduct) taxableincome-=standeduction;
    else taxableincome-=itemdeduct;

    if (taxableincome<0) taxableincome=0;
    printf("Taxable=%d\n", taxableincome);

    double tax;


    if (filingstatus!=2) {
        if (taxableincome>3000) tax = (taxableincome-3000)*0.05 + 2500*0.04 + 0.02*500;
        else if (taxableincome>500) tax = (taxableincome-500)*0.04 + 0.02*500;
        else tax = taxableincome*0.02;
    }
    else {
        if (taxableincome>6000) tax = (taxableincome-6000)*0.05 + 5000*0.04 + 0.02*1000;
        else if (taxableincome>500) tax = (taxableincome-1000)*0.04 + 0.02*1000;
        else tax = taxableincome*0.02;
    }


    //output
    printf("Tax is %d\n", (int)(tax+0.5));

    return 0;
}