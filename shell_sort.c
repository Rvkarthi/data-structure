#include <stdio.h>

void shell_sort(int arr[], int n)
{
    for (int gap = n / 2; gap > 0; gap = gap / 2)
    {
        for (int i = gap; i < n; i++)
        {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
            {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

void main()
{
    int arr[] = {90, 87, 77, 50, 30, 1, 20, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("\nbefore sorting : ");
    for (int i = 0; i < n; i++)
        printf(" %d ", arr[i]);

    shell_sort(arr, n);

    printf("\nafter sorting : ");
    for (int i = 0; i < n; i++)
        printf(" %d ", arr[i]);
}