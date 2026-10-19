#include <stdio.h>
#include <string.h>

int longestUniqueSubstring(char s[]) {
    int lastIndex[256];

    for (int i = 0; i < 256; i++) {
        lastIndex[i] = -1;
    }

    int left = 0;
    int maxLength = 0;

    for (int right = 0; s[right] != '\0'; right++) {
        unsigned char current = s[right];

        if (lastIndex[current] >= left) {
            left = lastIndex[current] + 1;
        }

        lastIndex[current] = right;

        int length = right - left + 1;

        if (length > maxLength) {
            maxLength = length;
        }
    }

    return maxLength;
}

int main() {
    char s[1000];

    printf("Enter a string: ");
    fgets(s, sizeof(s), stdin);

    // Remove newline
    s[strcspn(s, "\n")] = '\0';

    printf("Length of longest substring: %d\n",
           longestUniqueSubstring(s));

    return 0;
}