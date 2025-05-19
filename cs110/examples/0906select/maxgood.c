#include <stdio.h>
#include <limits.h>

int main(void)
{
	int a, b, c, d;
	printf("Enter integer #1: ");
	scanf("%d", &a);
	printf("Enter integer #2: ");
	scanf("%d", &b);
	printf("Enter integer #3: ");
	scanf("%d", &c);
	printf("Enter integer #4: ");
	scanf("%d", &d);

	int max = INT_MIN;
    if (a>max) max=a;
	if (b>max) max=b;
	if (c>max) max=c;
	if (d>max) max=d;

	printf("Max is %d\n", max);

	return 0;
}