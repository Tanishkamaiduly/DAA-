#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int a[1000], key;
    int i, j, temp;
    int low, high, mid, found = 0;

    srand(time(0));

    for(i = 0; i < 1000; i++)
        a[i] = rand();

    // Sort the array
    for(i = 0; i < 999; i++)
    {
        for(j = i + 1; j < 1000; j++)
        {
            if(a[i] > a[j])
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }

    printf("Enter element to search: ");
    scanf("%d", &key);

    low = 0;
    high = 999;

    clock_t start = clock();

    while(low <= high)
    {
        mid = (low + high) / 2;

        if(a[mid] == key)
        {
            found = 1;
            break;
        }
        else if(a[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }

    clock_t end = clock();

    if(found)
        printf("Element found at index %d\n", mid);
    else
        printf("Element not found\n");

    printf("Execution time = %f seconds\n",
           (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}