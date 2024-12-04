#include<stdio.h>
int count = 0;


void insertion_sort(int arr[], int n)
{
    for(int i=1;i<n;i++)   //for unsorted elements
    {
        int key = arr[i];
        int j = i-1;
        while(j>=0 && arr[j] > key) //for sorted elements
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1]=key;
        }
}

void main()
{
    int arr[] = {90,87,77,50,30,1,20,10};
    int n = sizeof(arr)/sizeof(arr[0]);

    printf("\nbefore sorting : ");
    for(int i =0; i<n ; i++)
        printf(" %d ", arr[i]);

    insertion_sort(arr,n);

    printf("\nafter sorting : ");
    for(int i =0; i<n ; i++)
        printf(" %d ", arr[i]);
    
}