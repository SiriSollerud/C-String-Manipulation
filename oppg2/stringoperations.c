# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include "stringoperations.h"
# include <ctype.h>

// returns the sum of the alpha_value of a string
int stringsum(char *s){
    char str[strlen(s)]; // removed +1 because s is null terminated in test.c
  	strcpy(str, s);

    // an alpha_value is the value of an alphabet character
    // a has alpha_value 1, b has alpha_value 2, c has alpha_value 3, etc.
    int alpha_value = 0;
    int alpha_sum = 0;
    int i = 0;

    // iterates through the string to find the sum of only the alpha_values
    while(str[i]) {
        if (isalpha(str[i]) || isspace(str[i])) {
            if (isalpha(str[i])) {
                str[i] = tolower(str[i]);
                // using the ascii value to find the alpha_value of str[i]
                alpha_value = ((int) (str[i])) - 96;
                alpha_sum += alpha_value;
            }
        } else {
            return -1;
        }
        i++;
    }
    return alpha_sum;
}

// returns the distance between the first and last occurance of a letter in a string
int distance_between(char *s, char c){
    // letter_amt is the amount the character letter occurs in str
    int letter_amt = 0;
    for (int i = 0; i < strlen(s); i++) {
        //s[i] = tolower(s[i]);
        if (s[i] == c){
            letter_amt++;
        }
    }

    // if the letter occurs only 1 or 0 times in str, function returns 0 or -1
    if (letter_amt == 1)
        return 0;

    if (letter_amt == 0)
        return -1;

    // using strchr to find the index to the first occurence of letter
    char *find_first = strchr(s, c);
    int first_letter = find_first - s;

    // using strrchr to find the index to the last occurence of letter
    char *find_last = strrchr(s, c);
    int last_letter = find_last - s;

    int distance = last_letter - first_letter;
    return distance;
}


// returns the string between the first and last occurance of a letter in str
char *string_between(char *s, char c) {
    // if the letter occurs only 1 or 0 times in str, function returns NULL or ""
    int letter_amt = distance_between(s, c);
    if (letter_amt == -1)
        return NULL;
    if (letter_amt == 0)
        return strdup("");

    // finding the first and last occurances of letter so I can make the between string
    char *find_first = strchr(s, c);
    int first_letter = find_first - s;
    char *find_last = strrchr(s, c);
    int last_letter = find_last - s;

    // makes the between string that will be returned
    char *between = malloc(letter_amt);

    int counter = 0;
    for (int i = first_letter + 1; i < last_letter; i++) {
        between[counter] = s[i];
        if (i == last_letter - 1) {
            between[counter + 1] = '\0';
        }
        counter++;
    }
    return between;
}

int stringsum2(char* s, int* res) {
    int sum = stringsum(s);
    *res = sum;

    return *res;
}
