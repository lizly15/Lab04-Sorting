#ifndef RADIX_SORT_H
#define RADIX_SORT_H

#include "sort_base.h"

class RadixSort : public SortBase {
public:
    void sort(int arr[], int n) override;
};

#endif // RADIX_SORT_H