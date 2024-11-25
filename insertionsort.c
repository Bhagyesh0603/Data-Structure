#include<stdio.h>
#include<stdlib.h>

// Function to display the array
void display(int a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

// Function to implement Insertion Sort
void insertionsort(int A[], int n) {
    for (int i = 1; i < n; i++) {
        int key = A[i];  // Current element to be inserted
        int j = i - 1;

        // Shift elements of the sorted segment forward to make space
        while (j >= 0 && A[j] > key) {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = key;  // Place the key in its correct position

        // Display the array after each pass
        printf("After pass %d: ", i);
        display(A, n);
    }
}

int main() {
    int A[] = {45, 6, 78, 5, 71, 9, 16, 2};
    int n = sizeof(A) / sizeof(A[0]);

    printf("Original Array: ");
    display(A, n);

    // Perform insertion sort
    insertionsort(A, n);

    printf("Sorted Array: ");
    display(A, n);

    return 0;
}

//hai example maine uder-define likha hai hame array input from user lena hai..............

// output:-
// Original Array: 45 6 78 5 71 9 16 2 
// After pass 1: 6 45 78 5 71 9 16 2 
// After pass 2: 6 45 78 5 71 9 16 2 
// After pass 3: 5 6 45 78 71 9 16 2 
// After pass 4: 5 6 45 71 78 9 16 2 
// After pass 5: 5 6 9 45 71 78 16 2 
// After pass 6: 5 6 9 16 45 71 78 2 
// After pass 7: 2 5 6 9 16 45 71 78 
// Sorted Array: 2 5 6 9 16 45 71 78 
