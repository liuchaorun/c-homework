//
// Created by lcr on 2017/12/7.
//

#include "minHeap.h"

template<class T>
minHeap<T>::minHeap(int size) {
    heapArray = new T[size];
    currentSize = 0;
    maxSize = size;
}

template<class T>
minHeap<T>::minHeap(T *array, int size) {
    heapArray = array;
    currentSize = size;
    maxSize = size;
}

template<class T>
minHeap<T>::~minHeap() {
    delete[](heapArray);
}

template<class T>
int minHeap<T>::chooseMax(int i) {
    int temp = 0;
    if (2 * i + 2 < currentSize - 1) {
        if (heapArray[i] >= heapArray[2 * i + 1] && heapArray[2 * i + 1] <= heapArray[2 * i + 2]) {
            temp = heapArray[i];
            heapArray[i] = heapArray[2 * i + 1];
            heapArray[2 * i + 1] = temp;
            return 1;
        } else if (heapArray[i] >= heapArray[2 * i + 2] && heapArray[2 * i + 1] >= heapArray[2 * i + 2]) {
            temp = heapArray[i];
            heapArray[i] = heapArray[2 * i + 2];
            heapArray[2 * i + 2] = temp;
            return 2;
        }
    } else {
        if (heapArray[2 * i + 1] < heapArray[i]) {
            temp = heapArray[i];
            heapArray[i] = heapArray[2 * i + 1];
            heapArray[2 * i + 1] = temp;
            return 1;
        }
    }
    return 0;
}

template<class T>
void minHeap<T>::init() {
    int j = 0;
    for (int i = (currentSize - 2) / 2; i >= 0; i--) {
        j = i;
        int flag = chooseMax(j);
        while (flag) {
            if (flag == 1) {
                j = 2 * j + 1;
            } else {
                j = 2 * j + 2;
            }
            if (j > (currentSize - 2) / 2) {
                break;
            }
            flag = chooseMax(j);
        }
    }
}

template<class T>
bool minHeap<T>::insert(T in) {
    if (currentSize == maxSize) {
        T *new_array = new T[maxSize * 2];
        for (int i = 0; i < maxSize; ++i) {
            new_array[i] = heapArray[i];
        }
        maxSize *= 2;
        delete[](heapArray);
        heapArray = new_array;
    }
    heapArray[currentSize] = in;
    currentSize++;
    for (int i = currentSize - 1; (i - 1) / 2 >= 0; i = (i - 1) / 2) {
        if (heapArray[i] < heapArray[(i - 1) / 2]) {
            int temp = heapArray[i];
            heapArray[i] = heapArray[(i - 1) / 2];
            heapArray[(i - 1) / 2] = temp;
        } else {
            break;
        }
    }
}

template<class T>
bool minHeap<T>::deleteOne(T key) {
    int p = 0;
    for (; p < currentSize; ++p) {
        if (heapArray[p] == key) {
            break;
        }
    }
    int temp = heapArray[p];
    heapArray[p] = heapArray[currentSize - 1];
    heapArray[currentSize - 1] = temp;
    currentSize--;
    int j = p;
    int flag = chooseMax(j);
    while (flag) {
        if (flag == 1) {
            j = 2 * j + 1;
        } else {
            j = 2 * j + 2;
        }
        if (j > (currentSize - 2) / 2) {
            break;
        }
        flag = chooseMax(j);
    }
    for (int i = currentSize - 1; (i - 1) / 2 >= 0; i = (i - 1) / 2) {
        if (heapArray[i] < heapArray[(i - 1) / 2]) {
            int temp = heapArray[i];
            heapArray[i] = heapArray[(i - 1) / 2];
            heapArray[(i - 1) / 2] = temp;
        } else {
            break;
        }
    }
}