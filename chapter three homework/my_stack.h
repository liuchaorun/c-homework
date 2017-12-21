//
// Created by lcr on 2017/11/3.
//

#ifndef INC_1_MY_STACK_H
#define INC_1_MY_STACK_H
template <class T>
class link_node{
private:
    T item;
    link_node<T>* next;
public:
    link_node();
    link_node(T n,link_node<T>* nt= nullptr);
    ~link_node();
    T get_item();
    void set_item(T n);
    link_node<T>* get_next();
    void set_next(link_node<T>* ne);
};

template <class T>
link_node<T>::link_node() {
    item = nullptr;
    next = nullptr;
}

template <class T>
link_node<T>::link_node(T n,link_node* nt) {
    item = n;
    next = nt;
}

template <class T>
link_node<T>::~link_node() {}

template <class T>
T link_node<T>::get_item() {
    return item;
}

template <class T>
void link_node<T>::set_item(T n) {
    item = n;
}

template <class T>
void link_node<T>::set_next(link_node *ne) {
    next = ne;
}

template <class T>
link_node<T>* link_node<T>::get_next() {
    return next;
}

template<class T>
class stack {
private:
    link_node<T> *stack_top;
    int max_length;
public:
    stack();

    ~stack();

    bool clear();

    bool push(T element);

    bool Top(T &element);

    bool pop(T &element);

    bool is_empty();

    int get_size();
};

template <class T>
stack<T>::stack():stack_top(nullptr) {
    max_length = 0;
}

template <class T>
stack<T>::~stack() {
    clear();
}

template <class T>
bool stack<T>::clear() {
    link_node<T> *temp = stack_top;
    while(stack_top){
        temp = stack_top;
        stack_top = stack_top->get_next();
        delete temp;
    }
    max_length = 0;
    return true;
}

template <class T>
bool stack<T>::push(T element) {
    link_node<T> *temp = new link_node<T>(element);
    if(is_empty()){
        stack_top = temp;
    }
    else{
        temp->set_next(stack_top);
        stack_top = temp;
    }
    max_length++;
    return true;
}

template <class T>
bool stack<T>::Top(T &element) {
    if(is_empty()){
        return false;
    }
    else{
        element = stack_top->get_item();
        return true;
    }
}

template <class T>
bool stack<T>::pop(T &element) {
    if(is_empty()){
        return false;
    }
    else{
        max_length--;
        element = stack_top->get_item();
        link_node<T> *temp = stack_top;
        stack_top = stack_top->get_next();
        delete temp;
        return true;
    }
}

template <class T>
bool stack<T>::is_empty() {
    return stack_top == nullptr;
}

template <class T>
int stack<T>::get_size() {
    return max_length;
}

#endif //INC_1_MY_STACK_H
