#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "main.h"

#define SHUFFEL_COUNT 10

void initMatrix(int mat[R][C]) {
    int counter = 1;
    int i, j;
    for (i = 0; i < R; i++) {
        for (j = 0; j < C; j++) {
            mat[i][j] = counter++;
        }
    }
    mat[R - 1][C - 1] = 0;
}

// 0 up 
//1 right
//2 down
//3 left
int randDirection() {
    	int i, n;
    	srand(time(0));
	for (i = 0; i < SHUFFEL_COUNT; i++) {
    		n = rand() % 4;
	}
    	return n;
}

int checkValidMove(int move, int row, int col) {
    switch (move) {
        // 0 up 
    case 0:
        if (row - 1 < 0)
            return 0;
        break;
        //1 right
    case 1:
        if (col + 1 >= C)
            return 0;
        break;
        //2 down
    case 2:
        if (row + 1 >= R)
            return 0;
        break;
        //3 left
    case 3:
        if (col - 1 < 0)
            return 0;
        break;
    }
    return 1;
}

void shuffleMat(int mat[R][C]) {
    	int i = R - 1, j = C - 1;
    	int d = randDirection();
    	int validMove = checkValidMove(d, i, j);
	if (validMove) {
		switch (d) {
        		case 0: // UP
            			swap(&mat[i][j], &mat[i - 1][j]);
            			i -= 1;
				printf("0");
            			break;            
       			case 1: // RIGHT
            			swap(&mat[i][j], &mat[i][j + 1]);
            			j += 1;
				printf("1");
            			break;          
        		case 2: // DOWN
            			swap(&mat[i][j], &mat[i + 1][j]);
            			i += 1;
				printf("2");
            			break;       
        		case 3: // LEFT
           			swap(&mat[i][j], &mat[i][j - 1]);
            			j -= 1;
				printf("3");
            			break;
        	}
	}
}

void checkWin() {
// check if board is arranged by ascending order if yes player wins
// else ask player what is next move
// check if player move is valid
// make move
// print array
}

int NumbersPuzzle() {
	int mat[R][C];
    	initMatrix(mat);
	printMatrix(mat);
	for (int i = 0; i < SHUFFEL_COUNT; i++) {
    		shuffleMat(mat);    
        printf("\n");
        printMatrix(mat);
} 
    	return 0;
}
















