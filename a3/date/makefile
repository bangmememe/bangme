TARGET = date

all : ${TARGET}

date : main.o date.o 
	cc -o date main.o date.o

main.o : main.c 
	cc -c main.c

date.o : date.c 
	cc -c date.c
clean :
	rm ${TARGET}
