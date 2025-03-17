#include "../include/quick_sort.h"

void QuickSort::sort(int arr[], int n) {
    auto start = std::chrono::high_resolution_clock::now();

    // implement algorithm here

    auto end = std::chrono::high_resolution_clock::now();
    runtime = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
}