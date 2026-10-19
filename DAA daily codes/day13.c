#include <stdio.h>

int trapWater(int height[], int n) {
    int left = 0;
    int right = n - 1;
    int leftMax = 0;
    int rightMax = 0;
    int water = 0;

    while (left < right) {
        if (height[left] <= height[right]) {
            if (height[left] >= leftMax) {
                leftMax = height[left];
            } else {
                water += leftMax - height[left];
            }
            left++;
        } else {
            if (height[right] >= rightMax) {
                rightMax = height[right];
            } else {
                water += rightMax - height[right];
            }
            right--;
        }
    }

    return water;
}

int main() {
    int n;

    printf("Enter number of bars: ");
    scanf("%d", &n);

    int height[n];

    printf("Enter bar heights:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &height[i]);
    }

    printf("Trapped water: %d units\n", trapWater(height, n));

    return 0;
}