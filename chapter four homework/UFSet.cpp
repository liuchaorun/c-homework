//
// Created by lcr on 17-12-13.
//

#include "UFSet.h"

UFSet::UFSet(int n):n(n) {
    root = new int[n];
    next = new int[n];
    length = new int [n];
    for (int i = 0; i < n; ++i) {
        root[i] = i;
        next[i] = i;
        length[i] = 1;
    }
}

UFSet::~UFSet() {
    delete[] root;
    delete[] next;
    delete[] length;
}

int UFSet::Find(int i) {
    return root[i];
}

bool UFSet::Union(int i, int j) {
    if(root[i] == root[j]){
        return true;
    }
    i = root[i];
    j = root[j];
    if(length[i] < length[j]){
        for (int k = 0; k < n; ++k) {
            if(root[k] == i){
                root[k] = j;
            }
        }
        length[j] += length[i];
    }
    else{
        for (int k = 0; k < n; ++k) {
            if(root[k] == j){
                root[k] = i;
            }
        }
        length[i] += length[j];
    }
    int temp = next[i];
    next[i] = next[j];
    next[j] = temp;
    return true;
}

bool UFSet::isOne() {
    for (int i = 1; i < n; ++i) {
        if(root[i] != root[0]){
            return false;
        }
    }
    return true;
}