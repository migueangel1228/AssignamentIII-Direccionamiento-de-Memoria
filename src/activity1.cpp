/**
 * @file activity1.cpp
 * @brief Activity 1: Variables, memory addresses, and basic pointers.
 * @course Sistemas Operativos
 */
#include <iostream>
#include <iomanip>
#include "MemoryUtils.h"

int main() {
    printSeparator("Activity 1 — Variables & Pointers");

    // Step 1: Declare and assign an integer variable
    int value = 42;
    std::cout << "[Step 1] value          = " << value << std::endl;

    // Step 2: Show the memory address of that variable
    std::cout << "[Step 2] Address        = " << &value << std::endl;

    // Step 3: Modify the value indirectly using a pointer
    int* ptr = &value;
    *ptr = 100;
    std::cout << "[Step 3] Modified value = " << value << "  (via pointer *ptr = 100)" << std::endl;

    // Step 4: Show the value and address again
    std::cout << "[Step 4] value          = " << value << "  | Address = " << &value << "  (unchanged)" << std::endl;
    
    std::cout << "==========================================\n";

    return 0;
}
