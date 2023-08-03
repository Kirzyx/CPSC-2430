//Ryan Luo
//lab 5

#include <iostream>
#include <chrono>
using namespace std::chrono;


void heapSort(int* A, int n);
void percolateDown(int* arr, int size, int index);

void mergeSort(int* A, int n);
void merge(int* arr, int start, int mid, int end);


void quickSort(int* A, int n);
int partition(int* arr, int start, int end);
void quick(int* A, int start, int end);

void printArray(const int* arr, int size);

void measureSort(void (*sortingFunction)(int*, int));

int main()
{
    void (*sortingFunction)(int*, int);

    std::cout << std::endl << "HEAP SORT" << std::endl;
    sortingFunction = &heapSort;
    measureSort(sortingFunction);

    std::cout << std::endl << "MERGE SORT" << std::endl;
    sortingFunction = &mergeSort;
    measureSort(sortingFunction);

    std::cout << std::endl << "QUICK SORT" << std::endl;
    sortingFunction = &quickSort;
    measureSort(sortingFunction);

    std::cout << std::endl << std::endl;
    return 0;
}

void mergeSort(int* A, int n) {
    //base case: if array has 1 or less elements stop
    if (n <= 1) {
        return;
    }
    //split array into 2 halves
    int mid = n / 2;
    //sort first half
    mergeSort(A, mid);
    //sort second half
    mergeSort(A + mid, n - mid);
    //merge the two halves
    merge(A, 0, mid, n);
}

void merge(int* arr, int start, int mid, int end) {
    int leftSize = mid - start;
    int rightSize = end - mid;
    // Create temporary arrays
    int* leftArray = new int[leftSize];
    int* rightArray = new int[rightSize];
    // Copy data to temporary arrays
    for (int i = 0; i < leftSize; i++) {
        leftArray[i] = arr[start + i];
    }
    for (int i = 0; i < rightSize; i++) {
        rightArray[i] = arr[mid + i];
    }

    int leftIndex = 0;  // Initial index of the first subarray
    int rightIndex = 0;  // Initial index of the second subarray
    int mergedIndex = start;  // Initial index of the merged subarray

    // Compare elements at each location and copy the smaller one
    while (leftIndex < leftSize && rightIndex < rightSize) {
        if (leftArray[leftIndex] <= rightArray[rightIndex]) {
            arr[mergedIndex] = leftArray[leftIndex];
            leftIndex++;
        } else {
            arr[mergedIndex] = rightArray[rightIndex];
            rightIndex++;
        }
        mergedIndex++;
    }

    // Copy the remaining elements of the left subarray, if any
    while (leftIndex < leftSize) {
        arr[mergedIndex] = leftArray[leftIndex];
        leftIndex++;
        mergedIndex++;
    }

    // Copy the remaining elements of the right subarray, if any
    while (rightIndex < rightSize) {
        arr[mergedIndex] = rightArray[rightIndex];
        rightIndex++;
        mergedIndex++;
    }

    // Clean up the temporary arrays
    delete[] leftArray;
    delete[] rightArray;
}

void quickSort(int* A, int n) {
    //call the sorting function
    quick(A, 0, n - 1);
}

void quick(int* A, int start, int end) {
    //base case: if start is less than end, keep sorting
    if (start < end) {
        //randomly choose pivot
        int pivotIndex = start + std::rand() % (end - start + 1);
        
        //swap element at the start with pviot
        std::swap(A[start], A[pivotIndex]);

        //partition the range around the pivot to get a new pivot index
        int newPivot = partition(A, start, end);
        
        //recursively call the swaps 
        quick(A, start, newPivot - 1);
        quick(A, newPivot + 1, end);
    }
}

int partition(int* arr, int start, int end) {
    //choose first element as pivot
    int pivot = arr[start];
    int m = start;

    //iterate over the array
    for (int i = start + 1; i <= end; i++) {
        if (arr[i] < pivot) {
            m++;
            std::swap(arr[m], arr[i]);
        }
    }
    //swap the pivot with the element at the partition pivot
    std::swap(arr[start], arr[m]);

    //return pivot index
    return m;
}



void printArray(const int* arr, int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
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
void measureSort(void (*sortingFunction)(int*, int)){    
    const int size = 10;
    int array[size];
    
    std::cout << "Unsorted array: ";
    for (int i = 0; i < size; i++) {
        array[i] = rand() % 100000;
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