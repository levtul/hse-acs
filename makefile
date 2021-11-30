# makefile for sorting.asm
task: main.c input.c inrnd.c output.c sorting.o
	gcc -g -o task main.c sorting.o -no-pie
sorting.o: sorting.asm
	nasm -f elf64 -g -F dwarf sorting.asm -l sorting.lst
