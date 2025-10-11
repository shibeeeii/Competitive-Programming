/*
 * Heap Sort Algorithm Implementation
 * 
 * Time Complexity: O(n log n) for all cases (best, average, worst)
 * Space Complexity: O(1) - in-place sorting algorithm
 * 
 * Heap Sort is a comparison-based sorting algorithm that uses a binary heap data structure.
 * It works by first building a max heap from the input array, then repeatedly extracting
 * the maximum element and placing it at the end of the array.
 * 
 * Algorithm Steps:
 * 1. Build a max heap from the input array
 * 2. Repeatedly:
 *    a. Extract the maximum element (root) and place it at the end
 *    b. Reduce heap size by 1
 *    c. Heapify the root to maintain heap property
 */

#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

// Function to heapify a subtree rooted at index i
// n is the size of the heap
void heapify(int arr[], int n, int i) {
    int largest = i;        // Initialize largest as root
    int left = 2 * i + 1;   // Left child index
    int right = 2 * i + 2;  // Right child index
    
    // If left child is larger than root
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }
    
    // If right child is larger than largest so far
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }
    
    // If largest is not root
    if (largest != i) {
        swap(arr[i], arr[largest]);
        
        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}

// Main function to do heap sort
void heapSort(int arr[], int n) {
    // Step 1: Build max heap
    // Start from last non-leaf node and heapify each node
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
    
    // Step 2: Extract elements from heap one by one
    for (int i = n - 1; i > 0; i--) {
        // Move current root to end
        swap(arr[0], arr[i]);
        
        // Call heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

// Utility function to print array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i];
        if (i < n - 1) {
            cout << " ";
        }
    }
    cout << endl;
}

// Driver program
int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    
    int arr[n];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    cout << "Original array: ";
    printArray(arr, n);
    
    heapSort(arr, n);
    
    cout << "Sorted array: ";
    printArray(arr, n);
    
    return 0;
}

/*
 * Example Usage:
 * 
 * Input:
 * Enter number of elements: 6
 * Enter elements: 12 11 13 5 6 7
 * 
 * Output:
 * Original array: 12 11 13 5 6 7
 * Sorted array: 5 6 7 11 12 13
 * 
 * Complexity Analysis:
 * - Building the heap: O(n)
 * - Extracting elements: O(n log n)
 * - Overall: O(n log n)
 * 
 * Advantages:
 * 1. Guaranteed O(n log n) time complexity
 * 2. In-place sorting (O(1) extra space)
 * 3. Not affected by input distribution
 * 
 * Disadvantages:
 * 1. Not stable (doesn't preserve relative order of equal elements)
 * 2. Not adaptive (doesn't perform better on partially sorted arrays)
 * 3. Poor cache performance due to non-sequential memory access
 */