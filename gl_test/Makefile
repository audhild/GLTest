all: gl_test

gl_test: GLTest.o SearchFile.o
	g++ -o gl_test GLTest.o SearchFile.o

GLTest.o: GLTest.cpp
	g++ -c GLTest.cpp

SearchFile.o: SearchFile.cpp SearchFile.h
	g++ -c SearchFile.cpp

clean:
	rm -rf *.o gl_test