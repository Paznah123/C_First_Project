#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 

#include "main.h"

void fillMatNums(int *matPtr) {
    srand(time(0));
	for(int i = 0; i < SIZE; i++) {
   	    for(int j = 0; j < SIZE; j++) {
 			*matPtr =rand() % 50;
  			printf("%d\t",*matPtr);
  			matPtr++;
      	}
    	printf("\n");
	}    
}

void reverseRows(int *matPtr) { 
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0, k = SIZE - 1; j < k; j++, k--) {
            swap(matPtr+SIZE*i+j,matPtr + SIZE*i+k);
        }
    }
} 

void reverseColumns(int *matPtr) {
    int  k;
    for (int i = 0; i < SIZE; i++){
       k = SIZE-1;
       for (int j = 0; j < k; j++) {
     	  swap(matPtr+SIZE*j+i,matPtr+SIZE*k+i);
     	  k--;
       }
    }
}

// matrix transpose  
void transpose(int *matPtr) { 
    for (int i = 0; i < SIZE; i++) {
        for (int j = i; j < SIZE; j++) {
       	    if(i!=j)
       	      swap(matPtr + SIZE*i+j, matPtr + SIZE*j+i); 
        }
    }
} 

void rotate90(int *matPtr, int ch) {    
    transpose(matPtr); 
    if(ch == 1) // clockwise
        reverseRows(matPtr);
    if(ch == 2) // counterclockwise
        reverseColumns(matPtr); 
} 

// main func
void PictureManipulation() {
    int mat[SIZE][SIZE];
    int *matPtr = &mat[0][0];
    fillMatNums(matPtr);

	pictureManipulationPrintMenu();
	int ch;
	scanf("%d", &ch);
	while ( ch != 0) {
    	switch (ch) {
    		case 1://clockwise
    		case 2://counterclockwise
    			rotate90(matPtr, ch);
    			printMatrix(matPtr);
    			break;
    		case 3: // flipHorizontal
    			reverseColumns(matPtr);
    			printMatrix(matPtr);
    			break;
    		case 4: // flipVertical
    			reverseRows(matPtr);
    			printMatrix(matPtr);
    			break;
    		default:
			    printf("Invalid Input! \n");
    		    break;
    	}
		pictureManipulationPrintMenu();
		getchar();
	    scanf("%d", &ch);
	}
}
  
