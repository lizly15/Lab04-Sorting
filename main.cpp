#include "./include/bubble_sort.h"
#include "./include/counting_sort.h"
#include "./include/heap_sort.h"
#include "./include/insertion_sort.h"
#include "./include/merge_sort.h"
#include "./include/quick_sort.h"
#include "./include/radix_sort.h"
#include "./include/selection_sort.h"
#include "./include/shaker_sort.h"
#include "./include/shell_sort.h"
#include "./include/sort_base.h"
#include <iostream>
#include <string>

const string DASH_LINE = "--------------------------------";

void show(SortBase* sort_algo, bool show_runtime = true, bool show_comparisons = true) {
    cout << endl << DASH_LINE << endl;
    if(show_runtime) {
        cout << "Running time: " << sort_algo->runtime << "ms" << endl;
    }
    if(show_comparisons) {
        cout << "Comparisons: " << sort_algo->comparisons << endl;
    }
}

void showCompare(SortBase* sort_algo_1, SortBase* sort_algo_2, bool show_runtime = true, bool show_comparisons = true) {
    cout << endl << DASH_LINE << endl;
    if(show_runtime) {
        cout << "Running time: " << sort_algo_1->runtime << "ms | " << sort_algo_2->runtime << "ms" << endl;
    }
    if(show_comparisons) {
        cout << "Comparisons: " << sort_algo_1->comparisons << " | " << sort_algo_2->runtime << endl;
    }
}

int main()
{
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    SortBase* sort_algo = new MergeSort();
    sort_algo->sort(arr, n);

    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    
    show(sort_algo);

    delete sort_algo;
    return 0;
}