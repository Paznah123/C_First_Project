#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "main.h"

#define SHUFFEL_COUNT 20

// initialize matrix
void initMatrix (int *matPtr) {
    int counter = 1;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
	        *matPtr = counter++;
	        matPtr++;
	    }
    }
    *(matPtr - 1) = 0;
}

// choose random direction
int randDirection () {
    int i, n;
    for (i = 0; i < SHUFFEL_COUNT; i++) {
      n = 1 + rand () % 4;
    }
    return n;
}

// updates matrix pointers and swaps values
int updatePtr(int **matPtr, int ptrAdd, int *edgeIndicator, int edgeAdd){
    swap(*matPtr, *matPtr + ptrAdd);
    *matPtr += ptrAdd;
    *edgeIndicator += edgeAdd;
    return 1;
}

// moves 0 in chosen direction 
int makeMove (int **matPtr, int *d, int *row, int *col) {
        switch (*d) { // if's check if move is valid
            case 1:	// UP
               if(*row - 1 >= 0)
                    return updatePtr(matPtr,-SIZE, row, -1);
                break;
            case 2:	// RIGHT
                if(*col + 1 < SIZE)
                    return updatePtr(matPtr, 1, col, 1);
                break;
            case 3:	// DOWN
                if(*row + 1 < SIZE)
                    return updatePtr(matPtr, SIZE, row, 1);
                break;
            case 4:	// LEFT
                if(*col - 1 >= 0)
                    return updatePtr(matPtr, -1, col, -1);
                break;
        }
        printf("Invalid Move! \n");
        return 0;
}

void shuffleMat(int **matPtr, int *num, int *row, int *col) {
    int i = 0;
    while(i != SHUFFEL_COUNT) {
        *num = randDirection();
        if(makeMove(matPtr ,num, row, col))
            i++; // i increase whe nvalid move is made
    }
}

// checks if board is arranged by ascending order
int checkWinnerBoard(int *matPtr) {
    int counter = 1;
    for (int i = 0; i < SIZE*SIZE-1; i++) {
        if(*matPtr != counter)
            return 0;
        else {
            counter++;
            matPtr++;
        }
    }
    printf("You win! The game is over! \n");
    return 1;
}

// main func
int NumbersPuzzle () {
    int mat[SIZE][SIZE];
    int *matPtr = &mat[0][0];
    initMatrix (matPtr);
    
    // pointer to 0 location
    int *lastElementPtr = matPtr + SIZE*SIZE-1;
    
    // edge of board indicators
    int row = SIZE-1;
    int col = SIZE-1;

    time_t t;
    srand ((unsigned) time (&t));
    int num = 0;
    
    shuffleMat(&lastElementPtr, &num, &row, &col);
    
    printMatrix(matPtr);
    numbersPuzzleMenu();
    
    int choice = 5;
    scanf ("%d", &choice);
    while (choice != 0) {
            switch (choice) {
        	    case 1:	// UP
        	    case 2:	// RIGHT
        	    case 3:	// DOWN
        	    case 4:	// LEFT
            	    makeMove (&lastElementPtr, &choice, &row, &col);
            	    break;
        	   default:
        	        printf("Invalid Move! \n");
        	        break;
            }
            printMatrix(matPtr);
            printf("\n");
            if(!checkWinnerBoard(matPtr)){
                numbersPuzzleMenu();   
                getchar();
                scanf ("%d", &choice);
            } else 
                break;
    }
    return 0;
}
