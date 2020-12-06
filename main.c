#include <stdio.h> 
#include <stdlib.h> 
#include <time.h>

#include "PictureManipulation.h"
#include "NumbersPuzzle.h"

#define SIZE 4

void printMenuOptions() {
    printf("\n");
	printf("Please choose one of the following options \n");
	printf("P/p - Picture Manipulation \n");
	printf("N/n - Number Game \n");
	printf("E/e - Quit \n");
	printf("\n");
}

void main() {
    printMenuOptions();
	char ch = ' ';
	scanf(" %c", &ch);
	while ( ch != 'E' && ch != 'e') {
		switch (ch) {
			case 'P':
			case 'p':
				PictureManipulation();
			    printMenuOptions();
				break;
			case 'n':
			case 'N':
				NumbersPuzzle();
			    printMenuOptions();
				break;
			default:
			    printf("Invalid Input! \n");
			    break;
		}
		getchar();
		scanf("%c", &ch);
	}
	printf("Bye Bye");
}

void pictureManipulationPrintMenu() {
    printf("\n");	
    printf("Please choose one of the following options \n");
	printf("0 - Return \n");	
	printf("1 - 90 degree clockwise \n");
	printf("2 - 90 degree counter clockwise \n");
	printf("3 - Flip Horizontal \n");
	printf("4 - Flip Vertical \n");
	printf("\n");	
}


void numbersPuzzleMenu() {
    printf("\n");
   	printf("Please choose one of the following options \n");
	printf("0 - Return \n");
	printf("1 - Move UP \n");
	printf("2 - Move RIGHT \n");
	printf("3 - Move DOWN \n");
	printf("4 - Move LEFT \n");
	printf("\n");
}

// swaps values pointed by xp and yp 
void swap(int *xp, int *yp) { 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
}

void printMatrix(const int *matPtr) {
    printf("    \n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d\t", *matPtr);
            ++matPtr;
        }
        printf("    \n");
    }
}
