/*Write a program using a while loop that repeatedly asks 
the user to enter the password and stops only when the correct 
password is entered. Finally, display "Login successful!".*/

#include <stdio.h>

int main()
{
    int password;
    int correctPassword = 12345;

    printf("Enter password: ");
    scanf("%d", &password);

    while (password != correctPassword)
    {
        printf("Incorrect password. Try again.\n");
        printf("Enter password: ");
        scanf("%d", &password);
    }

    printf("Login successful!\n");

    return 0;
}
