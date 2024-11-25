// merge sort.

#include <stdio.h>
#include <stdlib.h>
void display(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
}
void merge(int A[], int low, int mid, int high)
{
    int i = low;
    int k = low;
    int j = mid + 1;
    int B[100];
    while (i <= mid && j <= high)
    {
        if (A[i] < A[j])
        {
            B[k] = A[i];
            i++;
            k++;
        }
        if (A[i] > A[j])
        {
            B[k] = A[j];
            j++;
            k++;
        }
    }
    while (i <= mid)
    {
        B[k] = A[i];
        i++, k++;
    }
    while (j <= high)
    {
        B[k] = A[j];
        j++, k++;
    }

    for (int i = low; i <= high; i++)
    {
        A[i] = B[i];
    }
}
void merge_sort(int A[], int low, int high)
{
    int mid = (high + low) / 2;
    if (low < high)
    {
        merge_sort(A, low, mid);
        merge_sort(A, mid + 1, high);
        merge(A, low, mid, high);
    }
}
int main()
{
    int A[] = {45, 6, 78, 5, 71, 9, 16, 2};
    int n = sizeof(A) / sizeof(A[0]);
    printf("Array : ");
    display(A, n);
    merge_sort(A, 0, n - 1);
    printf("\nSorted : ");
    display(A, n);
    return 0;
}
