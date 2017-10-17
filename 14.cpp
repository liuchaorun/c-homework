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
//    link_node(T n,link_node<T>* nt=0);
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
//    bool en_queue(T iteam);
//    bool de_queue(T &item);
//    bool get_front(T &item);
//    int get_size();
//    void show();
//};
//
//template <class T>
//queue<T>::queue() {
//    size = 0;
//    front = rear = 0;
//}
//
//template <class T>
//queue<T>::~queue() {
//    //clear();
//}
//
//template <class T>
//bool queue<T>::clear() {
//    link_node<T>* temp = 0;
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
//    link_node<T>* temp = 0;
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
//template <class T>
//void queue<T>::show() {
//    link_node<T>* temp = front;
//    while(temp != rear){
//        cout<<temp->get_item()<<endl;
//        temp = temp->get_next();
//    }
//    cout<<temp->get_item()<<endl;
//}
//
//template <class T>
//class link_list{
//private:
//    link_node<T>* head;
//    link_node<T>* tail;
//public:
//    link_list();
//    ~link_list();
//    bool add(T& item);
//    void show();
//};
//
//template <class T>
//link_list<T>::link_list() {
//    head = tail = 0;
//}
//
//template <class T>
//link_list<T>::~link_list() {
//    while(head){
//        tail = head;
//        head = head->get_next();
//        delete tail;
//    }
//}
//
//template <class T>
//bool link_list<T>::add(T& item) {
//    link_node<T>* new_node = new link_node<T>(item);
//    if(!head){
//        head = tail = new_node;
//    }
//    else{
//        tail->set_next(new_node);
//        tail = tail->get_next();
//    }
//    return true;
//}
//
//template <class T>
//void link_list<T>::show() {
//    link_node<T>* temp = head;
//    while(temp){
//        (temp->get_item()).show();
//        temp = temp->get_next();
//    }
//}
//
//int main(){
//    queue<int> number[10];
//    link_list<queue<int>> queue_list;
//    int n;
//    cout<<"please input a number(0<=i<=9):";
//    cin>>n;
//    while(n>=0&&n<=9){
//        number[n].en_queue(n);
//        cout<<"please input a number(0<=i<=9):";
//        cin>>n;
//    }
//    for (int i = 0; i < 10; ++i) {
//        if(number[i].get_size()){
//            queue_list.add(number[i]);
//        }
//    }
//   queue_list.show();
//    return 0;
//}