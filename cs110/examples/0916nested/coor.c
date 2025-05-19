#include <stdio.h>

int main(){
    printf("Enter a number:\n");
	int num;
   scanf("%d", &num);
	for (int r=0; r<num; r++) {
		for (int c=0; c<num; c++)
			printf("<%d-%d> ", r, c);
		printf("\n");
	}

    return 0;
}