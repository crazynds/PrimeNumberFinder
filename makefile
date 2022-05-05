

all: 
	nasm main.asm -f win64 -o bin/main.o
	g++ PrimeCalculator.cpp bin/main.o -o exec.exe
	exec.exe



