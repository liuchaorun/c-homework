//#include <iostream>
//
//using namespace std;
//
//template<class T>
//class queue {
//private:
//    int max_size;
//    int front;
//    int rear;
//    T *q;
//public:
//    queue(int size);
//
//    ~queue();
//
//    void clear();                  //��ն���
//    bool en_queue(T item);   //���е�β������Ԫ��
//    bool de_queue(T &item);        //ȡ�����еĵ�һ��Ԫ��
//    bool is_empty();               //�ж϶����Ƿ�Ϊ��
//    bool is_full();                //�ж϶����Ƿ�����
//    bool get_front(T &item);       //��ȡ��ͷԪ�ص���ɾ��
//};
//
//template <class T>
//queue<T>::queue(int size) {
//    max_size = size+1;
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
//        return true;
//    }
//}
//
//template <class T>
//bool queue<T>::is_empty() {
//    return front==rear;
//}
//
//template <class T>
//bool queue<T>::is_full() {
//    return (rear + 1) % max_size == front;
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
//    queue<int> t(10);
//    for(int i =0; i <10;++i){
//        cout<<t.en_queue(i)<<endl;
//    }
//    int n;
//    for (int j = 0; j < 10 ; ++j) {
//        t.de_queue(n);
//        cout<<n<<" ";
//    }
//    return 0;
//}
//
