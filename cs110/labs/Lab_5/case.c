#include <stdio.h>
#include <string.h>
#include <ctype.h>

void countCase(char str[], int *pNumUpper, int *pNumLower);

int main() {
   char word[50];
   int numUpper, numLower;
   
   printf("Enter your input: ");
   while (scanf("%s", word) != EOF) {
      // Reset counters
      numUpper = 0;
      numLower = 0;

      // Count uppercase and lowercase letters
      countCase(word, &numUpper, &numLower);

      // Output the result
      printf("\n%s: %d uppercase, %d lowercase", word, numUpper, numLower);
   }
   printf("\n");
   return 0;
}

void countCase(char str[], int *pNumUpper, int *pNumLower) {
   for (int i = 0; str[i]!='\0'; i++) {
      if (isupper(str[i])) {
         (*pNumUpper)++;
      } 
      else if (islower(str[i])) {
         (*pNumLower)++;
      }
    }
}