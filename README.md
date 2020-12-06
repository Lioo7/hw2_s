# hw2_s
## Assignment #2 in C

#### This project made during the SW systems course at Ariel University in the Department of Computer Science, 2020. 

#### Project site: https://github.com/Lioo7/hw2_s.git

##### The assignment is about creating a bank, which can manage up to 50 accounts.
##### The user can use these transactions:

* O - Open a new account and gets the initial amount of deposit and print the account number, if the bank is not full.
* B - Gets the account number and prints the balance, if the account is open. 
* D - Gets the account number and the amount of deposit and prints the new balance, if the account is open.
* W - Gets the account number and the amount of withdrawal and prints the new balance, if the account is open and has enough money.
* C - Gets the account number and closes it, if the account is open.
* I - Gets the percentage of interest and adds it to all the open accounts.
* P - Printing all the open accounts and their balance.
* E - closing all the accounts and exits from the program.


##### The program contains a Makefile file with the following commands:

all: Compile the program.
mains: Creates a static main file.
myBanks: Creates a static library.
clean: Deletes all files with the following extensions .o .a .so .out and execute files.


@author Lioz Akirav.
