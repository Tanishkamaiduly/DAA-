#include <stdio.h>
#include <limits.h>

int main()
{
    int n, i;
    int arr[100];
    int largest = INT_MIN, second = INT_MIN;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    for(i = 0; i < n; i++)
    {
        if(arr[i] > largest)
        {
            second = largest;
            largest = arr[i];
        }
        else if(arr[i] > second && arr[i] != largest)
        {
            second = arr[i];
        }
    }

    if(second == INT_MIN)
        printf("No distinct second-largest element exists.");
    else
        printf("Second-largest element = %d", second);

    return 0;
}