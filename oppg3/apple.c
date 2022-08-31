# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <stdbool.h>
# include "the_apple.h"

// I made this variable global because I kept getting the warning:
// "function returns address of local variable"
int indexes[4];

// returns the indexes of the letters in worm
int *wormindexes(char* apple) {
    int w_index = -1; // first w in worm
    int o_index = -1; // first o in worm
    int r_index = -1; // first r in worm
    int m_index = -1; // last m in worm
    bool worm = false; // check for worm spelling

    /*
    I know the following code is repetetive and I could probably have made
    a function, but then again... it ain't pretty, but it works!
    */
    // checking if 'worm' is spelled correctly, no matter how long the worm is
    for (int i = 0; i < strlen(apple); i++) {
        if (apple[i] == 'w') {
            // first w
            if (worm == false && w_index == -1 && o_index == -1 &&
                                    r_index == -1 && m_index == -1) {
                w_index = i;
                worm = true;
            } else {
                continue;
            }
        }

        // first o
        if (worm == true && w_index != -1 && o_index == -1 &&
                            r_index == -1 && m_index == -1 &&
                                                apple[i] == 'o') {
            o_index = i;
        } else {
            worm == false;
        }

        // first r
        if (worm == true && w_index != -1 && o_index != -1 &&
                            r_index == -1 && m_index == -1 &&
                                                apple[i] == 'r') {
            r_index = i;
        } else {
            worm == false;
        }

        // first m
        if (worm == true && w_index != -1 && o_index != -1 &&
                            r_index != -1 && m_index == -1 &&
                                                apple[i] == 'm') {
            m_index = i;
        } else {
            worm == false;
        }

        // last m
        if (worm == true && w_index != -1 && o_index != -1 &&
                            r_index != -1 && m_index != -1 &&
                                                apple[i] == 'm') {
            m_index = i;
        } else {
            worm == false;
        }
    }

    // checking if worm is spelled correctly --> returns indexes
    if (worm && w_index != -1 && o_index != -1 && r_index != -1 && m_index != -1) {
        indexes[0] = w_index;
        indexes[1] = o_index;
        indexes[2] = r_index;
        indexes[3] = m_index;
        return indexes;
    } else {
        indexes[0] = -1;
        return indexes;
    }
}

int locateworm(char* apple) {
    int *worm_index = wormindexes(apple);
    if (worm_index[0] != -1) {
        return worm_index[0];
    } else {
        return -1;
    }
}

int removeworm(char* apple) {
    int *worm_index = wormindexes(apple);

    // newlines and spaces are not counted in the worm length
    // only worm letters are counted
    int worm_length = 0;

    // if the worm doesn't exist: return 0
    if (worm_index[0] == -1) {
        return 0;
    } else {
        // if there is a worm --> removie it, print apple, and return worm length
        int size = (worm_index[3] - worm_index[0]) + 1;
        for (int i = worm_index[0]; i <= worm_index[3]; i++) {
            // keeping newlines in so the print is pretty
            if (apple[i] != '\n' && apple[i] != ' ') {
                apple[i] = ' ';
                worm_length++;
            }
        }
        // making the apple red because it's fun :D
        printf("\x1b[31m%s", apple);
    }
    return worm_length;
}

// using the functions to test the apple
int test(char* apple) {
     int worm_index = locateworm(apple);
     if (worm_index == -1) {
         printf("\n\x1B[37mThis apple contains no worm!");
     } else {
         printf("\n\x1B[37mWorm is located at index: \x1b[32m%d\n\n", worm_index);
     }
     int worm = removeworm(apple);
     printf("\n\x1B[37mWorm has length: \x1b[32m%d\n", worm);
}

// running the tests on an apple with a worm and an apple without a worm
int main() {
    printf("----TESTING FIRST APPLE-----");
    char *apple_copy = strdup(apple);
    test(apple_copy);

    // cheks if the worm has been removed by running test() again on the same apple
    printf("\n\x1B[37m----TESTING IF WORM WAS REMOVED FROM FIRST APPLE-----");
    test(apple_copy);

    // tests another apple that doesn't have any worm in it.
    printf("\n\x1B[37m----TESTING SECOND APPLE-----");
    test(apple2);
}
