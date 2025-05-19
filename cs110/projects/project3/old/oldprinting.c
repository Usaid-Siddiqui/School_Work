//This is a program that takes it an input paragraph and formats it for printing as according to a certain formatting code. 
//It also outputs other details about the print, including the number of dots, spaces, and newlines printed.

//By Usaid Siddiqui

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

//function signatures
int dotsprinted(void);          //no parameter, returns number of dots printed
int spacesprinted(void);        //no parameter, returns number of spaces printed

void columnheader(int);         //prints out row of numbers 0-9 to help with alignment

void leftjustified(int);        //These three functions each correspond to a formatting type, and are called using a switch
void rightjustified(int);       //parameter is number of charactersper line, formats string as needed to be printed
void centerjustified(int); 

//global variables
char formatletter, input;
int formatnum, z=0, newlines=0, allignmentspaces=0; //allignmentspaces acounts for non-grammatical spaces introduced through the formatting
char paragraph[1000000];

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


int dotsprinted(void) {
    int n=0, numdots=0;
    while (1) {
        if (paragraph[n]=='\0') break;
        else if (islower(paragraph[n]) && paragraph[n]!=' ') {
            numdots = numdots + dotsLower[paragraph[n]-'a'];
        }
        else if (isupper(paragraph[n]) && paragraph[n]!=' ') {
            numdots = numdots + dotsUpper[paragraph[n]-'A'];
        }
        n++;
    }

    return numdots;
}
int spacesprinted(void) {
    int i=0, numspaces=0;
    while (1) {
        if (paragraph[i]=='\0') break;
        else if (paragraph[i] == ' ') {
            numspaces += 1;
        }
        i++;
    }

    return numspaces+allignmentspaces;
}

void columnheader(int n) {
    int i=1;
    while (i<n+1) {
        printf("%c", i%10 +'0');
        i++;
    }
}

void leftjustified(int linelength) {
    int i, recentspace=0, lastcut=1;
    for (i=0; i<1000; i++) {
        if (paragraph[i]=='\0') {
            if (i-lastcut<=linelength) {
                recentspace=i;
            }
            else {
                paragraph[recentspace] = '\n';
                newlines++;
                lastcut=recentspace+1;
            }
            break;
        }
        else if (paragraph[i] == ' ') {
            if (i-lastcut<=linelength) {
                recentspace=i;
            }
            else {
                paragraph[recentspace] = '\n';
                lastcut=recentspace+1;
                recentspace=i;
                newlines++;
            }
        }
    }
    return;
}
void rightjustified(int linelength) {
    int i=1, n=0, k=0, j=0;
    while(paragraph[i]!='\0') {
        if (paragraph[i] == '\n') {
            for (j=0; j<linelength-n; j++) {
                printf(" ");
                allignmentspaces++;
            }
            for (k=i-n; k<i; k++) {
                printf("%c", paragraph[k]);
            }
            printf("\n");
            n=0;
        }
        else {
            n++;
        }
        i++;
    }

    if (n > 0) {
        for (j = 0; j < linelength - n; j++) {
            printf(" ");
            allignmentspaces++;
        }
        for (k = i - n; k < i; k++) {
            printf("%c", paragraph[k]);
        }
        printf("\n");
    }
    return;
}
void centerjustified(int linelength) {
    int i=1, n=0, k=0, j=0;
    
    while(paragraph[i]!='\0') {
        if (paragraph[i] == '\n') {
            for (j=0; j<(linelength-n)/2; j++) {
                printf(" ");
                allignmentspaces++;
            }
            for (k=i-n; k<i; k++) {
                printf("%c", paragraph[k]);
            }
            printf("\n");
            n=0;
        }
        else {
            n++;
        }
        i++;
    }
    
    if (n > 0) {
        for (j = 0; j < (linelength - n)/2; j++) {
            printf(" ");
            allignmentspaces++;
        }
        for (k = i - n; k < i; k++) {
            printf("%c", paragraph[k]);
        }
        printf("\n");
    }
    return;
}


int main() {
    //inputs
    printf("Enter a formatting code:\n");
    scanf("%c%d", &formatletter, &formatnum);
    printf("Enter a paragraph, ending with <CTRL-D>:\n");
    
    while ((input = getchar()) != EOF) {
        if (input == '\n' && z!=0) paragraph[z++] = ' ';
        else paragraph[z++] = input;
    }
    paragraph[z-1] = '\0'; //adds null character

    columnheader(formatnum);

    switch (formatletter) {                 //Runs correct function based on inputted formatting code
        case 'L':                           //Each function is called with the line length as a parameter
            leftjustified(formatnum);
            printf("%s\n", paragraph);
            break;

        case 'R':
            printf("\n");
            leftjustified(formatnum);
            rightjustified(formatnum);
            break;

        case'C':
            printf("\n");
            leftjustified(formatnum);
            centerjustified(formatnum);
            break;
    }

    columnheader(formatnum);

    //output
    printf("\n\nDots printed: %d\n", dotsprinted());
    printf("Spaces printed: %d\n", spacesprinted());
    printf("Newlines printed: %d\n", newlines+1);           //+1 accounts for last newline when paragraph ends

    return 0;
}