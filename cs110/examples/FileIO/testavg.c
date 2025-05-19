#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc>3) {
        printf("Usage: %s input_file output_file\n", argv[0]);
        return 100;
    }

    int sum=0;
    FILE *fp=stdin;
    if (argc>1) fp=fopen(argv[1], "r");
    if (fp==NULL) {
        printf("Unable to open %s for reading\n", argv[1]);
        return 1;
    }
    int i=0; // the size
    while (1) {
        // read
        int num;
        int result=fscanf(fp, "%d", &num);
        // check
        if (result<1) break;
        // process
        sum += num;
        i++;
    }
    if (argc>1) fclose(fp);

    FILE *fp2=stdout;
    if (argc>2) fp2=fopen(argv[2], "w");
    if (fp2==NULL) {
        printf("Unable to open %s for writing\n", argv[2]);
        return 2;
    }
    fprintf(fp2, "count=%d, sum=%d, avg=%g\n", i, sum, (double)sum/i);
    if (argc>2) fclose(fp2);

    return 0;
}