#include <stdio.h>

int removeDuplicates(int arr[], int n) {
    if (n == 0) {
        return 0;
    }

    int k = 1;  // Position for the next unique element

    for (int i = 1; i < n; i++) {
        if (arr[i] != arr[k - 1]) {
            arr[k] = arr[i];
            k++;
        }
    }

    return k;
}

int main() {
    int n;

    printf("Enter array size: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter sorted array elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int k = removeDuplicates(arr, n);

    printf("Array after removing duplicates: ");
    for (int i = 0; i < k; i++) {
        printf("%d ", arr[i]);
    }

    printf("\nNumber of unique elements: %d\n", k);

    return 0;
}