//
// Created by lcr on 2017/12/7.
//

#ifndef INC_1_MINHEAP_H
#define INC_1_MINHEAP_H

#include "baseHeader.h"

template<class T>
class minHeap {
private:
    T *heapArray;
    int currentSize;
    int maxSize;
public:
    explicit minHeap(int size = 10);

    minHeap(T *array, int size);

    ~minHeap();

    int chooseMin(int i);

    void init();

    T minOne();

    bool deleteMinOne();
};

#endif //INC_1_MINHEAP_H
