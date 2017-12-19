//
// Created by lcr on 2017/11/3.
//

#ifndef INC_1_MY_QUEUE_H
#define INC_1_MY_QUEUE_H

template <class T>
class queue_node{
private:
    T item;
    queue_node<T>* next;
public:
    queue_node(T n,queue_node<T>* nt= nullptr);
    ~queue_node();
    T get_item();
    void set_item(T n);
    queue_node<T>* get_next();
    void set_next(queue_node<T>* ne);
};

template <class T>
queue_node<T>::queue_node(T n,queue_node* nt) {
    item = n;
    next = nt;
}

template <class T>
queue_node<T>::~queue_node() {}

template <class T>
T queue_node<T>::get_item() {
    return item;
}

template <class T>
void queue_node<T>::set_item(T n) {
    item = n;
}

template <class T>
void queue_node<T>::set_next(queue_node *ne) {
    next = ne;
}

template <class T>
queue_node<T>* queue_node<T>::get_next() {
    return next;
}

template <class T>
class queue{
private:
    int size;
    queue_node<T> *front;
    queue_node<T> *rear;
public:
    queue();
    ~queue();
    bool clear();
    bool en_queue(T item);
    bool de_queue(T &item);
    bool get_front(T &item);
    int get_size();
};

template <class T>
queue<T>::queue() {
    size = 0;
    front = rear = nullptr;
}

template <class T>
queue<T>::~queue() {
    clear();
}

template <class T>
bool queue<T>::clear() {
    if(size==0){
        return true;
    }
    else{
        queue_node<T>* temp = nullptr;
        while(front!=rear){
            temp = front;
            front = front->get_next();
            delete(temp);
        }
        delete(front);
        size = 0;
        return true;
    }
}

template <class T>
bool queue<T>::en_queue(T item) {
    queue_node<T>* new_node = new queue_node<T>(item);
    if(size == 0){
        front = rear = new_node;
    }
    else{
        rear->set_next(new_node);
        rear = rear->get_next();
    }
    size++;
    return true;
}

template <class T>
bool queue<T>::de_queue(T &item) {
    queue_node<T>* temp = nullptr;
    if(size == 0){
        return false;
    }
    else{
        item = front->get_item();
        temp = front;
        front = front->get_next();
        delete temp;
        size--;
        return true;
    }
}

template <class T>
bool queue<T>::get_front(T &item) {
    if(size == 0){
        return false;
    }
    else{
        item = front->get_item();
        return true;
    }
}

template <class T>
int queue<T>::get_size() {
    return size;
}

#endif //INC_1_MY_QUEUE_H
