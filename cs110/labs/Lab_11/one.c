#include <stdio.h>
#include <stdlib.h>

int ones(int num)
{
	if (num==0) {
        return 0;
    }
    else if (num % 2 == 1) {
        return 1 + ones(num / 2);
    } 
    else {
        return ones(num / 2); 
    }
}

int main(int argc, char *argv[])
{
    if (argc!=2) {
        printf("Usage: %s num\n", argv[0]);
        return 1;
    }

    int val=atoi(argv[1]);
	if (val<0) {
        printf("%s requires a non-negative integer as its argument\n", argv[0]);
        return 1;
    }

    printf("%d in binary contains %d ones\n", val, ones(val));

    return 0;
}

