/**
 * @file activity4.cpp
 * @brief Activity 4: Dynamic memory and 2D matrix.
 * @course Sistemas Operativos
 */
#include <iostream>
#include <iomanip>
#include "MemoryUtils.h"

using namespace std;

int main() {
    printSeparator("Activity 4 — Dynamic Memory (new/delete)");

    // Step 1: Use `new` for dynamic allocation
    int* singleInt = new int(99);
    cout << "[Step 1] singleInt = " << *singleInt << "  | addr = " << singleInt << endl;
    delete singleInt;
    singleInt = nullptr;
    cout << "[Step 1] Memory released for singleInt." << endl << endl;

    // Step 2: Create a dynamic 2D integer matrix (3 rows x 4 columns)
    const int rows = 3;
    const int cols = 4;
    int** matrix = new int*[rows];
    for (int i = 0; i < rows; ++i) {
        matrix[i] = new int[cols];
    }


    // Step 5: Free the memory
    for (int i = 0; i < rows; ++i) {
        delete[] matrix[i];
        matrix[i] = nullptr;
    }
    delete[] matrix;
    matrix = nullptr;
    cout << "[Step 5] Memory released successfully." << endl;

    cout << "==========================================\n";

    return 0;
}
