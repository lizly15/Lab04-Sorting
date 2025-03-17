#ifndef SORT_BASE_H
#define SORT_BASE_H

#include <iostream> 
#include <algorithm>
#include <chrono>

using namespace std;

class SortBase {
protected:
    bool less(int a, int b) {
        comparisons++;
        return a < b;
    }
    bool less_equal(int a, int b) {
        comparisons++;
        return a <= b;
    }
    bool equal(int a, int b) {
        comparisons++;
        return a == b;
    }
    bool greater(int a, int b) {
        comparisons++;
        return a > b;
    }
    bool greater_equal(int a, int b) {
        comparisons++;
        return a >= b;
    }
public:
    // runtime in milliseconds
    long long runtime = 0;
    // number of comparisons
    long long comparisons = 0;

    virtual void sort(int arr[], int n) = 0;
    
    virtual ~SortBase() {}
};

#endif // SORT_BASE_H