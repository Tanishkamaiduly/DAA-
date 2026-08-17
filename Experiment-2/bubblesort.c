//Bubble sort
#include <stdio.h>
#include <time.h>
int main()
{
    int n, i, j, temp;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d integers:\n", n);
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    
    // Bubble sort algorithm
    clock_t start = clock();
    for(i = 0; i < n-1; i++) {
        for(j = 0; j < n-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                // Swap arr[j] and arr[j+1]
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    clock_t end = clock();
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Sorted array: \n");
    for(i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\nTime taken: %f seconds\n", time_taken);

    return 0;
}