#include <stdio.h>
#include <stdlib.h>

// Function to display the array
void display(int a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

// Function to merge two sorted subarrays
void merge(int A[], int low, int mid, int high) {
    int i = low;      // Starting index for the left subarray
    int j = mid + 1;  // Starting index for the right subarray
    int k = 0;        // Starting index for the temporary array
    int b[high - low + 1]; // Temporary array

    // Merge the two subarrays into b[]
    while (i <= mid && j <= high) {
        if (A[i] <= A[j]) {
            b[k++] = A[i++];
        } else {
            b[k++] = A[j++];
        }
    }

    // Copy any remaining elements from the left subarray
    while (i <= mid) {
        b[k++] = A[i++];
    }

    // Copy any remaining elements from the right subarray
    while (j <= high) {
        b[k++] = A[j++];
    }

    // Copy the sorted elements back into the original array
    for (i = low, k = 0; i <= high; i++, k++) {
        A[i] = b[k];
    }
}

// Function to implement merge sort
void merge_sort(int A[], int low, int high) {
    if (low < high) { // Base case
        int mid = (low + high) / 2;

        // Recursively sort the left and right subarrays
        merge_sort(A, low, mid);
        merge_sort(A, mid + 1, high);

        // Merge the sorted subarrays
        merge(A, low, mid, high);

        // Display after merging for debug
        printf("After merging (%d to %d): ", low, high);
        display(A, high + 1); // Passing full array length to display
    }
}

int main() {
    int A[] = {45, 6, 78, 5, 71, 9, 16, 2};
    int n = sizeof(A) / sizeof(A[0]);

    printf("Original Array: ");
    display(A, n);

    // Sort the array
    merge_sort(A, 0, n - 1);

    printf("Sorted Array: ");
    display(A, n);

    return 0;
}

//hai example maine uder-define likha hai hame array input from user lena hai..............
//to keep it simple to understand maine yaha pe example use kiya hai....

// output-
// Original Array: 45 6 78 5 71 9 16 2 
// After merging (0 to 1): 6 45 78 5 71 9 16 2 
// After merging (2 to 3): 6 45 5 78 71 9 16 2 
// After merging (0 to 3): 5 6 45 78 71 9 16 2 
// After merging (4 to 5): 5 6 45 78 9 71 16 2 
// After merging (6 to 7): 5 6 45 78 9 71 2 16 
// After merging (4 to 7): 5 6 45 78 2 9 16 71 
// After merging (0 to 7): 2 5 6 9 16 45 71 78 
// Sorted Array: 2 5 6 9 16 45 71 78
