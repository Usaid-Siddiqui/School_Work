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
		if (feof(stdin)) break;
		sum += 1;
		i++;
	}

	printf("i = %d, Average is %lf\n", i, (double)sum/i);

	return 0;
}