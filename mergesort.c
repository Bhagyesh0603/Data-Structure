#include <stdio.h>

void printArray(int *A, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}

void merge(int A[], int mid, int low, int high) {
    int i, j, k, B[100];
    i = low;
    j = mid + 1;
    k = low;

    while (i <= mid && j <= high) {
        if (A[i] < A[j]) {
            B[k] = A[i];
            i++;
            k++;
        } else {
            B[k] = A[j];
            j++;
            k++;
        }
    }
    while (i <= mid) {
        B[k] = A[i];
        k++;
        i++;
    }
    while (j <= high) {
        B[k] = A[j];
        k++;
        j++;
    }
    for (int i = low; i <= high; i++) {
        A[i] = B[i];
    }

    // Immediate output after merging
    printf("After merging [%d-%d]: ", low, high);
    printArray(A, high + 1);
}

void mergeSort(int A[], int low, int high) {
    int mid;
    if (low < high) {
        mid = (low + high) / 2;
        mergeSort(A, low, mid);
        mergeSort(A, mid + 1, high);
        merge(A, mid, low, high);
    }
}

int main() {
    int A[100], n;

    // Taking array input from the user
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }

    printf("Original Array: ");
    printArray(A, n);

    mergeSort(A, 0, n - 1);

    printf("Sorted Array: ");
    printArray(A, n);

    return 0;
}

//isme maine user se input liya hai...
//insertion sort ka khud dekhlo.........

// output:-
// Enter the number of elements: 7
// Enter the elements of the array: 9 1 4 14 4 15 6

// Original Array: 9 1 4 14 4 15 6
// After merging [0-1]: 1 9 4 14 4 15 6
// After merging [2-3]: 1 9 4 14 4 15 6
// After merging [0-3]: 1 4 9 14 4 15 6
// After merging [4-5]: 1 4 9 14 4 15 6
// After merging [4-6]: 1 4 9 14 4 6 15
// After merging [0-6]: 1 4 4 6 9 14 15
// Sorted Array: 1 4 4 6 9 14 15
