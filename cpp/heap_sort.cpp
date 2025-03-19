#include "../include/heap_sort.h"

void HeapSort::heapify(int arr[], int n, int cur) {
    int largest = cur;
    int left = 2 * cur + 1;
    int right = 2 * cur + 2;

    if(less(left, n) && greater(arr[left], arr[largest])) {
        largest = left;
    }

    if(less(right, n) && greater(arr[right], arr[largest])) {
        largest = right;
    }

    if(!equal(largest, cur)) {
        swap_num(arr[cur], arr[largest]);
        heapify(arr, n, largest);
    }
}


void HeapSort::sort(int arr[], int n) {
    auto start = std::chrono::high_resolution_clock::now();

    for(int i = n / 2 - 1; greater_equal(i, 0); i--) {
        heapify(arr, n, i);
    }

    for(int i = n - 1; greater(i, 0); i--) {
        swap_num(arr[0], arr[i]);
        heapify(arr, i, 0);
    }

    auto end = std::chrono::high_resolution_clock::now();
    runtime = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
}
