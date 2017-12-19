//
// Created by lcr on 17-12-13.
//

#ifndef INC_1_UFSET_H
#define INC_1_UFSET_H


class UFSet {
private:
    int n;
    int *root;
    int *next;
    int *length;
public:
    UFSet(int n = 10);
    ~UFSet();
    int Find(int i);
    bool Union(int i, int j);
    bool isOne();
};


#endif //INC_1_UFSET_H
