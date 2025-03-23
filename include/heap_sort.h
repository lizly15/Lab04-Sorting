#ifndef HEAP_SORT_H
#define HEAP_SORT_H

#include "sort_base.h"

class HeapSort : public SortBase {
private:
    void heapify(int arr[], int n, int i);
public:
    void sort(int arr[], int n) override;
};

#endif // HEAP_SORT_H