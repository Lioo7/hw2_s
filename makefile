CC = gcc
AR = ar 
OBJECTS_MAIN = main.o 
OBJECTS_BANK = myBank.o 
FLAGS = -Wall -g 

all: myBanks mains

mains: $(OBJECTS_MAIN) libmyBank.a 
	$(CC) $(FLAGS) -o mains $(OBJECTS_MAIN) libmyBank.a 
myBanks: libmyBank.a
libmyBank.a: $(OBJECTS_BANK) 
	$(AR) -rcs libmyBank.a $(OBJECTS_BANK)
myBank.o: myBank.c myBank.h
	$(CC) $(FLAGS) -c myBank.c
main.o: main.c myBank.h
	$(CC) $(FLAGS) -c main.c

.PHONY: clean all

clean:
	rm -f *.o *.a *.so mains maind


