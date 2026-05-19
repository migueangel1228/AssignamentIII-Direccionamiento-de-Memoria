/**
 * @file activity1.cpp
 * @brief Activity 1: Variables, memory addresses, and basic pointers.
 * @course Sistemas Operativos
 */
#include <iostream>
#include <iomanip>
#include "MemoryUtils.h"

using namespace std;

int main() {
    printSeparator("Activity 1 — Variables & Pointers");

    // Step 1: Declare and assign an integer variable
    int value = 42;
    cout << "[Step 1] value          = " << value << endl;

    // Step 2: Show the memory address of that variable
    cout << "[Step 2] Address        = " << &value << endl;

    // Step 3: Modify the value indirectly using a pointer
    int* ptr = &value;
    *ptr = 100;
    cout << "[Step 3] Modified value = " << value << "  (via pointer *ptr = 100)" << endl;

    // Step 4: Show the value and address again
    cout << "[Step 4] value          = " << value << "  | Address = " << &value << "  (unchanged)" << endl;
    
    cout << "==========================================\n";

    return 0;
}
