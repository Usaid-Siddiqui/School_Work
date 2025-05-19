#include <stdio.h>
#include <stdlib.h>

int isosceles=0, equilateral=0, total=0;
int main(int argc, char *argv[]) {
    FILE *fp = fopen(argv[1], "r");
    
    while (1) {
        int side1, side2, side3;
        int result = fscanf(fp, "%d", &side1);
        if (result<1) break;                            //handles EOF

        fscanf(fp, "%d", &side2);
        fscanf(fp, "%d", &side3);
        
        total++;

        if (side1==side2 && side2==side3) {
            equilateral++;
            isosceles++;
        }
        else if (side1==side2 || side2==side3 || side3==side1) isosceles++;
    }

    printf("%d out of %d triangles are isosceles.\n", isosceles, total);
    printf("%d of them are equilateral.\n", equilateral);
    return 0;
}