#include <iostream>
#include <ctime>
#include <cstdlib>
#include <chrono>

void heapSort(int* A, int n);
void percolateDown(int* arr, int size, int index);
void printArray(const int* arr, int size);
void measureSort(void (*sortingFunction)(int*, int));

int main() {
    measureSort(heapSort);
    return 0;
}

void percolateDown(int* arr, int size, int index) {
    // Maintain heap structure from top to bottom
        
    // Base cases
    // If current node is a leaf node
    if (index >= size / 2) {
        return;
    }

    int leftChild = 2 * index + 1;
    int rightChild = 2 * index + 2;
    int smallestChild = leftChild;

    // Check if node has two children
    if (rightChild < size && arr[rightChild] > arr[leftChild]) {
        smallestChild = rightChild;
    }

    // If current node has only a left child and the value of the node is smaller than both children, we can stop
    if (arr[index] >= arr[smallestChild]) {
        return;
    }

    // Swap the smallest child with the current node
    std::swap(arr[index], arr[smallestChild]);

    // Recursively call percolateDown with the swapped node
    percolateDown(arr, size, smallestChild);
}


void heapSort(int* A, int n) {
    // Arrange array
    for (int i = n / 2 - 1; i >= 0; i--) {
        percolateDown(A, n, i);
    }

    // Extract elements from the heap one by one;
    for (int i = n - 1; i > 0; i--) {
        // Move current root to end
        std::swap(A[0], A[i]);

        // Percolate down
        percolateDown(A, i, 0);
    }
}

void printArray(const int* arr, int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void measureSort(void (*sortingFunction)(int*, int)){    const int size = 10;
    int array[size];
    
    std::cout << "Unsorted array: ";
    for (int i = 0; i < size; i++) {
        array[i] = rand() % 100000;
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
    
    auto start = std::chrono::high_resolution_clock::now();
    sortingFunction(array, size);
    auto stop = std::chrono::high_resolution_clock::now();
    
    std::cout << "Sorted array : ";
    printArray(array, size);
    
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start).count();
    std::cout << "Duration: " << duration << " ns" << std::endl;
}
