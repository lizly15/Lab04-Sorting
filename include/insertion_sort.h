#ifndef INSERTION_SORT_H
#define INSERTION_SORT_H

#include "sort_base.h"

class InsertionSort : public SortBase {
public:
    void sort(int arr[], int n) override;
};

#endif // INSERTION_SORT_H