
ifeq ($(OS),Windows_NT)
    CCFLAGS = -f win64
    OUTPUT = exec.exe
else
    CCFLAGS = -f elf64
    OUTPUT = exec.exe
endif


all: 
#	nasm main.asm -f $(CCFLAGS) -o bin/main.o
#	g++ PrimeCalculator.cpp bin/main.o -o $(OUTPUT)
	g++ PrimeCalculator.cpp -mavx -o $(OUTPUT)
	./$(OUTPUT)



