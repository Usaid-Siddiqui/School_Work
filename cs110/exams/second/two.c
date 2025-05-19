#include <stdio.h>

void findMode(int size, int x[], int *pMode, int *pCount)
{
    int scoreFreq[11]={0,0,0,0,0,0,0,0,0,0,0};      //possible quiz scores from 0 to 10. Keeps track of how often each score repeats
    int temp, i, mode, max=0;
    for (i=0; i<size; i++) {
        temp = x[i];
        scoreFreq[temp]++;
    }

    for (i=0; i<=10; i++) {
        if (scoreFreq[i]>=max) {
            mode = i;
            max = scoreFreq[i];
        }
    }

    *pMode = mode;
    *pCount = max;
}

// Do not change anything below this line
int getIntCount(char filename[]) {
    int count=0;
    FILE *fp=fopen(filename, "r");
    if (fp==NULL) return -1;
    while (1) {
        // read
        int num;
        int result=fscanf(fp, "%d", &num);
        // check
        if (result<1) break;
        // process
        count++;
    }
    fclose(fp);
    return count;
}

void getIntArray(char filename[], int x[], int size) {
     FILE *fp=fopen(filename, "r");
    for (int i=0; i<size; i++) {
        fscanf(fp, "%d", &x[i]);
    }
    fclose(fp);
}

int main(int argc, char *argv[])
{
    if (argc!=2) {
        printf("Usage: %s filename\n", argv[0]);
        return 1;
    }
    int size=getIntCount(argv[1]);
    if (size<=0) {
        printf("No scores read\n");
        return 2;
    }
    int array[size];
    getIntArray(argv[1], array, size);

    int mode, count;
    findMode(size, array, &mode, &count);
    
    printf("The mode is %d and it appears %d times\n", mode, count);

    return 0;
}
