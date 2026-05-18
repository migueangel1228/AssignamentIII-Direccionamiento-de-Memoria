/**
 * @file activity4.cpp
 * @brief Activity 4: Dynamic memory and 2D matrix.
 * @course Sistemas Operativos
 */
#include <iostream>
#include <iomanip>
#include "MemoryUtils.h"

int main() {
    printSeparator("Activity 4 — Dynamic Memory (new/delete)");

    // Step 1: Use `new` for dynamic allocation
    int* singleInt = new int(99);
    std::cout << "[Step 1] singleInt = " << *singleInt << "  | addr = " << singleInt << std::endl;
    delete singleInt;
    singleInt = nullptr;
    std::cout << "[Step 1] Memory released for singleInt." << std::endl << std::endl;

    // Step 2: Create a dynamic 2D integer matrix (3 rows x 4 columns)
    const int rows = 3;
    const int cols = 4;
    int** matrix = new int*[rows];
    for (int i = 0; i < rows; ++i) {
        matrix[i] = new int[cols];
    }

    // Step 3: Fill the matrix with data
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            matrix[i][j] = (i + 1) * (j + 1);
        }
    }

    // Step 4: Print the formatted matrix
    std::cout << "[Step 2-3] 3x4 Dynamic Matrix (i+1)*(j+1):" << std::endl;
    for (int i = 0; i < rows; ++i) {
        std::cout << "Row " << i << " [addr=" << matrix[i] << "]:";
        for (int j = 0; j < cols; ++j) {
            std::cout << std::setw(4) << matrix[i][j];
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    // Step 5: Free the memory
    for (int i = 0; i < rows; ++i) {
        delete[] matrix[i];
        matrix[i] = nullptr;
    }
    delete[] matrix;
    matrix = nullptr;
    std::cout << "[Step 5] Memory released successfully." << std::endl;

    std::cout << "==========================================\n";

    return 0;
}
