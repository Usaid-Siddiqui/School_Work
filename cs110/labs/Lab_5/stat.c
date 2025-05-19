#include <stdio.h>
#include <math.h>

int getInt(char prompt[]);
void getData(char prompt[], int array[], int size);
void calcMeanStdDev(int array[], int size, double *pMean, double *pStdDev);
void printResults(double mean, double stdDev);

int main() {
	int size = getInt("Enter the array size:\n");
	int array[size];
	getData("Enter the numbers:\n", array, size);
	
	double mean, stdDev;
	calcMeanStdDev(array, size, &mean, &stdDev);
	printResults(mean, stdDev);
	
	return 0;
}

// YOUR CODE BELOW HERE
int getInt(char prompt[]) {
	int val;
	printf("%s", prompt);
	scanf("%d", &val);
	return val;
}

void getData(char prompt[], int array[], int size) {
	int i;
	printf("%s", prompt);
	for (i=0; i<size; i++) {
		scanf("%d", &array[i]);
	}
}

void calcMeanStdDev(int array[], int size, double *pMean, double *pStdDev) {
	int i, j, sum=0;
	double variancesum=0;
	for (i=0; i<size; i++) {
		sum+=array[i];
	}
	*pMean = (double)sum/size;
	double tempmean = (double)sum/size;

	for (j=0; j<size; j++) {
		variancesum = variancesum + (array[j]-tempmean)*(array[j]-tempmean);
	}
	*pStdDev = sqrt(variancesum/(size*1.0));
}

void printResults(double mean, double stdDev) {
	printf("The mean is %.2f and the standard deviation is %.2f\n", mean, stdDev);
}

