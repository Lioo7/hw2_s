#include <stdio.h>
#include "myBank.h"

/*
     * Creates a 2D array which contains all the bank accounts 
     * The first dimension consists the balance
     * The second dimension consists a number 0/1,
     * when 0 means that the account is closed
     * and 1 means tat the account is open
     */
double bankAccounts[SIZE][OPTIONS];

// This function find an empty index in the array and return it
int find()
{
    for (int i = 0; i < SIZE; i++)
    {
        if (bankAccounts[i][1] == CLOSED)
        {
            return i;
        }
    }
    return 0;
}

int isOpen(int account_number)
{
    int ans = FALSE;
    if (bankAccounts[account_number - ACCOUNT][1] == OPEN)
    {
        ans = TRUE;
    }
    return ans;
}

int create(int counter, double sum)
{
    int ans;
    int index = find(bankAccounts);
    bankAccounts[index][0] = sum;
    bankAccounts[index][1] = OPEN;
    counter++;
    ans = index + ACCOUNT;

    return ans;
}

double balance(int account_number)
{
    double ans;
    ans = bankAccounts[account_number - ACCOUNT][0];

    return ans;
}

double deposit(int account_number, double sum)
{
    double ans;
    bankAccounts[account_number - ACCOUNT][0] += sum;
    ans = bankAccounts[account_number - ACCOUNT][0];

    return ans;
}

double withdraw(int account_number, double sum)
{
    double ans;
    bankAccounts[account_number - ACCOUNT][0] -= sum;
    ans = bankAccounts[account_number - ACCOUNT][0];

    return ans;
}

int close(int account_number)
{
    bankAccounts[account_number - ACCOUNT][1] = CLOSED;

    return 0;
}

int interest(double sum)
{
    double x = (sum / 100) + 1;
    for (int i = 0; i < SIZE; i++)
    {
        if (bankAccounts[i][1] == OPEN)
        {
            bankAccounts[i][0] *= x;
        }
    }

    return 0;
}

int print()
{
    for (int i = 0; i < SIZE; i++)
    {
        if (bankAccounts[i][1] == OPEN)
        {
            int index = i + ACCOUNT;
            double ans = balance(index);
            printf("The balance of account number %d is: %.2lf\n", index, ans);
        }
    }

    return 0;
}

int closeAll()
{
    for (int i = 0; i < SIZE; i++)
    {
        if (bankAccounts[i][1] == OPEN)
        {
            bankAccounts[i][1] = CLOSED;
        }
    }

    return 0;
}
