#ifndef NumbersPuzzle_H_
#define NumbersPuzzle_H_ 	

void initMatrix(int *mat);
int randDirection();
int updatePtr(int **matPtr, int ptrAdd, int *edgeIndicator, int edgeAdd);
void makeMove (int **matPtr, int *d, int *row, int *col);
void shuffleMat(int **matPtr,int num, int *row, int *col);
int checkWinnerBoard(int *matPtr);
int NumbersPuzzle();

#endif

