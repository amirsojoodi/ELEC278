# Tutorial 7 - Makefile
# Code provided for ELEC-278 Tutorial at Queen's University
# @author AmirHossein Sojoodi
# @date 2022-10

# [target] : [dependency list]
#	[command]

all: bin/main.o bin/is_happy.o bin/binary_search.o

bin/main.o : src/main.c
	gcc src/main.c -o bin/main.o

bin/is_happy.o : src/is_happy.c
	gcc src/is_happy.c -o bin/is_happy.o

bin/binary_search.o : src/binary_search.c
	gcc src/binary_search.c -o bin/binary_search.o

run: bin/main.o 
	./bin/main.o

happy: bin/is_happy.o
	./bin/is_happy.o

binary: bin/binary_search.o
	./bin/binary_search.o
	
debug: src/main.c
	gcc src/main.c -o bin/main.o -D DEBUG

clean:
	rm -f bin/*