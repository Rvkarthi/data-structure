// SELECTION SORTING
#include <stdio.h>

void selection_sort(int arr[], int n)
{
    int min, j, i;
    for (i = 0; i < n - 1; i++)
    {
        min = i;
        for (j = i; j < n; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        int temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
    }
}

void main()
{
    int arr[] = {21, 50, 40, 98, 10, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("\nbefore sorting : ");

    for (int i = 0; i < n; i++)
    {
        printf(" %d ", arr[i]);
    }

    selection_sort(arr, n);
    printf("\nafter sorting : ");
    for (int i = 0; i < n; i++)
    {
        printf(" %d ", arr[i]);
    }
}