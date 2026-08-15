#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char str[200];
    char clean[200];
    int i, j = 0, len;
    int palindrome = 1;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    // Remove spaces and convert to lowercase
    for(i = 0; str[i] != '\0'; i++)
    {
        if(str[i] != ' ' && str[i] != '\n')
        {
            clean[j++] = tolower(str[i]);
        }
    }

    clean[j] = '\0';

    len = strlen(clean);

    for(i = 0; i < len / 2; i++)
    {
        if(clean[i] != clean[len - i - 1])
        {
            palindrome = 0;
            break;
        }
    }

    if(palindrome)
        printf("The string is a palindrome.");
    else
        printf("The string is not a palindrome.");

    return 0;
}