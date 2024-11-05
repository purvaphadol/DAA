#include <iostream>
#include <vector>
#include <chrono>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()

using namespace std;

// Function to print the array
void printArray(const vector<int>& arr) {
    for (int val : arr) {
        cout << val << " ";
    }
    cout << endl;
}

// Function to partition the array for deterministic quicksort
int deterministicPartition(vector<int>& arr, int low, int high) {
    int pivot = arr[high]; // Choose the last element as pivot
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
            cout << "After swapping: ";
            printArray(arr); // Print the array after each swap
        }
    }
    swap(arr[i + 1], arr[high]);
    cout << "After moving pivot: ";
    printArray(arr); // Print the array after moving the pivot
    return i + 1; // Return the pivot index
}

// Deterministic quicksort function
void deterministicQuickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = deterministicPartition(arr, low, high);
        deterministicQuickSort(arr, low, pi - 1);
        deterministicQuickSort(arr, pi + 1, high);
    }
}

// Function to partition the array for randomized quicksort
int randomizedPartition(vector<int>& arr, int low, int high) {
    int randomIndex = low + rand() % (high - low + 1); // Random pivot index
    swap(arr[randomIndex], arr[high]); // Move random pivot to end
    cout << "Randomized pivot chosen: " << arr[high] << endl;
    return deterministicPartition(arr, low, high); // Use deterministic partition
}

// Randomized quicksort function
void randomizedQuickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = randomizedPartition(arr, low, high);
        randomizedQuickSort(arr, low, pi - 1);
        randomizedQuickSort(arr, pi + 1, high);
    }
}

// Function to measure execution time
template <typename Func>
double measureExecutionTime(Func sortFunc, vector<int>& arr) {
    auto start = chrono::high_resolution_clock::now();
    sortFunc(arr, 0, arr.size() - 1);
    auto end = chrono::high_resolution_clock::now();
    return chrono::duration<double, milli>(end - start).count(); // Return time in milliseconds
}

int main() {
    srand(static_cast<unsigned int>(time(0))); // Seed for random number generation

    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> arr1(n), arr2(n);
    for (int i = 0; i < n; i++) {
        arr1[i] = rand() % 1000; // Fill with random numbers
        arr2[i] = arr1[i];       // Copy for randomized quicksort
    }

    cout << "Initial Array: ";
    printArray(arr1);
    
    // Analyze deterministic quicksort
    cout << "\nDeterministic Quick Sort Steps:\n";
    double timeDeterministic = measureExecutionTime(deterministicQuickSort, arr1);
    cout << "Sorted Array (Deterministic): ";
    printArray(arr1);
    cout << "Deterministic Quick Sort Time: " << timeDeterministic << " ms" << endl;

    // Analyze randomized quicksort
    cout << "\nRandomized Quick Sort Steps:\n";
    double timeRandomized = measureExecutionTime(randomizedQuickSort, arr2);
    cout << "Sorted Array (Randomized): ";
    printArray(arr2);
    cout << "Randomized Quick Sort Time: " << timeRandomized << " ms" << endl;

    return 0;
}