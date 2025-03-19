#include "../include/selection_sort.h"

#include <chrono>

void SelectionSort::sort(int arr[], int n) {
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; less(i, n - 1); i++) {
        int min_index = i;
        for (int j = i + 1; less(j, n); j++) {
            if (less(arr[j], arr[min_index])) {
                min_index = j;
            }
        }
        std::swap(arr[i], arr[min_index]);
    }
    auto end = std::chrono::high_resolution_clock::now();
    runtime = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
}