#include "heap.hpp"
#include <iostream>

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Original array is \n";
    printArray(arr, n);

    heapSort(arr, n);

    std::cout << "Sorted array is \n";
    printArray(arr, n);
}
