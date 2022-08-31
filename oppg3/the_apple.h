# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# ifndef THE_APPLE_H
# define THE_APPLE_H

extern char* apple;
extern char* apple2;
extern int indexes[4];

int *wormindexes(char* apple);
int locateworm(char* apple);
int removeworm(char* apple);

# endif
