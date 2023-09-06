#include <stdio.h>

void sort_array(int arr[], int n)
{
    int i, j;
    int temp;
    for (i = 0; i < n-1; i++)
    {
        for (j = 0; j < n-i-1; j++)
        {
            if (arr[j] > arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    return;
}


int binarySearch(int array[], int x, int low, int high)
{
    // Repeat until the pointers low and high meet each other
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (array[mid] == x)
            return mid;

        if (array[mid] < x)
            low = mid + 1;

        else
            high = mid - 1;
    }

    return -1;
}

int main()
{
        int x;
        printf("Enter an element which you want to search : ");
        scanf("%d",&x);
        int array[] = {1,3,2,5,4,6,8,7,9,10};
        int n = sizeof(array) / sizeof(array[0]);
        // If characters are not sorting.
        sort_array(array, n);
        for(int i=0; i<n; i++)printf("%d ",array[i]);
        printf("\n");
        printf("\n");

        int result = binarySearch(array, x, 0, n-1);
        if (result == -1)
            printf("Not found\n");
        else
            printf("Element is found at index : %d\n", result);

    return 0;
}
