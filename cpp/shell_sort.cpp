#include "../include/shell_sort.h"

void ShellSort::sort(int arr[], int n) {
    auto start = std::chrono::high_resolution_clock::now();
    for(int gap = n / 2; greater(gap, 0); gap /= 2) {
        for(int i = gap; less(i, n); ++i) {
            int temp = arr[i];
            int j;
            for(j = i; greater_equal(j, gap) && greater(arr[j - gap], temp); j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
    auto end = std::chrono::high_resolution_clock::now();
    runtime = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
}