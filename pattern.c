#include <stdio.h>
#include <string.h>

int contains ( const char *text, const char *pattern );

int main (void) 
{
   int patternStart = 0;

   //first test call
   char textA[] = "Hello, World!";
	char patternA[] = "orl";
   patternStart = contains ( textA, patternA );
	if (patternStart != -1) {
	printf("Pattern %s occurs in %s at the location %d.\n", patternA, textA, patternStart);
   }
	else {
	printf("Pattern \"%s\" was not found in \"%s\".", patternA, textA);
	}
	
	//second test call
   char textB[] = "Yellow Ledbetter";
	char patternB[] = "doggy";
   patternStart = contains ( textB, patternB );
	if (patternStart != -1) {
	printf("Pattern %s occurs in %s at the location %d.\n", patternB, textB, patternStart);
   }
	else {
	printf("Pattern \"%s\" was not found in \"%s\".", patternB, textB);
	}
	
	//third test call
   char textC[] = "jack";
	char patternC[] = "computer";
   patternStart = contains ( textC, patternC );
	if (patternStart != -1) {
	printf("Pattern %s occurs in %s at the location %d.\n", patternC, textC, patternStart);
   }
	else {
	printf("\nPattern \"%s\" was not found in \"%s\".\n", patternC, textC);
	}

   //fourth test call
   char textD[] = "Piggy went market, Piggy stayed home";
	char patternD[] = "Piggy";
   patternStart = contains ( textD, patternD );
	if (patternStart != -1) {
	printf("Pattern %s occurs in %s at the location %d.\n", patternD, textD, patternStart);
   }
	else {
	printf("\nPattern \"%s\" was not found in \"%s\".\n", patternD, textD);
	}
   
	//fith test call
   char textE[] = "Space cowboy";
	char patternE[] = "boy";
   patternStart = contains ( textE, patternE );
	if (patternStart != -1) {
	printf("Pattern %s occurs in %s at the location %d.\n", patternE, textE, patternStart);
   }
	else {
	printf("\nPattern \"%s\" was not found in \"%s\".\n", patternE, textE);
	}

   return 0;
}

int contains ( const char *text, const char *pattern ) 
{

   int test = 0;
	int i = 0; //first counter used for text iterating
	int j = 0;  //second counter used for pattern iterating
	int k = 0; //third counter used to search text char vs pattern char
	int textLength = 0;
	int patternLength = 0;
	int patternStart = 0; //used to pass the location of the patterns starting location
	
	//calculates how many chars in text array
	textLength = strlen(text);
	
	//calculates how many chars in pattern array	
	patternLength = strlen(pattern);
		
	//returns -1 if the text your searching in isnt even long enough
	//for the patern to occur
	if (textLength < patternLength) {
	   return -1;
	}
	
	//searches text for pattern
	for (i = 0; i <= textLength - patternLength; i++) {
	   k = i;   
		patternStart = i; //starts the counter through the length of text
		                  //only looking for the start, so can subtract leangth of pattern 
	
	   for (j = 0; j < patternLength; j++) { //searches for the first char of the pattern in the text
	      if (pattern[j] == text[k]) {       //if it finds it,it looks for the second through the last
			   ++k;
			}
		   else {
			   break; //if the text never holds the pattern, break out and go to return line
			}
		}
		if (j == patternLength) {  //if the text holds the pattern by the j loop reaching the length of the pattern
         return patternStart;    //then return the starting location back to main... patternStart
      }	
	}
		
   return -1;	//returns -1 to main if the else statement breaks out of the loop above
}