#include <stdio.h>
#include <limits.h>

int main(void)
{
	int a;
	int max = INT_MIN;
	int iterations;
	printf("Enter the number of numbers you would like to test:\n");
	scanf("%d", &iterations);

	for (int i=0; i<iterations; i++) {
   	printf("Enter integer #%d: ", i+1);
	scanf("%d", &a);
    if (a>max) max=a;
	}

	printf("Max is %d\n", max);

	return 0;
}