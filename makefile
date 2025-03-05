all : infinit limit

infinit : infinit.c
  cc -o infinit infinit.cc

limit : $0

celsius2fair : $o

clean :
	rm a.out celsius2fair fair2celsius infinit limit
