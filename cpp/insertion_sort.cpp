#include "../include/insertion_sort.h"

#include <chrono>

void InsertionSort::sort(int arr[], int n) {
    auto start = std::chrono::high_resolution_clock::now();
    for(int i = 1; less(i, n); i++) {
        int key = arr[i];
        int j = i - 1;
        while(greater_equal(j, 0) && greater(arr[j], key)) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
    auto end = std::chrono::high_resolution_clock::now();
    runtime = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
}