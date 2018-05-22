all: main.c wordGen.c colorGen.c codenames.h
	gcc -c -g -std=c99 main.c wordGen.c colorGen.c
	gcc -o codenames main.o wordGen.o colorGen.o
	@echo "\nAll made!"

clean:
	rm codenames *.o
