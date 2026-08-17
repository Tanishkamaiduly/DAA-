#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int main()
{
    int a[1000],key,i,found=0;
    srand(time(0));
    for(i=0;i<1000;i++)
    {
        a[i]=rand()%1000;
    }
    printf("Enter the element to search: ");
    scanf("%d",&key);
    clock_t start=clock();
    for(i=0;i<1000;i++)
    {
        if(a[i]==key)
        {
            found=1;
            break;
        }
    }
    clock_t end=clock();
    if(found)
    {
        printf("Element found at index %d\n",i);
    }
    else
    {
        printf("Element not found\n");
    }
    printf("Time taken for linear search: %lf seconds\n", (double)(end-start)/CLOCKS_PER_SEC);
    return 0;
}