#ifndef QUICK_SORT_H
#define QUICK_SORT_H

#include "sort_base.h"

class QuickSort : public SortBase {
public:
    void sort(int arr[], int n) override;
};

#endif // QUICK_SORT_H