#include <stdio.h>

int main()
{
    float balance = 0;
    float amount;
    int choice;
    char transactions[5][100];
    int count = 0;
    int i;

    while(1)
    {
        printf("\n\n===== ATM MENU =====");
        printf("\n1. Check Balance");
        printf("\n2. Deposit Money");
        printf("\n3. Withdraw Money");
        printf("\n4. Display Last Five Transactions");
        printf("\n5. Exit");

        printf("\nEnter choice: ");
        scanf("%d", &choice);

        if(choice == 1)
        {
            printf("\nCurrent Balance = %.2f", balance);
        }

        else if(choice == 2)
        {
            printf("Enter amount to deposit: ");
            scanf("%f", &amount);

            if(amount > 0)
            {
                balance += amount;

                if(count < 5)
                {
                    sprintf(transactions[count],
                            "Deposited: %.2f", amount);
                    count++;
                }
                else
                {
                    for(i = 0; i < 4; i++)
                        sprintf(transactions[i], "%s", transactions[i + 1]);

                    sprintf(transactions[4],
                            "Deposited: %.2f", amount);
                }

                printf("Amount deposited successfully.");
            }
            else
            {
                printf("Invalid amount.");
            }
        }

        else if(choice == 3)
        {
            printf("Enter amount to withdraw: ");
            scanf("%f", &amount);

            if(amount <= 0)
            {
                printf("Invalid amount.");
            }
            else if(amount > balance)
            {
                printf("Insufficient balance.");
            }
            else
            {
                balance -= amount;

                if(count < 5)
                {
                    sprintf(transactions[count],
                            "Withdrawn: %.2f", amount);
                    count++;
                }
                else
                {
                    for(i = 0; i < 4; i++)
                        sprintf(transactions[i], "%s", transactions[i + 1]);

                    sprintf(transactions[4],
                            "Withdrawn: %.2f", amount);
                }

                printf("Please collect your money.");
            }
        }

        else if(choice == 4)
        {
            printf("\nLast Five Transactions:\n");

            if(count == 0)
            {
                printf("No transactions available.");
            }
            else
            {
                for(i = 0; i < count; i++)
                    printf("%d. %s\n", i + 1, transactions[i]);
            }
        }

        else if(choice == 5)
        {
            printf("Thank you for using the ATM.");
            break;
        }

        else
        {
            printf("Invalid choice.");
        }
    }

    return 0;
}