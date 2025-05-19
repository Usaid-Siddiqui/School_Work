#include <stdio.h>
#include <ctype.h>
		
int main(void) {
	char a = 'I', b = 'B', c = 'M';
	printf("%c %c %c\n", a, b, c);
    printf("%d %d %d\n", a, b, c);
	printf("%c %c %c\n", a-1, b+1, c+32);
    printf("islower(%c)=%d\n", a, islower((int)(a)));

    return 0;
}