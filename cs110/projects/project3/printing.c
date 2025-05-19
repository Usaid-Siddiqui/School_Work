//This is a program that takes it an input paragraph and formats it for printing as according to a certain formatting code. 
//It also outputs other details about the print, including the number of dots, spaces, and newlines printed.

//By Usaid Siddiqui

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

int linelength, dots=0, spaces=0, newlines=0;
char justification;

// the number of dots for 'A' (at 0) through 'Z' (at 25)
int dotsUpper[26]={
16, 19, 13, 18, 18, 14, 16,
17, 11, 12, 14, 11, 21, 19,
16, 15, 18, 18, 15, 11, 15,
13, 20, 11, 11, 15
};
// the number of dots for 'a' (at 0) through 'z' (at 25)
int dotsLower[26]={
12, 14,  9, 14, 14, 12, 18,
14,  9, 10, 12, 10, 16, 12,
12, 14, 14,  8, 13, 10, 12,
 9, 14,  9, 16, 13
};

//function signatures
void columnheader(int);                     //prints out row of numbers 0-9 to help with alignment, parameter is length of each line
int dotsprinted(char arr[]);                //counts numbers of dots printed in a certain line, parameter is the currentline string
void stringspaces(char arr[]);              //counts spaces in the currentline string before it it printed. (accounts for grammatical/non formatting strings)

//function definitions
void columnheader(int n) {
    int i=1;
    while (i<n+1) {
        printf("%c", i%10 +'0');
        i++;
    }
    printf("\n");
}
int dotsprinted(char arr[]) {
    int n=0, numdots=0;
    while (arr[n]!='\0') {
        if (islower(arr[n]) && arr[n]!=' ') {
            numdots = numdots + dotsLower[arr[n]-'a'];
        }
        else if (isupper(arr[n]) && arr[n]!=' ') {
            numdots = numdots + dotsUpper[arr[n]-'A'];
        }
        n++;
    }

    return numdots;
}
void stringspaces(char arr[]) {
    int i=0;
    while (1) {
        if (arr[i]=='\0') break;
        else if (arr[i] == ' ') spaces++;
        i++;
    }
}

int main() {
    //inputs
    printf("Enter a formatting code:\n");
    scanf("%c%d", &justification, &linelength);
    printf("Enter a paragraph, ending with <CTRL-D>:\n");

    char currentline[2*linelength];
    char word[linelength];
    strcpy(currentline, "");
    int currentspace=0, i=0;

    columnheader(linelength);

    while ((scanf("%s", word)) != EOF) {
        strcat(currentline, word);
        strcat(currentline, " ");
    
        dots += dotsprinted(word);                          //runs dotcount function for every new word entered into the scanf function, counting num of dots to be printed
        if (strlen(currentline)-1>linelength) {
            currentline[currentspace] = '\0';
            switch (justification) {                        //switch used to print out the line, with each case following a different format based on justification (L, R, or C)
                case 'L':
                    stringspaces(currentline);
                    printf("%s\n", currentline);
                    newlines++;
                    break;

                case 'R':
                    for (i=0; i<linelength-(int)strlen(currentline); i++) {
                        printf(" ");
                        spaces++;
                    }
                    stringspaces(currentline);
                    printf("%s\n", currentline);
                    newlines++;
                    break;

                case 'C':
                    for (i=0; i<(linelength-(int)strlen(currentline))/2; i++) {
                        printf(" ");
                        spaces++;
                    }
                    stringspaces(currentline);
                    printf("%s\n", currentline);
                    newlines++;
                    break;
            }
            strcpy(currentline, word);
            strcat(currentline, " ");
            currentspace = strlen(currentline)-1;
        }
        else currentspace = strlen(currentline)-1;
    }

    currentline[strlen(currentline)-1]='\0';
    switch (justification) {                                //same switch used again to process the final line, which is not handled by the loop
        case 'L':
            stringspaces(currentline);
            printf("%s\n", currentline);
            newlines++;
            break;

        case 'R':
            for (i=0; i<linelength-(int)strlen(currentline); i++) {
                printf(" ");
                spaces++;
            }
            stringspaces(currentline);
            printf("%s\n", currentline);
            newlines++;
            break;

        case 'C':
            for (i=0; i<(linelength-(int)strlen(currentline))/2; i++) {
                printf(" ");
                spaces++;
            }
            stringspaces(currentline);
            printf("%s\n", currentline);
            newlines++;
            break;
    }
    
    columnheader(linelength);

    //output
    printf("\nDots printed: %d\n", dots);
    printf("Spaces printed: %d\n", spaces);
    printf("Newlines printed: %d\n", newlines);
}