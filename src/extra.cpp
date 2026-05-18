/**
 * @file extra.cpp
 * @brief Extra: Stack, Heap, and Code Segment visualization.
 * @course Sistemas Operativos
 */
#include <iostream>
#include <iomanip>
#include "MemoryUtils.h"

int main() {
    // 1. A local variable (stack)
    int stackVar = 111;

    // 2. A dynamic variable (heap)
    int* heapVar = new int(222);

    // 3. The address of a function (code/text segment)
    void* codeAddr = (void*)&main;

    // 4. A static variable (data segment)
    static int staticVar = 333;

    std::cout << "┌─────────────────────────────────────┐\n";
    std::cout << "│         MEMORY MAP (approx)         │\n";
    std::cout << "├─────────────────────────────────────┤\n";
    std::cout << "│  [HIGH]  Stack  →  " << &stackVar      << "        │\n";
    std::cout << "│          stackVar = " << stackVar       << "             │\n";
    std::cout << "├─────────────────────────────────────┤\n";
    std::cout << "│  [MID ]  Heap   →  " << heapVar        << "         │\n";
    std::cout << "│          heapVar  = " << *heapVar       << "             │\n";
    std::cout << "├─────────────────────────────────────┤\n";
    std::cout << "│  [LOW ]  Data   →  " << &staticVar     << "         │\n";
    std::cout << "│          staticVar = " << staticVar    << "            │\n";
    std::cout << "├─────────────────────────────────────┤\n";
    std::cout << "│  [LOW ]  Code   →  " << codeAddr       << "         │\n";
    std::cout << "│          main() address             │\n";
    std::cout << "└─────────────────────────────────────┘\n";

    delete heapVar;
    heapVar = nullptr;

    return 0;
}
