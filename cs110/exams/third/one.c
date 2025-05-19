#include <stdio.h>

// order three integers from the smalles to the largest
void order(int *pX, int *pY, int *pZ) {
    int arr[3] = {*pX, *pY, *pZ};
    int max=-99999, min=99999, mid=0;
    for (int i=0; i<3; i++) {
        if (arr[i]<=min) min=arr[i];
        if (arr[i]>=max) max=arr[i];
    }
    for (int i=0; i<3; i++) {
        if (arr[i]<max && arr[i]>min) mid=arr[i];
    }
    if (arr[1]==arr[2]||arr[0]==arr[2]) mid = arr[2];
    if (arr[1]==arr[0]) mid = arr[1];
    *pX = min;
    *pY = mid;
    *pZ = max;
}

// do not change anyting below
int main() {
    int x, y, z;
    printf("Enter three integers: ");
    scanf("%d%d%d", &x, &y, &z);
    order(&x, &y, &z);
    printf("The result after ordering: %d %d %d\n", x, y, z);

    return 0;
}

