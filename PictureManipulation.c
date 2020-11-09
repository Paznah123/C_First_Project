#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 

#include "main.h"

// After transpose we swap 
// elements of column 
// one by one for finding left 
// rotation of matrix 
// by 90 degree 
void reverseColumns(int arr[R][C]) { 
    for (int i = 0; i < C; i++) 
        for (int j = 0, k = C - 1; j < k; j++, k--) 
            swap(&arr[j][i], &arr[k][i]);  
                
} 

void reverseRows(int arr[R][C]) {
    int  k;
    for (int i = 0; i < R; i++){
       k = R-1;
       for (int j = 0; j < k; j++) {
 	  swap(&arr[i][j],&arr[i][k]);
 	  k--;
       }
    }
}

// matrix transpose  
void transpose(int arr[R][C]) { 
    for (int i = 0; i < R; i++) 
        for (int j = i; j < C; j++) 
       	    if(i!=j)
       	      swap(&arr[i][j], &arr[j][i]); 
} 

// rotate matrix by 90 degree counter/clockwise
void rotate90Clockwise(int arr[R][C]) {    
    transpose(arr); 
    reverseRows(arr);
} 

void rotate90CounterClockwise(int arr[R][C]) {     
    transpose(arr); 
    reverseColumns(arr); 
} 
  
void flipHorizontal(int arr[R][C]){
 reverseColumns(arr);
}

void flipVertical(int arr[R][C]){
    reverseRows(arr);
}

void PictureManipulation() {
	int mat[R][C];
	int i,j;
       	srand(time(0));
    	for(i = 0; i < R; i++) {
   		for(j = 0; j < C ; j++) {
     			mat[i][j]=rand() % 50;
      			printf("%d\t",mat[i][j]);
  		}
   	 	printf("\n");
    	}
    	pictureManipulationPrintMenu();
    	int ch;
    	scanf("%d", &ch);
    	while ( ch != -1) {
		switch (ch) {
			case 0:
				main();
				break;
			case 1:
				rotate90Clockwise(mat);
				printMatrix(mat);
				break;
			case 2:
		    		rotate90CounterClockwise(mat);
		    		printMatrix(mat);
				break;
			case 3:
				flipHorizontal(mat);
				printMatrix(mat);
				break;
			case 4:
				flipVertical(mat);
				printMatrix(mat);
				break;
		}
    		pictureManipulationPrintMenu();
		scanf("%d", &ch);
    	}
	printf("Bye Bye");	
}
  
