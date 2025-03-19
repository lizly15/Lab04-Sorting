#include "../include/bubble_sort.h"

void BubbleSort::sort(int arr[], int n) {
    auto start = std::chrono::high_resolution_clock::now();

    // implement algorithm here
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j+1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    auto end = std::chrono::high_resolution_clock::now();
    runtime = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();

}
