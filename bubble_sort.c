// this is bubble sort

#include <stdio.h>
int count = 0;
void bubble_sort(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < (n - 1) - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
        count++;
    }
}

void main()
{
    int arr[] = {91, 5, 10, 46, 87, 20, 35}; // declaration of array
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("\nbefore sorting : ");
    for (int i = 0; i < n; i++)
    {
        printf(" %d ", arr[i]);
    }

    bubble_sort(arr, n); // function call

    printf("\nafter sorting : ");
    for (int i = 0; i < n; i++)
    {
        printf(" %d ", arr[i]);
    }
    printf("\ncount = %d", count);
}