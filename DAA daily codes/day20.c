#include <stdio.h>
#include <string.h>

int main() {
    char str[1000];
    int lastIndex[256];

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    str[strcspn(str, "\n")] = '\0';

    for (int i = 0; i < 256; i++) {
        lastIndex[i] = -1;
    }

    int start = 0;
    int maxStart = 0;
    int maxLength = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        unsigned char ch = str[i];

        if (lastIndex[ch] >= start) {
            start = lastIndex[ch] + 1;
        }

        lastIndex[ch] = i;

        int currentLength = i - start + 1;

        if (currentLength > maxLength) {
            maxLength = currentLength;
            maxStart = start;
        }
    }

    printf("Longest substring without repeating characters: ");

    for (int i = maxStart; i < maxStart + maxLength; i++) {
        printf("%c", str[i]);
    }

    printf("\nLength: %d\n", maxLength);

    return 0;
}