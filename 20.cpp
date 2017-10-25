//#include <iostream>
//
//using namespace std;
//
//template <class T>
//class link_node{
//private:
//    T item;
//    link_node<T>* next;
//public:
//    link_node(T n,link_node<T>* nt= nullptr);
//    T get_item();
//    void set_item(T n);
//    link_node<T>* get_next();
//    void set_next(link_node<T>* ne);
//};
//
//template <class T>
//link_node<T>::link_node(T n,link_node* nt) {
//    item = n;
//    next = nt;
//}
//
//template <class T>
//T link_node<T>::get_item() {
//    return item;
//}
//
//template <class T>
//void link_node<T>::set_item(T n) {
//    item = n;
//}
//
//template <class T>
//void link_node<T>::set_next(link_node *ne) {
//    next = ne;
//}
//
//template <class T>
//link_node<T>* link_node<T>::get_next() {
//    return next;
//}
//
//template <class T>
//class queue{
//private:
//    int size;
//    link_node<T> *front;
//    link_node<T> *rear;
//public:
//    queue();
//    ~queue();
//    bool clear();
//    bool en_queue(T item);
//    bool de_queue(T &item);
//    bool get_front(T &item);
//    int get_size();
//};
//
//template <class T>
//queue<T>::queue() {
//    size = 0;
//    front = rear = nullptr;
//}
//
//template <class T>
//queue<T>::~queue() {
//    //clear();
//}
//
//template <class T>
//bool queue<T>::clear() {
//    link_node<T>* temp = nullptr;
//    while(front!=rear){
//        temp = front;
//        front = front->get_next();
//        delete temp;
//    }
//    delete front;
//    size = 0;
//    return true;
//}
//
//template <class T>
//bool queue<T>::en_queue(T item) {
//    link_node<T>* new_node = new link_node<T>(item);
//    if(size == 0){
//        front = rear = new_node;
//    }
//    else{
//        rear->set_next(new_node);
//        rear = rear->get_next();
//    }
//    size++;
//    return true;
//}
//
//template <class T>
//bool queue<T>::de_queue(T &item) {
//    link_node<T>* temp = nullptr;
//    if(size == 0){
//        return false;
//    }
//    else{
//        item = front->get_item();
//        temp = front;
//        front = front->get_next();
//        delete temp;
//        size--;
//        return true;
//    }
//}
//
//template <class T>
//bool queue<T>::get_front(T &item) {
//    if(size == 0){
//        return false;
//    }
//    else{
//        item = front->get_item();
//        return true;
//    }
//}
//
//template <class T>
//int queue<T>::get_size() {
//    return size;
//}
//
//int main(){
//    queue<int> s;
//    s.en_queue(0);
//    s.en_queue(1);
//    s.en_queue(1);
//    s.en_queue(0);
//    cout<<"please inpiut the number:";
//    int n;
//    cin>>n;
//    for(int i = 1;i<n;++i){
//        int j,temp;
//        do{
//            s.de_queue(j);
//            s.get_front(temp);
//            s.en_queue(j+temp);
//            cout<<temp<<" ";
//        }while(temp!=0);
//        s.en_queue(0);
//        cout<<endl;
//    }
//    s.de_queue(n);
//    s.de_queue(n);
//    while(n!=0){
//        cout<<n<<" ";
//        s.de_queue(n);
//    }
//    return 0;
//}