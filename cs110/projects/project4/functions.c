//Usaid Siddiqui
//This program contians five functions meant to be used in combination with file main.c in order to parse through a csv file and calculate certain statistics

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>


//      Three helper functions used to reformat the shorthand column name, find the index of a specified column name in a row, 
//      and parse through a row to check if a value in a row is blank or not

void columnReformat(char columnName[]) {
    char activityType[15], temp[100]="";
    switch (*columnName) {                      //switch to copy  assignment type based on each corresponding letter in assignment code
        case 'P': 
            strcpy(activityType, "Participation");
            break;
        case 'C':
            strcpy(activityType, "Challenge");
            break;
        case 'L':
            strcpy(activityType, "Lab");
            break;
    }

    strcat(temp, columnName+1);                 //copies assignment code number to temp string
    strcat(temp," - ");
    strcat(temp, activityType);

    strcpy(columnName, temp);           //updates columName pointer to its new, expanded form
}
int findColumnIndex(char *headerLine, char *column) {
    char *token;
    int index = 0;

    // Tokenize the header line to search for the column.
    token = strsep(&headerLine, ",");
    while (token != NULL) {
        if (strncmp(token, column, strlen(column)-1) == 0) {
            return index;
        }
        token = strsep(&headerLine, ",");
        index++;
    }
    return -1;  // Column not found.
}
double checkScore(char *field) {
    if (field == NULL || strlen(field) == 0) {
        return 0.0;  // Return 0.0 if the field is NULL or empty.
    }
    else if (strcmp(field, "N/A") == 0) return -1.0;
    else return atof(field);  // Convert the field to a double if it's valid.
}


//getmin and getmax are nearly identical sister functions with just some minor changes to the numerical logic in finding the maximum versus the minimum
double getMin(char csvfile[], char column[]) {
    FILE *fp1 = fopen(csvfile, "r");
    char line[3000];
    fgets(line, 3000, fp1);

    char columnNameTemp[50];
    strcpy(columnNameTemp, column);
    columnReformat(columnNameTemp);
    int columnIndex = findColumnIndex(line, columnNameTemp);
    if (columnIndex == -1) return -2.0;
    
    double min = 100.1;

    while ((fgets(line, 3000, fp1)) != NULL) {
        char *token = NULL;
        char *row = line;

        for (int i = 0; i <= columnIndex; i++) {
            token = strsep(&row, ",");
        }

        double score = checkScore(token);
        if (score==-1.0) return -1.0;               //returns -1.0 if field is N/A, meaning that the column is optional

        if (strlen(token) > 0 && score < min) {
            min = score;
        }
    }

    fclose(fp1);
    return min;
}
double getMax(char csvfile[], char column[]) {
    FILE *fp1 = fopen(csvfile, "r");
    char line[3000];
    fgets(line, 3000, fp1);

    char columnNameTemp[50];
    strcpy(columnNameTemp, column);
    columnReformat(columnNameTemp);
    int columnIndex = findColumnIndex(line, columnNameTemp);
    if (columnIndex == -1) return -2.0;
    
    double max = -0.1;

    while ((fgets(line, 3000, fp1)) != NULL) {
        char *token = NULL;
        char *row = line;

        for (int i = 0; i <= columnIndex; i++) {
            token = strsep(&row, ",");
        }

        double score = checkScore(token);
        if (score==-1.0) return -1.0;               //returns -1.0 if field is N/A, meaning that the column is optional

        if (strlen(token) > 0 && score > max) {
            max = score;
        }
    }

    fclose(fp1);
    return max;
}

//based off similar to first two functions; keeps running sum and number of grades. calculates and outputs avg at the end
double getAvg(char csvfile[], char column[]) {
    FILE *fp1 = fopen(csvfile, "r");
    char line[3000];
    fgets(line, 3000, fp1);

    char columnNameTemp[50];
    strcpy(columnNameTemp, column);
    columnReformat(columnNameTemp);
    int columnIndex = findColumnIndex(line, columnNameTemp);
    if (columnIndex == -1) return -2.0;
    
    double sum = 0.0;
    int numGrades=0;

    while ((fgets(line, 3000, fp1)) != NULL) {
        char *token = NULL;
        char *row = line;

        for (int i = 0; i <= columnIndex; i++) {
            token = strsep(&row, ",");
        }

        double score = checkScore(token);
        if (score==-1.0) return -1.0;               //returns -1.0 if field is N/A, meaning that the column is optional

        if (strlen(token) > 0) {
            sum += score;
            numGrades++;
        }
    }

    fclose(fp1);
    return (double)sum/numGrades;
}

//again similar structure. checks if each score is higher than threshold. if true, increments 'count' by 1
int getCount(char csvfile[], char column[], double threshold) {
    FILE *fp1 = fopen(csvfile, "r");
    char line[3000];
    fgets(line, 3000, fp1);

    char columnNameTemp[50];
    strcpy(columnNameTemp, column);
    columnReformat(columnNameTemp);
    int columnIndex = findColumnIndex(line, columnNameTemp);
    if (columnIndex == -1) return -2.0;

    int count=0;

    while ((fgets(line, 3000, fp1)) != NULL) {
        char *token = NULL;
        char *row = line;

        for (int i = 0; i <= columnIndex; i++) {
            token = strsep(&row, ",");
        }

        double score = checkScore(token);
        if (score==-1.0) return -1.0;               //returns -1.0 if field is N/A, meaning that the column is optional

        if (strlen(token) > 0 && score >= threshold) {
            count++;
        }
    }

    fclose(fp1);
    return count;
}

//parses through the header row first, locating the weightage for each assignment.
//then proceeds to search the first two columns for a match to the requested student's name
//once found, parses through that student's grades, calculating the sum of the weighted points earned, before dividing them by total points possible at the end to retrieve a grade for the student
double getGrade(char csvfile[], char first[], char last[]){
    FILE *fp1 = fopen(csvfile, "r");

    char line[3000];
    double sum = 0.0, weightedSum = 0.0;
    int studentFound = 0;

    // Read the header row to extract the weights.
    fgets(line, sizeof(line), fp1);
    char *headerRow = line;
    double weights[300];  // Store weights for assignments.
    int numColumns = 0;

    // Parse the header row to extract weights.
    while (headerRow != NULL) {
        char *columnName = strsep(&headerRow, ",");
        if (columnName == NULL) break;

        // Extract weight from the column name (e.g., "5.6 - Participation (8)").
        char *openParen = strrchr(columnName, '(');
        if (openParen != NULL) {
            weights[numColumns] = atof(openParen + 1);  // Extract weight.
        } else {
            weights[numColumns] = 0.0;  // Default weight for non-numeric columns (e.g., names).
        }
        numColumns++;
    }

    // Loop through rows to find the target student.
    while (fgets(line, sizeof(line), fp1)) {
        char *row = line;
        char *token = strsep(&row, ",");  // Last name.

        if (token == NULL || strcasecmp(token, last) != 0) continue;

        token = strsep(&row, ",");  // First name.
        if (token == NULL || strcasecmp(token, first) != 0) continue;

        studentFound = 1;

        // Process the student’s grades using the weights from the header.
        int columnIndex = 2;  // Start from the 3rd column (after names).
        while ((token = strsep(&row, ",")) != NULL) {
            double score = (strlen(token) > 0) ? atof(token) : 0.0;  // Handle blank cells.

            if (weights[columnIndex] > 0) {  // Skip optional sections
                sum += score * weights[columnIndex];
                weightedSum += weights[columnIndex];
            }
            columnIndex++;
        }
        break;  // Exit loop after finding the student.
    }

    fclose(fp1);

    if (!studentFound) return -2.0;  // Student not found.
    return (weightedSum > 0) ? (sum / weightedSum) : 0.0;  // Return weighted average or 0.
}