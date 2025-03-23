#include "../include/shaker_sort.h"

void ShakerSort::sort(int arr[], int n) {
    auto start = std::chrono::high_resolution_clock::now();

    int low = 0;
	int high = n - 1;
	int k = 0;
	while(less(low, high)) {
		for(int i = low; less(i, high); ++i) {
			if(greater(arr[i], arr[i + 1])) {
				swap_num(arr[i], arr[i + 1]);
				k = i;
			}
		}

		high = k;

		for(int i = high; greater(i, low); --i) {
			if(less(arr[i], arr[i - 1])) {
				swap_num(arr[i], arr[i - 1]);
				k = i;
			}
		}
        
		low = k;
	}

    auto end = std::chrono::high_resolution_clock::now();
    runtime = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
}