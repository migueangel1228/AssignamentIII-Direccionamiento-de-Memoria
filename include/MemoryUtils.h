/**
 * @file MemoryUtils.h
 * @brief Shared utility functions for memory address visualization.
 * @course Sistemas Operativos
 */

#ifndef MEMORY_UTILS_H
#define MEMORY_UTILS_H

#include <iostream>
#include <string>
#include <iomanip>

/**
 * @brief Prints a separator line with a title.
 * @param title The title to display in the separator.
 */
inline void printSeparator(const std::string& title) {
    std::cout << "==========================================\n";
    std::cout << " " << title << "\n";
    std::cout << "==========================================\n";
}

/**
 * @brief Prints the address of a pointer with a descriptive label.
 * @param label Descriptive label for the output.
 * @param addr Address to print (void*).
 */
inline void printAddress(const std::string& label, const void* addr) {
    std::cout << std::left << std::setw(24) << label
              << "= " << addr << "\n";
}

#endif // MEMORY_UTILS_H
