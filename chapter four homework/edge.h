//
// Created by lcr on 2017/12/7.
//

#ifndef INC_1_EDGE_H
#define INC_1_EDGE_H

#include "baseHeader.h"

template<class T>
class edge {
private:
    int start;
    int end;
    T weight;
public:
    edge(int start, int end, T weight);

    edge();

    ~edge();

    void setStart(int start);

    void setEnd(int end);

    void setWeight(T weight);

    int getStart();

    int getEnd();

    T getWeight();

    bool operator>(edge &other);

    bool operator<(edge &other);

    bool operator==(edge &other);
};


#endif //INC_1_EDGE_H
