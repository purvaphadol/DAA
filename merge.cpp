/* #include <iostream>
using namespace std;

// Merge two halves of the array
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int* L = new int[n1]; // Left subarray
    int* R = new int[n2]; // Right subarray

    // Copy data to temp arrays L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // Merge the temp arrays back into arr[left..right]
    int i = 0; // Initial index of first subarray
    int j = 0; // Initial index of second subarray
    int k = left; // Initial index of merged subarray

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    // Free allocated memory
    delete[] L;
    delete[] R;
}

// Recursive Merge Sort function
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid); // Sort first half
        mergeSort(arr, mid + 1, right); // Sort second half
        merge(arr, left, mid, right); // Merge the sorted halves
    }
}

// Function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int SIZE;

    // Take input for the size of the array
    cout << "Enter the size of the array: ";
    cin >> SIZE;

    // Check for valid size
    if (SIZE <= 0) {
        cout << "Invalid size!" << endl;
        return 1;
    }

    int* arr = new int[SIZE]; // Dynamically allocate array

    // Input array elements
    cout << "Enter " << SIZE << " elements of the array: ";
    for (int i = 0; i < SIZE; i++) {
        cin >> arr[i];
    }

    // Perform Merge Sort
    mergeSort(arr, 0, SIZE - 1);

    // Print sorted array
    cout << "Sorted array using Standard Merge Sort: ";
    printArray(arr, SIZE);

    // Free allocated memory
    delete[] arr;

    return 0;
}*/

#include <iostream>

using namespace std;

// Merge function to merge two halves of the array
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int* L = new int[n1]; // Left subarray
    int* R = new int[n2]; // Right subarray

    // Copy data to temp arrays L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // Merge the temp arrays back into arr[left..right]
    int i = 0; // Initial index of first subarray
    int j = 0; // Initial index of second subarray
    int k = left; // Initial index of merged subarray

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    // Free allocated memory
    delete[] L;
    delete[] R;
}

// Recursive function for Merge Sort
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid); // Sort first half
        mergeSort(arr, mid + 1, right); // Sort second half
        merge(arr, left, mid, right); // Merge the sorted halves
    }
}

// Function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int SIZE;

    // Take input for the size of the array
    cout << "Enter the size of the array: ";
    cin >> SIZE;

    // Check for valid size
    if (SIZE <= 0) {
        cout << "Invalid size!" << endl;
        return 1;
    }

    int* arr = new int[SIZE]; // Dynamically allocate array

    // Input array elements
    cout << "Enter " << SIZE << " elements of the array: ";
    for (int i = 0; i < SIZE; i++) {
        cin >> arr[i];
    }

    // Perform Merge Sort
    mergeSort(arr, 0, SIZE - 1);

    // Print sorted array
    cout << "Sorted array using Multithreaded Merge Sort: ";
    printArray(arr, SIZE);

    // Free allocated memory
    delete[] arr;

    return 0;
}


/*
g++ -o merge_sort merge_sort.cpp
./merge_sort
*/

