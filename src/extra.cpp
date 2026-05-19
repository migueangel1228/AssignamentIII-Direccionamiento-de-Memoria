/**
 * @file extra.cpp
 * @brief Extra: Stack, Heap, and Code Segment visualization.
 * @course Sistemas Operativos
 */
#include <iostream>
#include <iomanip>
#include "MemoryUtils.h"

using namespace std;

int main() {
    // 1. A local variable (stack)
    int stackVar = 111;

    // 2. A dynamic variable (heap)
    int* heapVar = new int(222);

    // 3. The address of a function (code/text segment)
    void* codeAddr = (void*)&main;

    // 4. A static variable (data segment)
    static int staticVar = 333;

    cout << "┌─────────────────────────────────────┐\n";
    cout << "│         MEMORY MAP (approx)         │\n";
    cout << "├─────────────────────────────────────┤\n";
    cout << "│  [HIGH]  Stack  →  " << &stackVar      << "         │\n";
    cout << "│          stackVar = " << stackVar       << "             │\n";
    cout << "├─────────────────────────────────────┤\n";
    cout << "│  [MID ]  Heap   →  " << heapVar        << "         │\n";
    cout << "│          heapVar  = " << *heapVar      << "             │\n";
    cout << "├─────────────────────────────────────┤\n";
    cout << "│  [LOW ]  Data   →  " << &staticVar     << "         │\n";
    cout << "│          staticVar = " << staticVar    << "            │\n";
    cout << "├─────────────────────────────────────┤\n";
    cout << "│  [LOW ]  Code   →  " << codeAddr       << "         │\n";
    cout << "│          main() address             │\n";
    cout << "└─────────────────────────────────────┘\n";

    delete heapVar;
    heapVar = nullptr;

    return 0;
}
