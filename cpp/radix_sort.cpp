#include "../include/radix_sort.h"

void RadixSort::counting_sort_by_digit(int arr[], int n, int exp) {
    int count_arr[10] = {0};
    int* sorted_arr = new int[n];

    for(int i = 0; less(i, n); ++i) {
        count_arr[(arr[i] / exp) % 10]++;
    }

    for(int i = 1; less(i, 10); ++i) {
        count_arr[i] += count_arr[i - 1];
    }

    for(int i = n - 1; greater_equal(i, 0); --i) {
        sorted_arr[count_arr[(arr[i] / exp) % 10] - 1] = arr[i];
        count_arr[(arr[i] / exp) % 10]--;
    }

    for(int i = 0; less(i, n); ++i) {
        arr[i] = sorted_arr[i];
    }

    delete [] sorted_arr;
}

void RadixSort::sort(int arr[], int n) {
    auto start = std::chrono::high_resolution_clock::now();

    int max_num = arr[0];
    for(int i = 0; less(i, n); ++i) {
        if(greater(arr[i], max_num)) {
            max_num = arr[i];
        }
    }

    for (int exp = 1; greater(max_num / exp, 0); exp *= 10) {
        counting_sort_by_digit(arr, n, exp);
    }

    auto end = std::chrono::high_resolution_clock::now();
    runtime = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
}