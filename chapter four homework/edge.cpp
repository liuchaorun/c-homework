//
// Created by lcr on 2017/12/7.
//

#include "edge.h"

template<class T>
edge<T>::edge(int start, int end, T weight):start(start), end(end), weight(weight) {}

template <class T>
edge<T>::edge()=default;

template<class T>
edge<T>::~edge()= default;

template<class T>
void edge<T>::setStart(int start) {
    this->start = start;
}

template<class T>
void edge<T>::setEnd(int end) {
    this->end = end;
}

template<class T>
void edge<T>::setWeight(T weight) {
    this->weight = weight;
}

template<class T>
int edge<T>::getStart() {
    return start;
}

template<class T>
int edge<T>::getEnd() {
    return end;
}

template<class T>
T edge<T>::getWeight() {
    return weight;
}

template<class T>
bool edge<T>::operator>(edge &other) {
    return weight > other.getWeight();
}

template<class T>
bool edge<T>::operator<(edge &other) {
    return weight < other.getWeight();
}

template<class T>
bool edge<T>::operator==(edge &other) {
    return weight == other.getWeight();
}

template <class T>
bool edge<T>::operator<=(edge &other) {
    return weight<=other.getWeight();
}

template <class T>
bool edge<T>::operator>=(edge &other) {
    return weight>=other.getWeight();
}

template <class T>
ostream& operator<<(ostream& out,edge<T>& obj){
    return out<<"这条边的起点是"<<obj.getStart()<<",终点是"<<obj.getEnd()<<"，权重为"<<obj.getWeight()<<endl;
}

template <class T>
istream& operator>>(istream& in,edge<T>& obj){
    int a,b;
    T c;
    in>>a>>b>>c;
    obj.setStart(a);
    obj.setEnd(b);
    obj.setWeight(c);
    return in;
}