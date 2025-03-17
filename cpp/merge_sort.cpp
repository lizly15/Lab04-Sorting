#include "../include/merge_sort.h"

void MergeSort::merge(int arr[], int l, int m, int r) {
    int left_len = m - l + 1;
    int* left_arr = new int[left_len];
    for (int i = 0; less(i, left_len); i++) {
        left_arr[i] = arr[l + i];
    }

    int right_len = r - m;
    int* right_arr = new int[right_len];
    for (int i = 0; less(i, right_len); i++) {
        right_arr[i] = arr[m + 1 + i];
    }

    int left_cur = 0, right_cur = 0;
    while(less(left_cur, left_len) && less(right_cur, right_len)) {
        if (less_equal(left_arr[left_cur], right_arr[right_cur])) {
            arr[l++] = left_arr[left_cur++];
        } else {
            arr[l++] = right_arr[right_cur++];
        }
    }

    while (less(left_cur, left_len)) {
        arr[l++] = left_arr[left_cur++];
    }

    while (less(right_cur, right_len)) {
        arr[l++] = right_arr[right_cur++];
    }
}

void MergeSort::merge_sort(int arr[], int l, int r) {
    if (greater_equal(l, r)) {
        return;
    }
    int m = (l + r) / 2;
    merge_sort(arr, l, m);
    merge_sort(arr, m + 1, r);
    merge(arr, l, m, r);
}

void MergeSort::sort(int arr[], int n) {
    auto start = std::chrono::high_resolution_clock::now();
    merge_sort(arr, 0, n - 1);
    auto end = std::chrono::high_resolution_clock::now();
    runtime = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
}