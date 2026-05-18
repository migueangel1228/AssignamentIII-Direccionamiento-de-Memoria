/**
 * @file activity3.cpp
 * @brief Activity 3: Arrays and pointer arithmetic.
 * @course Sistemas Operativos
 */
#include <iostream>
#include <iomanip>
#include "MemoryUtils.h"

void printArray(const int* arr, int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << "  ";
    }
    std::cout << std::endl;
}

int main() {
    printSeparator("Activity 3 — Arrays & Pointer Arithmetic");

    // Step 1: Declare an array of 5 integers
    int arr[5] = {10, 20, 30, 40, 50};
    std::cout << "Original array  : ";
    printArray(arr, 5);

    // Step 2: Use pointers to access and modify elements
    int* ptr = arr; // ptr points to the first element
    for (int i = 0; i < 5; ++i) {
        *(ptr + i) = *(ptr + i) * 2;
    }
    std::cout << "Modified array  : ";
    printArray(arr, 5);

    // Step 3: Show the address of the array and the pointer
    std::cout << "Array base addr : " << arr << std::endl;
    std::cout << "Pointer &ptr    : " << &ptr << "  ← different from array base" << std::endl;
    std::cout << "Element details :" << std::endl;
    for (int i = 0; i < 5; ++i) {
        std::cout << "  [" << i << "] addr=" << (ptr + i) << " value=" << *(ptr + i) << std::endl;
    }

    std::cout << "==========================================\n";

    return 0;
}
