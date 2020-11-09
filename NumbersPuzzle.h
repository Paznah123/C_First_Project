#ifndef NumbersPuzzle_H_
#define NumbersPuzzle_H_ 	

#define R 3
#define C 3

int NumbersPuzzle();
void initMatrix(int mat[R][C]);
int randDirection();
int checkValidMove(int move, int row, int col);

#endif

