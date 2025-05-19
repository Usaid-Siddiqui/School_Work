#include <stdio.h>
#include <string.h>

int main(){
    char integer[20];
    int i, a=0;
    printf("Enter a non negative integer of your choice:\n");
    scanf("%s", integer);

    for (i=0; i < (strlen(integer)); ++i) {
        a = a + integer[i] - 48;
    }

    printf("%d\n", a);

}