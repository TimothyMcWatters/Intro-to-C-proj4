#include <stdio.h>
#include <string.h>

typedef struct {
	   char from[28];
		char to[28];
	} CodeT;

void encodeStr ( char *input, char *output, CodeT code );
void decodeStr ( char *input, char *output, CodeT code );

int main (void)
{
  	int i = 0;
	int stringLength = 0;
	CodeT code = {   .from = " abcdefghijklmnopqrstuvwxyz",  
	                 .to = ".172093%@#+!:_-$^*()854=6?>" };//encryption key
   
   do { // Starts the loop to run until no empty text is input via '\n'
	
	// Initializes each array every iteration of the program (eliminates stray characters)
	char input[50] = ""; 	
	char output[50] = "";
	char temp[50] = "";


	//gathers user input to encode
	printf("Enter text line: ");
   fgets(input, 49, stdin);
	
	// Ends the program when the user inputs empty text via '\n'
	if (input[0] == '\n') {
	   return 0;
		break;
	}
	
	// Invokes the encodeStr function to encode the users input
	encodeStr ( input, output, code);
	printf("Encoded string: %s\n", output);

   // Changes the output of the encode function to input for use in the decode function
   stringLength = strlen(output);
	for (i = 0; i < stringLength; ++i) {
	   input[i] = output[i];
	}

   // Invokes the decodeStr function to decode the previously encoded users input
	decodeStr ( input, output, code);
	printf("Decoded string: %s\n\n", output);

   } while (1); // Continues to ask for user input until user inputs empty text and 0 is returned

   return 0;
}

// Encodes the users input
void encodeStr ( char *input, char *output, CodeT code )
{
   int inputLength = 0; 
	int i = 0; 
	int j = 0;
	int k = 0;
	
	inputLength = strlen(input); // Computes the length of input for use in the for loop 
	
	// Loops to find when input char equals code.from char using by incrementing through code.from
	for (i = 0; i < inputLength - 1; ++i) {
	   while (input[i] != code.from[k]) {
		   ++k; // Iterates code.from char by char trying to match input[i] 
		}
		output[i] = code.to[k]; // sets output array to the coded input array char by char
		k = 0; // Resets k to zero to start the for loop over again fresh
	}	
	
   return;
}

// Decodes the encoded message (originally the users input)
void decodeStr ( char *input, char *output, CodeT code )
{
   int inputLength = 0; 
	int i = 0; 
	int j = 0;
	int k = 0;
	
	inputLength = strlen(input); // Computes the length of input for use in the for loop 

	// Loops to find when input char equals code.to char using by incrementing through code.to
	for (i = 0; i < inputLength - 1; ++i) {
	   while (input[i] != code.to[k]) {
		   ++k; // Iterates code.to char by char trying to match input[i] 
		}
		output[i] = code.from[k]; // sets output array to the now uncoded input array char by char
		k = 0; // Resets k to zero to start the for loop over again fresh
	}	
		
   return;
}