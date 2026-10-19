#include <stdio.h>

int main() {
    unsigned int n, temp;
    int ones = 0, zeros = 0;
    int currentOnes = 0, maxConsecutiveOnes = 0;

    printf("Enter a number: ");
    scanf("%u", &n);

    temp = n;

    if (temp == 0) {
        zeros = 1;
    } else {
        while (temp > 0) {
            if (temp % 2 == 1) {
                ones++;
                currentOnes++;

                if (currentOnes > maxConsecutiveOnes) {
                    maxConsecutiveOnes = currentOnes;
                }
            } else {
                zeros++;
                currentOnes = 0;
            }

            temp = temp / 2;
        }
    }

    printf("Number of 1s: %d\n", ones);
    printf("Number of 0s: %d\n", zeros);
    printf("Maximum consecutive 1s: %d\n", maxConsecutiveOnes);

    return 0;
}