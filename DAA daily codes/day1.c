/* Write a C program that accepts a positive integer
  containing digits from 0 to 9. Exactly one digit is 
  missing, while the remaining nine digits appear exactly once.*/

#include <stdio.h>

int main()
{
    int n, rem;
    int frequency[10] = {0};

    printf("Enter the number: ");
    scanf("%d", &n);

    while(n > 0)
    {
        rem = n % 10;

        // Count the occurrence
        frequency[rem]++;

        n = n / 10;
    }

    for(int i = 0; i < 10; i++)
    {
        if(frequency[i] == 0)
        {
            printf("Missing digit = %d\n", i);
        }
        else if(frequency[i] > 1)
        {
            printf("Digit %d is repeated %d times\n",
                   i, frequency[i]);
        }
    }

    return 0;
}