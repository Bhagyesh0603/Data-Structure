// insertion sort

#include <stdio.h>
#include <stdlib.h>
void display(int *A, int n)
{
array:
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}
void insertion_sort(int *A, int n)
{
    for (int i = 1; i <= n - 1; i++)
    {
        int key = A[i];
        int j = i - 1;
        while (j >= 0 && A[j] > key)
        {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = key;
    }
    display(A, n);
}
int main()
{
    int arr[] = {5, 50, 4, 12, 45, 84, 1};
    int n = (sizeof(arr) / sizeof(arr[0]));
    display(arr, n);
    insertion_sort(arr, n);

    return 0;
}