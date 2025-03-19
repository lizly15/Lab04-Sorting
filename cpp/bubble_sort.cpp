#include "../include/bubble_sort.h"

void BubbleSort::sort(int arr[], int n) {
    auto start = std::chrono::high_resolution_clock::now();

    for(int i = 0; i < n - 1; ++i) {
        for(int j = 0; j < n - i - 1; ++j) {
            if(greater(arr[j], arr[j + 1])) {
                swap_num(arr[j], arr[j + 1]);
            }
        }
    }

    auto end = std::chrono::high_resolution_clock::now();
    runtime = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();

}
