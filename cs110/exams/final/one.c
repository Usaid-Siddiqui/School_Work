#include <stdio.h>
#include <limits.h>

// Do not modify the signature of this function
void compute(int n, int x[], int lower, int upper, int *pCount, int *pMax, int *pMin)
{
        int count=0;
        int min = INT_MAX;
        int max = INT_MIN;

        for (int i=0; i<n; i++) {
                if (x[i]<=upper && x[i]>=lower) {
                        count++;
                        if (x[i]<min) min = x[i];
                        if (x[i]>max) max = x[i];
                }
        }

        *pCount=count;
        *pMax=max;
        *pMin=min;

        return;
}

// Do not change anything below this line
int main(void)
{
        printf("How many integers? ");
        int size;
        scanf("%d", &size);
        printf("Enter %d integers:\n", size);
        int array[size];
        for (int i=0; i<size; i++) {
                scanf("%d", &array[i]);
        }
        printf("Enter lower and upper bounds to identify the subset:\n");
        int lower, upper;
        scanf("%d%d", &lower, &upper);
        int count;
        int max;
        int min;
        compute(size, array, lower, upper, &count, &max, &min);
        if (count>0) {
                printf("There are %d elements between %d and %d\n", count, lower, upper);
                printf("The maximum of the subset is %d\n", max);
                printf("The minimum of the subset is %d\n", min);
        }
        else {
                printf("There are no elements between %d and %d\n", lower, upper);
        }
        return 0;
}
