//
// Created by lcr on 2017/11/24.
//
//
//#include <iostream>
//#include "my_queue.h"
//
//using namespace std;
//
//template <class T>
//class binary_search_tree_node{
//private:
//    T item;
//    binary_search_tree_node<T> *left_children;
//    binary_search_tree_node<T> *right_children;
//public:
//    binary_search_tree_node();
//    binary_search_tree_node(T item,binary_search_tree_node<T> *left_children = nullptr,binary_search_tree_node<T> *right_children = nullptr);
//    ~binary_search_tree_node();
//    T get_item();
//    binary_search_tree_node<T>*& get_left_children();
//    binary_search_tree_node<T>*& get_right_children();
//    void set_item(T item);
//    void set_left_children(binary_search_tree_node<T>* left_children);
//    void set_right_children(binary_search_tree_node<T>* right_children);
//};
//
//template <class T>
//binary_search_tree_node<T>::binary_search_tree_node() {
//    item = 0;
//    left_children = right_children =nullptr;
//}
//
//template <class T>
//binary_search_tree_node<T>::binary_search_tree_node(T item, binary_search_tree_node<T> *left_children,
//                                      binary_search_tree_node<T> *right_children):item(item),left_children(left_children),right_children(right_children) {}
//
//template <class T>
//binary_search_tree_node<T>::~binary_search_tree_node() {}
//
//template <class T>
//T binary_search_tree_node<T>::get_item() {
//    return item;
//}
//
//template <class T>
//binary_search_tree_node<T>*& binary_search_tree_node<T>::get_left_children() {
//    return left_children;
//}
//
//template <class T>
//binary_search_tree_node<T>*& binary_search_tree_node<T>::get_right_children() {
//    return right_children;
//}
//
//template <class T>
//void binary_search_tree_node<T>::set_item(T item) {
//    this->item = item;
//}
//
//template <class T>
//void binary_search_tree_node<T>::set_left_children(binary_search_tree_node<T> *left_children) {
//    this->left_children = left_children;
//}
//
//template <class T>
//void binary_search_tree_node<T>::set_right_children(binary_search_tree_node<T> *right_children) {
//    this->right_children = right_children;
//}
//
//template <class T>
//class binary_search_tree{
//private:
//    binary_search_tree_node<T>* root;
//public:
//    binary_search_tree();
//    ~binary_search_tree();
//    binary_search_tree_node<T>* search(T key);
//    bool insert(T in);
//    bool delete_one(T key);
//    void breadth_first_order();//广度优先遍历
//};
//
//template <class T>
//binary_search_tree<T>::binary_search_tree() {
//    root = 0;
//}
//
//template <class T>
//binary_search_tree<T>::~binary_search_tree() {
//    queue<binary_search_tree_node<T>*> binary_search_tree_node_queue;
//    binary_search_tree_node_queue.en_queue(root);
//    binary_search_tree_node<T>* temp;
//    while(!binary_search_tree_node_queue.get_size()){
//        binary_search_tree_node_queue.de_queue(temp);
//        if(temp->get_left_children()){
//            binary_search_tree_node_queue.en_queue(temp->get_left_children());
//        }
//        if(temp->get_right_children()){
//            binary_search_tree_node_queue.en_queue(temp->get_right_children());
//        }
//        delete temp;
//    }
//}
//
//template <class T>
//binary_search_tree_node<T>* binary_search_tree<T>::search(T key) {
//    binary_search_tree_node<T>* temp = root;
//    while(temp){
//        if(temp->get_item()>key){
//            temp = temp->get_left_children();
//        }
//        else if(temp->get_item() < key){
//            temp = temp->get_right_children();
//        }
//        else{
//            return temp;
//        }
//    }
//    return nullptr;
//}
//
//template <class T>
//bool binary_search_tree<T>::insert(T in) {
//    binary_search_tree_node<T>* temp = root;
//    if(root == nullptr){
//        root = new binary_search_tree_node<T>;
//        root->set_item(in);
//    }
//    else{
//        while(1){
//            if(temp->get_item()>in){
//                if(temp->get_left_children()){
//                    temp = temp->get_left_children();
//                }
//                else{
//                    temp->set_left_children(new binary_search_tree_node<T>(in));
//                    return true;
//                }
//            }
//            else{
//                if(temp->get_right_children()){
//                    temp = temp->get_right_children();
//                }
//                else{
//                    temp->set_right_children(new binary_search_tree_node<T>(in));
//                    return true;
//                }
//            }
//        }
//    }
//    return false;
//}
//
//template <class T>
//bool binary_search_tree<T>::delete_one(T key) {
//    binary_search_tree_node<T>* temp = root, *pre = nullptr , *r = nullptr;
//    while(temp->get_item() != key){
//        if(temp->get_item() > key){
//            pre = temp;
//            temp = temp->get_left_children();
//        }
//        else{
//            pre = temp;
//            temp = temp->get_right_children();
//        }
//    }
//    if(!temp->get_left_children() && !temp->get_right_children()){
//        if(temp == pre->get_left_children()){
//            pre->set_left_children(nullptr);
//        }
//        else{
//            pre->set_right_children(nullptr);
//        }
//        delete temp;
//    }
//    else if(temp->get_left_children() && temp->get_right_children()){
//        r = temp->get_left_children(),pre = temp;
//        while(r->get_right_children()){
//            pre = r;
//            r = r->get_right_children();
//        }
//        temp->set_item(r->get_item());
//        if(r->get_left_children()){
//            pre->set_right_children(r->get_left_children());
//        }
//        else{
//            pre->set_right_children(nullptr);
//            delete r;
//        }
//    }
//    else{
//        if(temp->get_left_children()){
//            if(temp == pre->get_left_children()){
//                pre->set_left_children(temp->get_left_children());
//            }
//            else{
//                pre->set_right_children(temp->get_left_children());
//            }
//        }
//        else{
//            if(temp == pre->get_left_children()){
//                pre->set_left_children(temp->get_right_children());
//            }
//            else{
//                pre->set_right_children(temp->get_right_children());
//            }
//        }
//    }
//}
//
//template <class T>
//void binary_search_tree<T>::breadth_first_order() {
//    queue<binary_search_tree_node<T>*> binary_search_tree_node_queue;
//    binary_search_tree_node_queue.en_queue(root);
//    binary_search_tree_node<T>* temp;
//    while(binary_search_tree_node_queue.get_size()){
//        binary_search_tree_node_queue.de_queue(temp);
//        cout<<temp->get_item()<<" ";
//        if(temp->get_left_children()){
//            binary_search_tree_node_queue.en_queue(temp->get_left_children());
//        }
//        if(temp->get_right_children()){
//            binary_search_tree_node_queue.en_queue(temp->get_right_children());
//        }
//    }
//    cout<<endl;
//}
//
//int main(){
//    binary_search_tree<int> tree;
//    int n;
//    while(1){
//        cout<<"please input a number(end with -1):";
//        cin>>n;
//        if(n==-1){
//            break;
//        }
//        else{
//            tree.insert(n);
//        }
//    }
//    tree.breadth_first_order();
//    cout<<"请输入查找的值：";
//    int i;
//    cin>>i;
//    cout<<tree.search(i)->get_item()<<endl;
//    cout<<"请输入删除的值：";
//    cin>>i;
//    tree.delete_one(i);
//    tree.breadth_first_order();
//    system("pause");
//    return 0;
//}