#ifndef _MYBANK_H_
#define _MYBANK_H_

// constants definition exported by library:
#define FALSE 0
#define TRUE 1
// The maximum of the accounts in the bank 
#define SIZE 50
// The number of the first account 
#define ACCOUNT 901
// The number of options for each account 
#define OPTIONS 2
// The options for each account 
#define CLOSED 0
#define OPEN 1

// myBank functions:
int find();
int isOpen(int account_number);
int create(int counter, double sum);
double balance(int account_number);
double deposit(int account_number, double sum);
double withdraw(int account_number, double sum);
int close(int account_number);
int interest(double sum);
int print();
int closeAll();

#endif
