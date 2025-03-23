#include "../include/quick_sort.h"

int QuickSort::partition(int arr[], int low, int high) {
    int mid = low + (high - low) / 2;
    
    // Median-of-Three Pivot Selection
    if (less(arr[mid], arr[low])) swap_num(arr[mid], arr[low]);
    if (less(arr[high], arr[low])) swap_num(arr[high], arr[low]);
    if (less(arr[mid], arr[high])) swap_num(arr[mid], arr[high]);
    
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; less(j, high); ++j) {
        if (less_equal(arr[j], pivot)) {
            ++i;
            swap_num(arr[i], arr[j]);
        }
    }
    
    swap_num(arr[i + 1], arr[high]);
    return i + 1;
}

void QuickSort::quick_sort(int arr[], int low, int high) {
    if (less(low, high)) {
        int mid = partition(arr, low, high);
        quick_sort(arr, low, mid - 1);
        quick_sort(arr, mid + 1, high);
    }
}

void QuickSort::sort(int arr[], int n) {
    auto start = std::chrono::high_resolution_clock::now();
    quick_sort(arr, 0, n - 1);
    auto end = std::chrono::high_resolution_clock::now();
    runtime = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
}