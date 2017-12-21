//
// Created by lcr on 17-12-21.
//

#include <iostream>
#define N 10

using namespace std;

template <class T>
void insertSort(T* array, int n){
    for (int i = 1; i < n; ++i) {
        int min = i;
        for (int j = min + 1; j < n; ++j) {
            if(array[j] < array[min]){
                min = j;
            }
        }
        int temp = array[i];
        array[i] = array[min];
        array[min] = temp;
    }
}

template <class T>
void binaryInsertSort(T* array, int n){
    for (int i = 1; i < n; ++i) {

    }
}

int main(){
    int *array = new int[N];
}