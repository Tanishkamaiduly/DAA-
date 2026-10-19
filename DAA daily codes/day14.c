#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int smallestDifference(int arr1[], int n1, int arr2[], int n2) {
    int i = 0, j = 0;
    int minDiff = abs(arr1[0] - arr2[0]);

    while (i < n1 && j < n2) {
        int diff = abs(arr1[i] - arr2[j]);

        if (diff < minDiff) {
            minDiff = diff;
        }

        if (arr1[i] < arr2[j]) {
            i++;
        } else {
            j++;
        }
    }

    return minDiff;
}

int main() {
    int n1, n2;

    printf("Enter size of first array: ");
    scanf("%d", &n1);

    int arr1[n1];

    printf("Enter elements of first array:\n");
    for (int i = 0; i < n1; i++) {
        scanf("%d", &arr1[i]);
    }

    printf("Enter size of second array: ");
    scanf("%d", &n2);

    int arr2[n2];

    printf("Enter elements of second array:\n");
    for (int i = 0; i < n2; i++) {
        scanf("%d", &arr2[i]);
    }

    qsort(arr1, n1, sizeof(int), compare);
    qsort(arr2, n2, sizeof(int), compare);

    printf("Smallest difference: %d\n",
           smallestDifference(arr1, n1, arr2, n2));

    return 0;
}