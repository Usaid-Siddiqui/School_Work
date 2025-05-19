#include <stdio.h>
#include <string.h>

int main() {
    char input[50];
	int a=0, e=0, i=0, o=0, u=0, j=0;

    while (1) {
        scanf("%s", input);
        if (feof(stdin)) break;
        for (j=0; j<(strlen(input));j++) {
            if (input[j]=='a') a+=1;
            else if (input[j]=='e') e+=1;
            else if (input[j]=='i') i+=1;
            else if (input[j]=='o') o+=1;
            else if (input[j]=='u') u+=1;
        } 
        printf("i appears %d times\n",i);
    }


	printf("The vowel a occurred %d times\n", a);
    printf("The vowel e occurred %d times\n", e);
    printf("The vowel i occurred %d times\n", i);
    printf("The vowel o occurred %d times\n", o);
    printf("The vowel u occurred %d times\n", u);

	return 0;
}