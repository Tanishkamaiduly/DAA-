//selection sort
#include <stdio.h>
#include <time.h>
int main()
{
    int n, i, j, min_idx, temp;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    clock_t start = clock();

    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;

        temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }

    clock_t end = clock();
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Sorted array:\n");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\nTime taken to sort: %f seconds\n", time_taken);

    return 0;
}