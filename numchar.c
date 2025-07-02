
#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 10

/*
 *     This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

    This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along with this program. If not, see <https://www.gnu.org/licenses/>. 
 *
**/


/*
 * Program that takes as input a string, and returns the number
 * of characters in that string. Input can be provided either via
 * piping or by providing an argument.
 *
**/

// Function to read input from stdin and return the number of characters
// in it.
unsigned int read_from_stdin() {
	// Define the size of the buffer string we will use to store
	// user inputs, and set the number of characters to zero.
	char buffer [BUFFER_SIZE];
	unsigned int num_characters = 0;

	// Get the first sizeof(buffer)-number of characters from
	// the input, and then iterate through them. If a null character
	// is reached, break the loop.
	while (fgets(buffer, sizeof(buffer), stdin) != NULL) {
		for (int i = 0; i < strlen(buffer); i++) {
			// If the newline is reached, then continue
			// to the next iteration of the for-loop.
			if (buffer[i] == '\n') {
				continue;
			}
			// If the newline wasn't reached, then add
			// any character to the count unless it's a
			// null-terminator character.
			if (buffer[i] != '\0') {
				num_characters++;
			}
		}
	}

	// Return the number of characters.
	return num_characters;
	
}


// Reads input from the first argument given to the function argv[1],
// and reads the number of characters in it.
unsigned int read_from_arg(char* str) {
	return strlen(str);
}

// Main function.
int main(int argc, char** argv) {
	unsigned int num_characters;
	// If there is only one argument (i.e. ./numchar), then
	// get input from stdin.
	if (argc == 1) {
		num_characters = read_from_stdin();
	}
	// If there is one arg, get input from the first argument 
	// (argv[1]).
	else if (argc == 2) {
		num_characters = read_from_arg(argv[1]);
	}
	// Otherwise, return an error.
	else {
		return 7; // Argument list is too long.
	}
	// Print the result.
	printf("%u\n", num_characters);
	
	return 0;

}

