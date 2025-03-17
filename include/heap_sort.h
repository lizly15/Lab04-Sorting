#ifndef HEAP_SORT_H
#define HEAP_SORT_H

#include "sort_base.h"

class HeapSort : public SortBase {
public:
    void sort(int arr[], int n) override;
};

#endif // HEAP_SORT_H