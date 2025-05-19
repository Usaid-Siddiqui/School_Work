#include <stdio.h>
#include <limits.h>

int main(void) {

	int sum = 0;
	int i = 0;

	while (1) {
		// read
		int a;
   		printf("Enter integer #%d: ", i+1);
		scanf("%d", &a);
		// check
		if (a==-1) break;
		sum += 1;
		i++;
	}

	printf("Average is %lf\n", (double)sum/i);

	return 0;
}