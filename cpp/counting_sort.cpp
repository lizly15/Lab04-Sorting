#include "../include/counting_sort.h"

void CountingSort::sort(int arr[], int n) {
    auto start = std::chrono::high_resolution_clock::now();

    int max_num = arr[0];
    for(int i = 0; less(i, n); ++i) {
        if(greater(arr[i], max_num)) {
            max_num = arr[i];
        }
    }

    int* count_arr = new int[max_num + 1]();
    int* sorted_arr = new int[n];
    
    for(int i = 0; less(i, n); ++i) {
        count_arr[arr[i]]++;
    }

    for(int i = 1; less_equal(i, max_num); ++i) {
        count_arr[i] += count_arr[i - 1];
    }

    for(int i = n - 1; greater_equal(i, 0); --i) {
        sorted_arr[count_arr[arr[i]] - 1] = arr[i];
        sorted_arr[arr[i]]--;
    }

    for(int i = 0; less(i, n); ++i) {
        arr[i] = sorted_arr[i];
    }

    delete [] sorted_arr;
    delete [] count_arr;

    auto end = std::chrono::high_resolution_clock::now();
    runtime = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
}