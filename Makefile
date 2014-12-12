cc = gcc
CFLAGS = -Wall -Werror -O2 -std=c99 -lm
LCFLAGS = $(CFLAGS)
OCFLAGS = $(CFLAGS) -c
MAINBIN = a.out

DEPFILE = broyden.deps

#objects
OBJECTF += broyden_functions.o 
OBJECTF += broyden_input.o 
OBJECTF += broyden_output.o
OBJECTF += broyden_main.o 
OBJECTF += matrix_operations.o 
OBJECTF += solve_equation.o
OBJECTF += broyden_method.o
OBJECTF += broyden_file.o

all: deps main

deps: *.h *.c
	$(cc) -MM *.c > $(DEPFILE)

main: ${OBJECTF}
	$(cc) $(CFLAGS) -o $(MAINBIN) *.o

%.o: %.c %.h
	$(cc) $(OCFLAGS) -o $*.o $*.c


include $(DEPFILE)
