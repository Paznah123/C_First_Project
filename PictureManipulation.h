#ifndef PictureManipulation_H_
#define PictureManipulation_H_ 	

#define R 3
#define C 3

void PictureManipulation();
void reverseColumns(int arr[R][C]);
void reverseRows(int arr[R][C]);
void transpose(int arr[R][C]);
void rotate90Clockwise(int arr[R][C]); 
void rotate90CounterClockwise(int arr[R][C]); 
void flipHorizontal(int arr[R][C]); 
void flipVertical(int arr[R][C]);

#endif


