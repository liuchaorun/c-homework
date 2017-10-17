//#include <iostream>
//
//using namespace std;
//
//template<class T>
//class queue {
//private:
//    bool tag;
//    int max_size;
//    int front;
//    int rear;
//    T *q;
//public:
//    queue(int size);
//
//    ~queue();
//
//    void clear();                  //清空队列
//    bool en_queue(T item);         //队列的尾部加入元素
//    bool de_queue(T &item);        //取出队列的第一个元素
//    bool is_empty();               //判断队列是否为空
//    bool is_full();                //判断队列是否已满
//    bool get_front(T &item);       //读取队头元素但不删除
//};
//
//template <class T>
//queue<T>::queue(int size) {
//    tag = false;
//    max_size = size;
//    front = 0;
//    rear = 0;
//    q = new T[max_size+1];
//}
//
//template <class T>
//queue<T>::~queue() {
//    delete q;
//}
//
//template <class T>
//void queue<T>::clear() {
//    tag = false;
//    front = 0;
//    rear = 0;
//}
//
//template <class T>
//bool queue<T>::en_queue(T item) {
//    if(is_full()){
//        return false;
//    }
//    else{
//        q[rear] = item;
//        rear = (rear + 1) % max_size;
//        tag = 1;
//        return true;
//    }
//}
//
//template <class T>
//bool queue<T>::de_queue(T &item) {
//    if(is_empty()){
//        return false;
//    }
//    else{
//        item = q[front];
//        front = (front + 1) % max_size;
//        if(front == rear){
//            tag = 0;
//        }
//        return true;
//    }
//}
//
//template <class T>
//bool queue<T>::is_empty() {
//    return tag==0;
//}
//
//template <class T>
//bool queue<T>::is_full() {
//    if(tag==0){
//        return false;
//    }
//    else{
//        return front == rear;
//    }
//}
//
//template <class T>
//bool queue<T>::get_front(T &item) {
//    if(is_empty()){
//        return false;
//    }
//    else{
//        item = q[front];
//        return true;
//    }
//}
//
//int main(){
//    queue<int> queue1(10);
//    for (int i = 0; i < 10; ++i) {
//        queue1.en_queue(i);
//    }
//    for (int j = 0; j <10 ; ++j) {
//        queue1.de_queue(j);
//        cout<<j<<" ";
//    }
//    for (int i = 0; i < 1; ++i) {
//        queue1.en_queue(i);
//    }
//    for (int j = 0; j <1 ; ++j) {
//        queue1.de_queue(j);
//        cout<<j<<" ";
//    }
//    int i;
//    cout<<queue1.de_queue(i);
//    return 0;
//}