#include <stdio.h>

int findSingleElement(int nums[], int n) {
    int low = 0;
    int high = n - 1;

    while (low < high) {
        int mid = low + (high - low) / 2;

        // Make mid even
        if (mid % 2 == 1) {
            mid--;
        }

        if (nums[mid] == nums[mid + 1]) {
            // Single element is on the right
            low = mid + 2;
        } else {
            // Single element is on the left or at mid
            high = mid;
        }
    }

    return nums[low];
}

int main() {
    int n;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int nums[n];

    printf("Enter the sorted array elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    printf("The single element is: %d\n", findSingleElement(nums, n));

    return 0;
}