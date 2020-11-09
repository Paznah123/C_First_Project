gbuild:
	gcc main.c PictureManipulation.c NumbersPuzzle.c -o main.o 
	gcc main.h PictureManipulation.h NumbersPuzzle.h -o main

clean:
	rm -f *.o ./exe1

run:

	./main.o
	./main




