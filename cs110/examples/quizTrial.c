#include <stdio.h>
#include <stdlib.h>

int* func1(int n, int m) {
    int *p = (int *) malloc (sizeof(int) * n);
    for (int k=0; k<n; k++) {
        p[k] = m + k;
    }
    return p;
}

char *func2 (int n, char ch) {
    char *data;
    data = (char *) malloc(n+1);
    data[n] = '\0';
    for (int j=0; j<n; j++) {
        data[j] = ch + j;
    }
    return data;
}

int main(void) {
    int *z = func1(5, 2);
    char *b = func2(3, 'X');
    char *c = func2(4, 'a');
    printf("%s %s\n", b, c);
    for (int a=0; a<5; a++) printf("%d\n", z[a]);
    return 0;
}