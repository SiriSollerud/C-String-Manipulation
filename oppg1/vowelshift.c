# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <ctype.h>

// Replaces all vowels in a sentence with a given letter
int main(int argc, char *argv[]) {
	  // fixed order of arguments (sentence first, then letter)
	  char letter = *argv[2];
	  char sentence[strlen(argv[1]) + 1];
		strcpy(sentence, argv[1]);

    // deleted the \0 from the array
		char vowels[] = {'a', 'e', 'i', 'o', 'u'};

		for (int i = 0; i < strlen(sentence); i++) {
			  for (int j = 0; j < strlen(vowels); j++) {
					   if (tolower(sentence[i]) == vowels[j]){
						    	sentence[i] = letter;
						 }
				}
		}
	  printf("%s\n", sentence);
}
