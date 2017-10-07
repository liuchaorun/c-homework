#include <iostream>
#include <string>

using namespace std;

template<class T>
class stack {
private:
    T *s;
    int top;
    int max_length;
public:
    stack(int size=1);

    ~stack();

    bool clear();

    bool push(T element);

    bool Top(T &element);

    bool pop(T &element);

    bool isEmpty();

    bool isFull();
};

template<class T>
stack<T>::stack(int size) {
    top = -1;
    max_length = size;
    s = new T[size];
}

template <class T>
stack<T>::~stack() {
    delete s;
}

template <class T>
bool stack<T>::clear() {
    top = -1;
}

template <class T>
bool stack<T>::isEmpty() {
    if(top==-1){
        return true;
    }
    else{
        return false;
    }
}

template <class T>
bool stack<T>::isFull() {
    if(top==max_length-1){
        return true;
    }
    else{
        return false;
    }
}

template <class T>
bool stack<T>::push(T element) {
    if(isFull()){
        T* old = s;
        s =new T[max_length*2];
        for(int i=0;i<max_length;++i){
            s[i]=old[i];
        }
        max_length*=2;
        s[++top] = element;
        delete old;
        return true;
    }
    else{
        s[++top] = element;
        return true;
    }
}

template <class T>
bool stack<T>::Top(T &element) {
    if(isEmpty()){
        return false;
    }
    else{
        element = s[top];
        return true;
    }
}

template <class T>
bool stack<T>::pop(T &element) {
    if(isEmpty()){
        return false;
    }
    else{
        element = s[top--];
        return true;
    }
}

class check{
private:
    stack* c;
};

int main(){
    return 0;
}