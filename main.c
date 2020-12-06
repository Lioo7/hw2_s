#include <stdio.h>
#include "myBank.h"

int main()
{
    int static counter = 0;
    char choice;
    int mood = TRUE;

    while (mood == TRUE)
    {
        printf("\nPlease choose a transaction type:\n");
        printf("O-Open Account\n");
        printf("B-Balance Inquiry\n");
        printf("D-Deposit\n");
        printf("W-Withdrawal\n");
        printf("C-Close Account\n");
        printf("I-Interest\n");
        printf("P-Print\n");
        printf("E-Exit\n");

        if (scanf(" %c", &choice) == 1)
        {
            switch (choice)
            {
            case 'O':
            {
                double sum;
                if (counter < SIZE)
                {
                    printf("Please enter amount for deposit: ");
                    if (scanf("%lf", &sum) == 1)
                    {
                        if (sum > 0)
                        {
                            int ans = create(counter, sum);
                            printf("New account number is: %d\n", ans);
                            counter++;
                        }
                        else
                        {
                            printf("Invalid Amount");
                        }
                    }
                    else
                    {
                        printf("Failed to read the amount\n");
                    }
                }

                else
                {
                    printf("The Bank is Full.\n");
                }
                break;
            }

            case 'B':
            {
                int account_number;
                printf("Please enter account number: ");
                if (scanf("%d", &account_number) == 1)
                {
                    if (account_number < ACCOUNT || account_number > (ACCOUNT + SIZE - 1))
                    {
                        printf("Invalid account number");
                    }
                    else
                    {

                        if (isOpen(account_number) == TRUE)
                        {
                            double ans = balance(account_number);
                            printf("The balance of account number %d is: %.2lf\n", account_number, ans);
                        }
                        else
                        {
                            printf("This account is closed\n");
                        }
                    }
                }
                else
                {
                    printf("Failed to read the account number\n");
                }

                break;
            }

            case 'D':
            {
                int account_number;
                printf("Please enter account number: ");
                if (scanf("%d", &account_number) == 1)
                {
                    if (account_number < ACCOUNT || account_number > (ACCOUNT + SIZE - 1))
                    {
                        printf("Invalid account number");
                    }
                    else
                    {
                        if (isOpen(account_number) == TRUE)
                        {
                            double sum;
                            printf("Please enter amount for deposit: ");
                            if (scanf("%lf", &sum) == 1)
                            {
                                if (sum > 0)
                                {
                                    double ans = deposit(account_number, sum);
                                    printf("The new balance is: %.2lf\n", ans);
                                }
                                else
                                {
                                    printf("Cannot deposit a negative amount");
                                }
                            }
                            else
                            {
                                printf("Failed to read the amount\n");
                            }
                        }
                        else
                        {
                            printf("Your account is closed\n");
                        }
                    }
                }
                else
                {
                    printf("Failed to read the account number\n");
                }
                break;
            }

            case 'W':
            {
                int account_number;
                printf("Please enter account number: ");
                if (scanf("%d", &account_number) == 1)
                {
                    if (account_number < ACCOUNT || account_number > (ACCOUNT + SIZE - 1))
                    {
                        printf("Invalid account number");
                    }
                    else
                    {
                        if (isOpen(account_number) == TRUE)
                        {
                            double sum;
                            printf("Please enter the amount to withdraw: ");
                            scanf("%lf", &sum);

                            if (sum <= balance(account_number))
                            {
                                double ans = withdraw(account_number, sum);
                                printf("The new balance is: %.2lf\n", ans);
                            }
                            else
                            {
                                printf("Cannot withdraw more than the balance\n");
                            }
                        }
                        else
                        {
                            printf("Your account is closed.\n");
                        }
                    }
                }
                else
                {
                    printf("Failed to read the amount\n");
                }
                break;
            }

            case 'C':
            {
                int account_number;
                printf("Please enter your account number: ");
                if (scanf("%d", &account_number) == 1)
                {
                    if (account_number < ACCOUNT || account_number > (ACCOUNT + SIZE - 1))
                    {
                        printf("Invalid account number");
                    }
                    else
                    {
                        if (isOpen(account_number) == TRUE)
                        {
                            close(account_number);
                            printf("Closed account number %d\n", account_number);

                            counter--;
                        }
                        else
                        {
                            printf("This account is already closed\n");
                        }
                    }
                }
                else
                {
                    printf("Failed to read the account number\n");
                }
                break;
            }

            case 'I':
            {
                double sum;
                printf("Please enter interest rate: ");
                if (scanf("%lf", &sum) == 1)
                {
                    if (sum >= 0)
                    {
                        if (counter > 0)
                        {
                            interest(sum);
                        }
                    }
                    else
                    {
                        printf("Invalid interest rate\n");
                    }
                }

                else
                {
                    printf("Failed to read the interest rate\n");
                }
                break;
            }

            case 'P':
            {
                if (counter > 0)
                {
                    print();
                }
                
                break;
            }

            case 'E':
            {
                if (counter > 0)
                {
                    closeAll();
                    counter = 0;
                }
                mood = FALSE;

                break;
            }

                // The input doesn't match any case above /
            default:
            {
                printf("Invalid transaction type\n");
            }
            break;
            }
        }
    }
    return 0;
}
