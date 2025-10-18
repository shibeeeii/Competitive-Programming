/*
 * Heap Sort - Complete Implementation
 * Includes both recursive and iterative versions
 * 
 * Author: Competitive Programming Repository
 * Time Complexity: O(n log n)
 * Space Complexity: O(1) for iterative, O(log n) for recursive
 */

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

// Recursive Heapify
void heapifyRecursive(int arr[], int n, int i) {
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;
    
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }
    
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }
    
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapifyRecursive(arr, n, largest);
    }
}

// Iterative Heapify (more efficient for competitive programming)
void heapifyIterative(int arr[], int n, int i) {
    while (true) {
        int largest = i;
        int left = 2*i + 1;
        int right = 2*i + 2;
        
        if (left < n && arr[left] > arr[largest]) {
            largest = left;
        }
        
        if (right < n && arr[right] > arr[largest]) {
            largest = right;
        }
        
        if (largest == i) break;
        
        swap(arr[i], arr[largest]);
        i = largest;
    }
}

// Heap Sort using recursive heapify
void heapSortRecursive(int arr[], int n) {
    // Build max heap
    for (int i = n/2 - 1; i >= 0; i--) {
        heapifyRecursive(arr, n, i);
    }
    
    // Extract elements from heap
    for (int i = n-1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapifyRecursive(arr, i, 0);
    }
}

// Heap Sort using iterative heapify (recommended for contests)
void heapSortIterative(int arr[], int n) {
    // Build max heap
    for (int i = n/2 - 1; i >= 0; i--) {
        heapifyIterative(arr, n, i);
    }
    
    // Extract elements from heap
    for (int i = n-1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapifyIterative(arr, i, 0);
    }
}

// Using STL make_heap and sort_heap (fastest for contests)
void heapSortSTL(int arr[], int n) {
    make_heap(arr, arr + n);
    sort_heap(arr, arr + n);
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i];
        if (i < n-1) cout << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    
    int arr1[n], arr2[n], arr3[n];
    
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr1[i];
        arr2[i] = arr1[i];  // Copy for different sorting methods
        arr3[i] = arr1[i];
    }
    
    cout << "\nOriginal array: ";
    printArray(arr1, n);
    
    // Test recursive version
    heapSortRecursive(arr1, n);
    cout << "Recursive Heap Sort: ";
    printArray(arr1, n);
    
    // Test iterative version
    heapSortIterative(arr2, n);
    cout << "Iterative Heap Sort: ";
    printArray(arr2, n);
    
    // Test STL version
    heapSortSTL(arr3, n);
    cout << "STL Heap Sort: ";
    printArray(arr3, n);
    
    return 0;
}

/*
 * Performance Notes for Competitive Programming:
 * 
 * 1. Iterative heapify is faster than recursive (no function call overhead)
 * 2. STL make_heap + sort_heap is usually the fastest
 * 3. For most contest problems, just use sort() from STL
 * 4. Use heap sort when you need guaranteed O(n log n) performance
 * 
 * When to use Heap Sort in contests:
 * - When you need guaranteed O(n log n) time complexity
 * - When memory is limited (O(1) extra space)
 * - When implementing priority queues manually
 * - When you need to find kth largest/smallest elements efficiently
 */