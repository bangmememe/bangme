TARGET = string

all : ${TARGET}

string : main.o string.o 
	cc -o string main.o string.o

main.o : main.c 
	cc -c main.c

string.o : string.c 
	cc -c string.c
clean :
	rm ${TARGET}
