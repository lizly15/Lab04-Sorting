#ifndef QUICK_SORT_H
#define QUICK_SORT_H

#include "sort_base.h"

class QuickSort : public SortBase {
private:
    int partition(int arr[], int low, int high);
    void quick_sort(int arr[], int low, int high);
    
public:
    void sort(int arr[], int n) override;
};

#endif // QUICK_SORT_H