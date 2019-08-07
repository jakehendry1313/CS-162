
output: mainDeterm.o determinant.o readMatrix.o
	g++ mainDeterm.o determinant.o readMatrix.o -o output

mainDeterm.o: mainDeterm.cpp
	g++ -c mainDeterm.cpp

determinant.o: determinant.cpp determinant.hpp
	g++ -c determinant.cpp determinant.hpp

readMatrix.o: readMatrix.cpp
	g++ -c readMatrix.cpp readMatrix.hpp

clean:
	rm *.o output
