#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	if (argc!=2) {
		printf("Usage: %s num\n", argv[0]);
		return 1;
	}
	int num=atoi(argv[1]);
	for (int r=0; r<num; r++) {
		for (int c=0; c<num; c++)
			if (r+c==num-1||c==num-1||r==num-1) 
				printf("X");
			else
				printf(" ");
		printf("\n");
	}

    return 0;
}