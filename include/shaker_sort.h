#ifndef SHAKER_SORT_H
#define SHAKER_SORT_H

#include "sort_base.h"

class ShakerSort : public SortBase {
public:
    void sort(int arr[], int n) override;
};

#endif // SHAKER_SORT_H