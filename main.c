#include <stdio.h> 
#include <stdlib.h> 
#include <time.h>

#include "PictureManipulation.h"
#include "NumbersPuzzle.h"

void printMenuOptions() {
	printf("Please choose one of the following options \n");
	printf("P/p - Picture Manipulation \n");
	printf("N/n - Number Game \n");
	printf("E/e - Quit \n");
}

void main() {
	int mat[R][C];
	printMenuOptions();
	char ch = ' ';
	scanf("%c", &ch);
	while ( ch != 'e'&&ch != 'E') {
		switch (ch) {
			case 'P':
			case 'p':
				PictureManipulation();
				break;

			case 'n':
			case 'N':
				NumbersPuzzle();
				break;

		}
		scanf("%c", &ch);
	}
	printf("Bye Bye");
}

void pictureManipulationPrintMenu() {
    	printf("Please choose one of the following options \n");
	printf("0 - Return \n");	
	printf("1 - 90 degree clockwise \n");
	printf("2 - 90 degree counter clockwise \n");
	printf("3 - Flip Horizontal \n");
	printf("4 - Flip Vertical \n");
}


void numbersPuzzleMainMenu() {
   	printf("Please choose one of the following options \n");
	printf("0 - Return \n");
	printf("1 -  \n");
	printf("2 -  \n");
	printf("3 -  \n");
	printf("4 -  \n");
}

// swaps values pointed by xp and yp 
void swap(int *xp, int *yp) { 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 

// print matrix *((arr+i*C) + j)
void printMatrix(int *arr) {
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            printf("%d ", *((arr+i*C) + j));
        }
     printf("    \n");
    }
}
