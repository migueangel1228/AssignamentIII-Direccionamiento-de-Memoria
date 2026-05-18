/**
 * @file activity2.cpp
 * @brief Activity 2: Pointers, references, and their addresses.
 * @course Sistemas Operativos
 */
#include <iostream>
#include <iomanip>
#include "MemoryUtils.h"

int main() {
    printSeparator("Activity 2 — Pointers & References");

    // Step 1: Declare a variable and a pointer to it
    int variable = 55;
    int* ptr = &variable;
    std::cout << "[Step 1] variable       = " << variable << std::endl;

    // Step 2: Use the pointer to access and modify the value
    std::cout << "[Step 2] via *ptr       = " << *ptr;
    *ptr = 200;
    std::cout << "  →  *ptr = 200  →  variable = " << variable << std::endl;

    // Step 3: Create a reference and use it to modify the value
    int& ref = variable;
    std::cout << "[Step 3] via ref        = " << ref;
    ref = 300;
    std::cout << " →  ref = 300   →  variable = " << variable << std::endl;

    // Step 4: Show the addresses of the pointer and the reference
    std::cout << "[Step 4] &variable      = " << &variable << std::endl;
    std::cout << "         ptr (points to)= " << ptr << "  ← same as &variable" << std::endl;
    std::cout << "         &ptr (ptr addr) = " << &ptr << " ← different (ptr is its own variable)" << std::endl;
    // A reference is an alias for another variable; it does not have its own memory address.
    // Taking the address of a reference returns the address of the variable it refers to.
    std::cout << "         &ref            = " << &ref << " ← same as &variable (ref is an alias)" << std::endl;

    std::cout << "==========================================\n";

    return 0;
}
