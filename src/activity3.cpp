/**
 * @file activity3.cpp
 * @brief Activity 3: Arrays and pointer arithmetic.
 * @course Sistemas Operativos
 */
#include <iostream>
#include <iomanip>
#include "MemoryUtils.h"

using namespace std;

void printArray(const int* arr, int size) {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << "  ";
    }
    cout << endl;
}

int main() {
    printSeparator("Activity 3 — Arrays & Pointer Arithmetic");

    // Step 1: Declare an array of 5 integers
    int arr[5] = {10, 20, 30, 40, 50};
    cout << "Original array  : ";
    printArray(arr, 5);

    // Step 2: Use pointers to access and modify elements
    int* ptr = arr; // ptr points to the first element
    for (int i = 0; i < 5; ++i) {
        *(ptr + i) = *(ptr + i) * 2;
    }
    cout << "Modified array  : ";
    printArray(arr, 5);

    // Step 3: Show the address of the array and the pointer
    cout << "Array base addr : " << arr << endl;
    cout << "Pointer &ptr    : " << &ptr << "  ← different from array base" << endl;
    cout << "Element details :" << endl;
    for (int i = 0; i < 5; ++i) {
        cout << "  [" << i << "] addr=" << (ptr + i) << " value=" << *(ptr + i) << endl;
    }

    cout << "==========================================\n";

    return 0;
}
