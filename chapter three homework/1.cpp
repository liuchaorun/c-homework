//
// Created by lcr on 2017/11/3.
//
#include<iostream>
#include "my_stack.h"
#include "my_queue.h"

using namespace std;

template <class T>
class binary_tree_node{
private:
    T item;
    binary_tree_node<T> *left_children;
    binary_tree_node<T> *right_children;
public:
    binary_tree_node();
    binary_tree_node(T item,binary_tree_node<T> *left_children = nullptr,binary_tree_node<T> *right_children = nullptr);
    ~binary_tree_node();
    T get_item();
    binary_tree_node<T>* get_left_children();
    binary_tree_node<T>* get_right_children();
    void set_item(T item);
    void set_left_children(binary_tree_node<T>* left_children);
    void set_right_children(binary_tree_node<T>* right_children);
};

template <class T>
binary_tree_node<T>::binary_tree_node() {
    item = 0;
    left_children = right_children =nullptr;
}

template <class T>
binary_tree_node<T>::binary_tree_node(T item, binary_tree_node<T> *left_children,
                                      binary_tree_node<T> *right_children):item(item),left_children(left_children),right_children(right_children) {}

template <class T>
binary_tree_node<T>::~binary_tree_node() {}

template <class T>
T binary_tree_node<T>::get_item() {
    return item;
}

template <class T>
binary_tree_node<T>* binary_tree_node<T>::get_left_children() {
    return left_children;
}

template <class T>
binary_tree_node<T>* binary_tree_node<T>::get_right_children() {
    return right_children;
}

template <class T>
void binary_tree_node<T>::set_item(T item) {
    this->item = item;
}

template <class T>
void binary_tree_node<T>::set_left_children(binary_tree_node<T> *left_children) {
    this->left_children = left_children;
}

template <class T>
void binary_tree_node<T>::set_right_children(binary_tree_node<T> *right_children) {
    this->right_children = right_children;
}

template <class T>
class binary_tree{
private:
    binary_tree_node<T> *root;
public:
    binary_tree();
    ~binary_tree();
    bool is_empty();
    binary_tree_node<T>* get_root();
    void create_binary_tree(T* a);
    void breadth_first_order();//广度优先遍历
    void pre_order();//前序深度优先遍历
    void pre_order(binary_tree_node<T> *temp);//前序深度优先遍历 递归
};

template <class T>
binary_tree<T>::binary_tree() {
    root = nullptr;
}

template <class T>
binary_tree<T>::~binary_tree() {
    if(!is_empty()){
        queue<binary_tree_node<T>*> binary_tree_node_queue;
        binary_tree_node_queue.en_queue(root);
        binary_tree_node<T> *temp;
        while(binary_tree_node_queue.get_size()==0){
            binary_tree_node_queue.de_queue(temp);
            if(temp->get_left_children()){
                binary_tree_node_queue.en_queue(temp->get_left_children());
            }
            if(temp->get_right_children()){
                binary_tree_node_queue.en_queue(temp->get_right_children());
            }
            delete(temp);
        }
    }
}

template <class T>
bool binary_tree<T>::is_empty() {
    return root == nullptr;
}

template <class T>
binary_tree_node<T>* binary_tree<T>::get_root() {
    return root;
}

template <class T>
void binary_tree<T>::create_binary_tree(T* a) {
    binary_tree_node<T>* node = new binary_tree_node<T>[10];
    for(int i = 0;i <10;++i){
        node[i].set_item(a[i]);
    }
    root = &node[0];
    root->set_left_children(&node[1]);
    root->set_right_children(&node[2]);
    node[1].set_left_children(&node[3]);
    node[1].set_right_children(&node[4]);
    node[2].set_left_children(&node[5]);
    node[3].set_right_children(&node[6]);
    node[4].set_left_children(&node[7]);
    node[5].set_left_children(&node[8]);
    node[5].set_right_children(&node[9]);
}

template <class T>
void binary_tree<T>::breadth_first_order() {
    if(!is_empty()){
        queue<binary_tree_node<T>*> binary_tree_node_queue;
        binary_tree_node_queue.en_queue(root);
        binary_tree_node<T> *temp;
        while(binary_tree_node_queue.get_size()!=0){
            binary_tree_node_queue.de_queue(temp);
            cout<<temp->get_item()<<" ";
            if(temp->get_left_children()){
                binary_tree_node_queue.en_queue(temp->get_left_children());
            }
            if(temp->get_right_children()){
                binary_tree_node_queue.en_queue(temp->get_right_children());
            }
        }
        cout<<endl;
    }
}

template <class T>
void binary_tree<T>::pre_order() {
    if(!is_empty()){
        stack<binary_tree_node<T>*> binary_tree_node_stack;
        binary_tree_node<T> *temp = root;
        while(!binary_tree_node_stack.is_empty() || temp){
            if(temp){
                cout<<temp->get_item()<<" ";
                if(temp->get_right_children()){
                    binary_tree_node_stack.push(temp->get_right_children());
                }
                temp = temp->get_left_children();
            }
            else{
                binary_tree_node_stack.pop(temp);
            }
        }
        cout<<endl;
    }
}

template <class T>
void binary_tree<T>::pre_order(binary_tree_node<T> *temp) {
    if(temp){
        cout<<temp->get_item()<<" ";
        pre_order(temp->get_left_children());
        pre_order(temp->get_right_children());
    }
}

int main(){
    binary_tree<char> tree;
    char *a;
    a = new char[10];
    for(int i=0;i<10;++i){
        //a[i] = 'A' + i;
        cin>>a[i];
    }
    tree.create_binary_tree(a);
    tree.breadth_first_order();
    tree.pre_order();
    tree.pre_order(tree.get_root());
    return 0;
}