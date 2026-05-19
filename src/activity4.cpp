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

    // Step 3: Fill the matrix with data
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            matrix[i][j] = (i + 1) * (j + 1);
        }
    }

    // Step 4: Print the formatted matrix
    cout << "[Step 2-3] 3x4 Dynamic Matrix (i+1)*(j+1):" << endl;
    for (int i = 0; i < rows; ++i) {
        cout << "Row " << i << " [addr=" << matrix[i] << "]:";
        for (int j = 0; j < cols; ++j) {
            cout << setw(4) << matrix[i][j];
        }
        cout << endl;
    }
    cout << endl;

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
