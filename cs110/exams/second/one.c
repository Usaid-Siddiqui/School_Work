#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int num = atoi(argv[1]);
    
    for (int r=0; r<num; r++) {
		for (int c=0; c<num; c++)
			if (r+c==num-1||c==num-1||r==num-1||r==0||c==0||r==c) 
				printf("O");
			else
				printf(" ");
		printf("\n");
	}


    return 0;
}