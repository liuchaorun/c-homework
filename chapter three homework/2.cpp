//#include<iostream>
//#include "my_stack.h"
//#include "my_queue.h"
//
//using namespace std;
//
//template <class T>
//class binary_tree_node{
//private:
//    T item;
//    binary_tree_node<T> *left_children;
//    binary_tree_node<T> *right_children;
//public:
//    binary_tree_node();
//    binary_tree_node(T item,binary_tree_node<T> *left_children = nullptr,binary_tree_node<T> *right_children = nullptr);
//    ~binary_tree_node();
//    T get_item();
//    binary_tree_node<T>*& get_left_children();
//    binary_tree_node<T>*& get_right_children();
//    void set_item(T item);
//    void set_left_children(binary_tree_node<T>* left_children);
//    void set_right_children(binary_tree_node<T>* right_children);
//};
//
//template <class T>
//binary_tree_node<T>::binary_tree_node() {
//    item = 0;
//    left_children = right_children =nullptr;
//}
//
//template <class T>
//binary_tree_node<T>::binary_tree_node(T item, binary_tree_node<T> *left_children,
//                                      binary_tree_node<T> *right_children):item(item),left_children(left_children),right_children(right_children) {}
//
//template <class T>
//binary_tree_node<T>::~binary_tree_node() {}
//
//template <class T>
//T binary_tree_node<T>::get_item() {
//    return item;
//}
//
//template <class T>
//binary_tree_node<T>*& binary_tree_node<T>::get_left_children() {
//    return left_children;
//}
//
//template <class T>
//binary_tree_node<T>*& binary_tree_node<T>::get_right_children() {
//    return right_children;
//}
//
//template <class T>
//void binary_tree_node<T>::set_item(T item) {
//    this->item = item;
//}
//
//template <class T>
//void binary_tree_node<T>::set_left_children(binary_tree_node<T> *left_children) {
//    this->left_children = left_children;
//}
//
//template <class T>
//void binary_tree_node<T>::set_right_children(binary_tree_node<T> *right_children) {
//    this->right_children = right_children;
//}
//
//template <class T>
//class binary_tree{
//public:
//    binary_tree_node<T> *root;
//public:
//    binary_tree();
//    ~binary_tree();
//    bool is_empty();
//    binary_tree_node<T>*& get_root();
//    void create_binary();
//    void create_binary_tree_by_pre_order(binary_tree_node<T> *&temp);//根据前序优先遍历算法创建二叉树
//    void create_binary_tree_by_pre_order_and_in_order(binary_tree_node<T> *&temp,string pre_order_string,string in_order_string);//根据前序和中序优先遍历算法创建二叉树
//    void create_binary_tree_by_in_order_and_post_order(binary_tree_node<T> *&temp,string in_order_string,string post_order_string);//根据中序和后序优先遍历算法创建二叉树
//    void breadth_first_order();//广度优先遍历
//    void pre_order();//前序深度优先遍历
//    void pre_order(binary_tree_node<T> *temp);//前序深度优先遍历 递归
//    void in_order();//中序深度优先遍历
//    void in_order(binary_tree_node<T> *temp);//中序深度优先遍历 递归
//    void post_order();//后序深度优先遍历
//    void post_order(binary_tree_node<T> *temp);//后序深度优先遍历 递归
//    int get_one(binary_tree_node<T>*& temp);
//    int get_two(binary_tree_node<T>*& temp);
//    int get_zero(binary_tree_node<T>*& temp);
//    int get_tree_height(binary_tree_node<T>*& temp);
//    void get_tree_wide(binary_tree_node<T>*& temp,int f,int* wide);
//    T get_max_one(binary_tree_node<T>*& temp);
//    void change_children(binary_tree_node<T>*& temp);
//    void delete_all_leaves(binary_tree_node<T>*& temp);
//};
//
//template <class T>
//binary_tree<T>::binary_tree() {
//    root = nullptr;
//}
//
//template <class T>
//binary_tree<T>::~binary_tree() {
//    if(!is_empty()){
//        queue<binary_tree_node<T>*> binary_tree_node_queue;
//        binary_tree_node_queue.en_queue(root);
//        binary_tree_node<T> *temp;
//        while(binary_tree_node_queue.get_size()==0){
//            binary_tree_node_queue.de_queue(temp);
//            if(temp->get_left_children()){
//                binary_tree_node_queue.en_queue(temp->get_left_children());
//            }
//            if(temp->get_right_children()){
//                binary_tree_node_queue.en_queue(temp->get_right_children());
//            }
//            delete(temp);
//        }
//    }
//}
//
//template <class T>
//bool binary_tree<T>::is_empty() {
//    return root == nullptr;
//}
//
//template <class T>
//binary_tree_node<T>*& binary_tree<T>::get_root() {
//    return root;
//}
//
//template <class T>
//void binary_tree<T>::create_binary() {
//    cout<<"1.根据前序深度优先遍历创建二叉树\n2.根据前序和中序深度优先遍历创建二叉树\n3.根据中序和后序深度优先遍历创建二叉树"<<endl;
//    cout<<"请输入一个序号：";
//    int i;
//    cin>>i;
//    string pre_order_string,in_order_string,post_order_string;
//    switch (i){
//        case 1:
//            create_binary_tree_by_pre_order(root);
//            break;
//        case 2:
//            cout<<"请输入前序序列：";
//            cin>>pre_order_string;
//            cout<<"请输入中序序列：";
//            cin>>in_order_string;
////            pre_order_string = "ABDFGCEH";
////            in_order_string = "BFDGACEH";
//            create_binary_tree_by_pre_order_and_in_order(root,pre_order_string,in_order_string);
//            break;
//        case 3:
//            cout<<"请输入后序序列：";
//            cin>>post_order_string;
//            cout<<"请输入中序序列：";
//            cin>>in_order_string;
//            create_binary_tree_by_in_order_and_post_order(root,in_order_string,post_order_string);
//            break;
//        default:
//            cout<<"无效的序号！"<<endl;
//            break;
//    }
//}
//
//template <class T>
//void binary_tree<T>::create_binary_tree_by_pre_order(binary_tree_node<T>*&temp) {
//    T a;
//    cin>>a;
//    if(a=='#'){
//        temp = nullptr;
//    }
//    else{
//        temp = new binary_tree_node<T>;
//        temp->set_item(a);
//        create_binary_tree_by_pre_order(temp->get_left_children());
//        create_binary_tree_by_pre_order(temp->get_right_children());
//    }
//
//}
//
//template <class T>
//void binary_tree<T>::create_binary_tree_by_pre_order_and_in_order(binary_tree_node<T> *&temp, string pre_order_string,
//                                                                  string in_order_string) {
//    if(pre_order_string.empty()||in_order_string.empty()){
//        temp = nullptr;
//        return;
//    }
//    int length;
//    char a = pre_order_string[0];
//    if(in_order_string.find(a)==in_order_string.npos){
//        cout<<"error!"<<endl;
//        return ;
//    }
//    else{
//        length = in_order_string.find(a);
//    }
//    temp = new binary_tree_node<T>;
//    temp->set_item(a);
//    create_binary_tree_by_pre_order_and_in_order(temp->get_left_children(),pre_order_string.substr(1,length),in_order_string.substr(0,length));
//    create_binary_tree_by_pre_order_and_in_order(temp->get_right_children(),pre_order_string.substr(length+1,pre_order_string.length()-length-1),in_order_string.substr(length+1,in_order_string.length()-length-1));
//}
//
//template <class T>
//void binary_tree<T>::create_binary_tree_by_in_order_and_post_order(binary_tree_node<T> *&temp, string in_order_string,
//                                                                   string post_order_string) {
//    if(post_order_string.empty()||in_order_string.empty()){
//        temp = nullptr;
//        return;
//    }
//    int length;
//    int post_order_string_length = post_order_string.length();
//    char a = post_order_string[post_order_string_length - 1];
//    if(in_order_string.find(a)==in_order_string.npos){
//        cout<<"error!"<<endl;
//        return ;
//    }
//    else{
//        length = in_order_string.find(a);
//    }
//    temp = new binary_tree_node<T>;
//    temp->set_item(a);
//    create_binary_tree_by_in_order_and_post_order(temp->get_left_children(),in_order_string.substr(0,length),post_order_string.substr(0,length));
//    create_binary_tree_by_in_order_and_post_order(temp->get_right_children(),in_order_string.substr(length+1,in_order_string.length()-length-1),post_order_string.substr(length,post_order_string.length()-length-1));
//}
//
//template <class T>
//void binary_tree<T>::breadth_first_order() {
//    if(!is_empty()){
//        queue<binary_tree_node<T>*> binary_tree_node_queue;
//        binary_tree_node_queue.en_queue(root);
//        binary_tree_node<T> *temp;
//        while(binary_tree_node_queue.get_size()!=0){
//            binary_tree_node_queue.de_queue(temp);
//            cout<<temp->get_item()<<" ";
//            if(temp->get_left_children()){
//                binary_tree_node_queue.en_queue(temp->get_left_children());
//            }
//            if(temp->get_right_children()){
//                binary_tree_node_queue.en_queue(temp->get_right_children());
//            }
//        }
//    }
//    cout<<endl;
//}
//
//template <class T>
//void binary_tree<T>::pre_order() {
//    if(!is_empty()){
//        stack<binary_tree_node<T>*> binary_tree_node_stack;
//        binary_tree_node<T> *temp = root;
//        while(!binary_tree_node_stack.is_empty() || temp){
//            if(temp){
//                cout<<temp->get_item()<<" ";
//                if(temp->get_right_children()){
//                    binary_tree_node_stack.push(temp->get_right_children());
//                }
//                temp = temp->get_left_children();
//            }
//            else{
//                binary_tree_node_stack.pop(temp);
//            }
//        }
//    }
//    cout<<endl;
//}
//
//template <class T>
//void binary_tree<T>::pre_order(binary_tree_node<T> *temp) {
//    if(temp){
//        cout<<temp->get_item()<<" ";
//        pre_order(temp->get_left_children());
//        pre_order(temp->get_right_children());
//    }
//}
//
//template <class T>
//void binary_tree<T>::in_order() {
//    if(!is_empty()){
//        stack<binary_tree_node<T>*> binary_tree_node_stack;
//        binary_tree_node<T> *temp = root;
//        while(!binary_tree_node_stack.is_empty() || temp){
//            if(temp){
//                binary_tree_node_stack.push(temp);
//                temp = temp->get_left_children();
//            }
//            else{
//                binary_tree_node_stack.pop(temp);
//                cout<<temp->get_item()<<" ";
//                temp = temp->get_right_children();
//            }
//        }
//    }
//    cout<<endl;
//}
//
//template <class T>
//void binary_tree<T>::in_order(binary_tree_node<T> *temp) {
//    if(temp){
//        in_order(temp->get_left_children());
//        cout<<temp->get_item()<<" ";
//        in_order(temp->get_right_children());
//    }
//}
//
//template <class T>
//void binary_tree<T>::post_order() {
//    if(!is_empty()){
//        stack<binary_tree_node<T>*> binary_tree_node_stack;
//        binary_tree_node<T> *temp = root;
//        binary_tree_node<T> *pre = root;
//        while(!binary_tree_node_stack.is_empty() || temp){
//            if(temp->get_left_children()){
//                binary_tree_node_stack.push(temp);
//                temp = temp->get_left_children();
//            }
//            else{
//                while(temp){
//                    if(!temp->get_right_children()||temp->get_right_children()==pre){
//                        cout<<temp->get_item()<<" ";
//                        pre = temp;
//                        if(binary_tree_node_stack.is_empty()){
//                            cout<<endl;
//                            return;
//                        }
//                        binary_tree_node_stack.pop(temp);
//                    }
//                    else{
//                        binary_tree_node_stack.push(temp);
//                        temp = temp->get_right_children();
//                        break;
//                    }
//                }
//            }
//        }
//    }
//    cout<<endl;
//}
//
//template <class T>
//void binary_tree<T>::post_order(binary_tree_node<T> *temp) {
//    if(temp){
//        post_order(temp->get_left_children());
//        post_order(temp->get_right_children());
//        cout<<temp->get_item()<<" ";
//    }
//}
//
//template <class T>
//int binary_tree<T>::get_one(binary_tree_node<T> *&temp) {
//    if (temp->get_left_children() == nullptr && temp->get_right_children() == nullptr) {
//        return 0;
//    } else if (temp->get_left_children() == nullptr && temp->get_right_children() != nullptr) {
//        return get_one(temp->get_right_children()) + 1;
//    } else if (temp->get_left_children() != nullptr && temp->get_right_children() == nullptr) {
//        return get_one(temp->get_left_children()) + 1;
//    } else {
//        return get_one(temp->get_left_children()) + get_one(temp->get_right_children());
//    }
//}
//
//template <class T>
//int binary_tree<T>::get_two(binary_tree_node<T> *&temp) {
//    if(temp->get_left_children()== nullptr&&temp->get_right_children()== nullptr){
//        return 0;
//    }
//    else if(temp->get_left_children()== nullptr&&temp->get_right_children()!= nullptr){
//        return get_two(temp->get_right_children());
//    }
//    else if(temp->get_left_children()!= nullptr && temp->get_right_children() == nullptr){
//        return get_two(temp->get_left_children());
//    }
//    else{
//        return get_two(temp->get_left_children()) + get_two(temp->get_right_children()) + 1;
//    }
//}
//
//template <class T>
//int binary_tree<T>::get_zero(binary_tree_node<T> *&temp) {
//    if(temp->get_left_children()== nullptr&&temp->get_right_children()== nullptr){
//        return 1;
//    }
//    else if(temp->get_left_children()== nullptr&&temp->get_right_children()!= nullptr){
//        return get_zero(temp->get_right_children());
//    }
//    else if(temp->get_left_children()!= nullptr && temp->get_right_children() == nullptr){
//        return get_zero(temp->get_left_children());
//    }
//    else{
//        return get_zero(temp->get_left_children()) + get_zero(temp->get_right_children());
//    }
//}
//
//template <class T>
//int binary_tree<T>::get_tree_height(binary_tree_node<T> *&temp) {
//    if(temp->get_left_children()== nullptr&&temp->get_right_children()== nullptr){
//        return 1;
//    }
//    else if(temp->get_left_children()== nullptr&&temp->get_right_children()!= nullptr){
//        return get_tree_height(temp->get_right_children()) + 1;
//    }
//    else if(temp->get_left_children()!= nullptr && temp->get_right_children() == nullptr){
//        return get_tree_height(temp->get_left_children()) + 1;
//    }
//    else{
//        int right = get_tree_height(temp->get_right_children());
//        int left = get_tree_height(temp->get_left_children());
//        return left>right?left + 1:right + 1;
//    }
//}
//
//template <class T>
//void binary_tree<T>::get_tree_wide(binary_tree_node<T> *&temp,int f,int* wide) {
//    if(temp != nullptr){
//        wide[f] ++;
//        get_tree_wide(temp->get_left_children(),f+1,wide);
//        get_tree_wide(temp->get_right_children(),f+1,wide);
//    }
//}
//
//template <class T>
//T binary_tree<T>::get_max_one(binary_tree_node<T> *&temp) {
//    if (temp->get_left_children() == nullptr && temp->get_right_children() == nullptr) {
//        return temp->get_item();
//    } else if (temp->get_left_children() == nullptr && temp->get_right_children() != nullptr) {
//        return get_max_one(temp->get_right_children());
//    } else if (temp->get_left_children() != nullptr && temp->get_right_children() == nullptr) {
//        return get_max_one(temp->get_left_children());
//    } else {
//        T left = get_max_one(temp->get_left_children());
//        T right = get_max_one(temp->get_right_children());
//        return left>right?left:right;
//    }
//}
//
//template <class T>
//void binary_tree<T>::change_children(binary_tree_node<T> *&temp) {
//    if(temp!= nullptr){
//        binary_tree_node<T>* t = temp->get_left_children();
//        temp->set_left_children(temp->get_right_children());
//        temp->set_right_children(t);
//        change_children(temp->get_left_children());
//        change_children(temp->get_right_children());
//    }
//}
//
//template <class T>
//void binary_tree<T>::delete_all_leaves(binary_tree_node<T> *&temp) {
//    if(temp->get_left_children()== nullptr&&temp->get_right_children()== nullptr){
//        binary_tree_node<T>*t = temp;
//        temp = nullptr;
//        delete t;
//    }
//    else if(temp->get_left_children()== nullptr&&temp->get_right_children()!= nullptr){
//        delete_all_leaves(temp->get_right_children());
//    }
//    else if(temp->get_left_children()!= nullptr && temp->get_right_children() == nullptr){
//        delete_all_leaves(temp->get_left_children());
//    }
//    else{
//        delete_all_leaves(temp->get_left_children());
//        delete_all_leaves(temp->get_right_children());
//    }
//}
//
//int main(){
//    binary_tree<char> tree;
//    tree.create_binary();
//    cout<<"广度优先遍历：";
//    tree.breadth_first_order();
//    cout<<"前序深度优先遍历：";
//    tree.pre_order();
//    cout<<"中序深度优先遍历：";
//    tree.in_order();
//    cout<<"后序深度优先遍历：";
//    tree.post_order();
//    cout<<"二叉树中度为1的节点个数："<<tree.get_one(tree.get_root())<<endl;
//    cout<<"二叉树中度为2的节点个数："<<tree.get_two(tree.get_root())<<endl;
//    cout<<"二叉树中度为0的节点个数："<<tree.get_zero(tree.get_root())<<endl;
//    cout<<"二叉树的深度："<<tree.get_tree_height(tree.get_root())<<endl;
//    int wide[tree.get_tree_height(tree.get_root())] = {0};
//    tree.get_tree_wide(tree.get_root(),0,wide);
//    int max = wide[0];
//    for(int i = 0; i< tree.get_tree_height(tree.get_root());++i){
//        if(max<wide[i]){
//            max = wide[i];
//        }
//    }
//    cout<<"二叉树的宽度为："<<max<<endl;
//    cout<<"二叉树中各结点中最大的元素的值为："<<tree.get_max_one(tree.get_root())<<endl;
//    tree.change_children(tree.get_root());
//    cout<<"广度优先遍历：";
//    tree.breadth_first_order();
//    cout<<"前序深度优先遍历：";
//    tree.pre_order();
//    cout<<"中序深度优先遍历：";
//    tree.in_order();
//    cout<<"后序深度优先遍历：";
//    tree.post_order();
//    tree.delete_all_leaves(tree.get_root());
//    cout<<"广度优先遍历：";
//    tree.breadth_first_order();
//    cout<<"前序深度优先遍历：";
//    tree.pre_order();
//    cout<<"中序深度优先遍历：";
//    tree.in_order();
//    cout<<"后序深度优先遍历：";
//    tree.post_order();
//    return 0;
//}
