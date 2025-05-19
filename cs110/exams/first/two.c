#include <stdio.h>

int main() {
    int n, i;
    double inputweight, cost=0;

    //input
    printf("How many packages to be mailed? ");
    scanf("%d", &n);

    printf("Enter the weight of %d these packages: ", n);
    for (i=0; i<n; i++) {
        scanf("%lf", &inputweight);
        if (inputweight > 12) cost+=5.5;
        else if (inputweight > 11) cost+=5.15;
        else if (inputweight > 10) cost+=4.8;
        else if (inputweight > 9) cost+=4.45;
        else if (inputweight > 8) cost+=4.1;
        else if (inputweight > 4) cost+=3.75;
        else cost+=3.5;
    }

    printf("Total postage is %lf\n", cost);

    return 0;
}