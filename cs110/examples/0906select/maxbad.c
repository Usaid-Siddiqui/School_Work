#include <stdio.h>

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

	int max;
	if (a>=b && a>=c && a>=d) max=a;
	if (b>=a && b>=c && b>=d) max=b;
	if (c>=a && c>=b && c>=d) max=c;
	if (d>=a && d>=b && d>=c) max=d;

	printf("Max is %d\n", max);

	return 0;
}