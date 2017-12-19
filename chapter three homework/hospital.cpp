////
//// Created by lcr on 2017/12/3.
////
//
//#include <iostream>
//#include <string>
//#include "my_queue.h"
//
//using namespace std;
//
//class hosPartNode{
//private:
//    string name;
//    int num;
//public:
//    explicit hosPartNode(string& name,int num=1);
//    ~hosPartNode();
//    string& getName();
//    int getNum();
//    void setName(string name);
//    void setNum(int num);
//};
//
//hosPartNode::hosPartNode(string& name, int num):name(name),num(num) {}
//
//hosPartNode::~hosPartNode()=default;
//
//string& hosPartNode::getName() {
//    return name;
//}
//
//int hosPartNode::getNum() {
//    return num;
//}
//
//void hosPartNode::setName(string name) {
//    this->name = name;
//}
//
//void hosPartNode::setNum(int num) {
//    this->num = num;
//}
//
//class treeNode{
//private:
//    hosPartNode hosNode;
//    treeNode* firstChild;
//    treeNode* nextSibling;
//public:
//    treeNode(string& name,int num = 1,treeNode* firstChild = nullptr,treeNode* nextSibling = nullptr);
//    ~treeNode();
//    void setName(string& name);
//    void setNum(int num);
//    void setFirstChild(treeNode* fistChild);
//    void setNextSibling(treeNode* nextSibling);
//    string& getName();
//    int getNum();
//    treeNode* getFirstChild();
//    treeNode* getNextSibling();
//    void insertFirst(treeNode* first);
//    void insertNext(treeNode* next);
//};
//
//treeNode::treeNode(string &name, int num, treeNode *firstChild, treeNode *nextSibling):hosNode(name,num),firstChild(firstChild),nextSibling(nextSibling) {}
//
//treeNode::~treeNode()=default;
//
//void treeNode::setName(string &name) {
//    hosNode.setName(name);
//}
//
//void treeNode::setNum(int num) {
//    hosNode.setNum(num);
//}
//
//void treeNode::setFirstChild(treeNode *fistChild) {
//    this->firstChild = firstChild;
//}
//
//void treeNode::setNextSibling(treeNode *nextSibling) {
//    this->nextSibling = nextSibling;
//}
//
//string& treeNode::getName() {
//    return hosNode.getName();
//}
//
//int treeNode::getNum() {
//    return hosNode.getNum();
//}
//
//treeNode* treeNode::getFirstChild() {
//    return firstChild;
//}
//
//treeNode* treeNode::getNextSibling() {
//    return nextSibling;
//}
//
//void treeNode::insertFirst(treeNode *first) {
//    first->setNextSibling(firstChild);
//    firstChild = first;
//}
//
//void treeNode::insertNext(treeNode *next) {
//    next->setNextSibling(nextSibling);
//    nextSibling = next;
//}
//
//class tree{
//private:
//    treeNode* root;
//public:
//    tree();
//    ~tree();
//    void withTraverse();//广度优先遍历
//    void insert(string& parent, hosPartNode* value);//插入
//    int count(string& gParent, string& child);//计算某个节点包含另一个节点的数目
//    treeNode* find(string& current);//查找某个节点
//    treeNode* getParent(string& current);//查找某个节点的父节点
//};
//
//tree::tree() {
//    string a("医院");
//    root = new treeNode(a);
//}
//
//tree::~tree() {
//    queue<treeNode*> treeNodeQueue;
//    treeNodeQueue.en_queue(root);
//    treeNode* temp, *p;
//    while(treeNodeQueue.get_size()){
//        treeNodeQueue.de_queue(temp);
//        do{
//            if(temp->getFirstChild()){
//                treeNodeQueue.en_queue(temp->getFirstChild());
//            }
//            p = temp;
//            temp = temp->getNextSibling();
//            delete p;
//        }while(temp);
//    }
//}
//
//void tree::withTraverse() {
//    queue<treeNode*> treeNodeQueue;
//    treeNodeQueue.en_queue(root);
//    treeNode* temp;
//    while(treeNodeQueue.get_size()){
//        treeNodeQueue.de_queue(temp);
//        do{
//            cout<<"名称："<<temp->getName()<<" 数量："<<temp->getNum()<<endl;
//            if(temp->getFirstChild()){
//                treeNodeQueue.en_queue(temp->getFirstChild());
//            }
//            temp = temp->getNextSibling();
//        }while(temp);
//    }
//}
//
//treeNode* tree::find(string& current) {
//    queue<treeNode*> treeNodeQueue;
//    treeNodeQueue.en_queue(root);
//    treeNode* temp;
//    while(treeNodeQueue.get_size()){
//        treeNodeQueue.de_queue(temp);
//        do{
//            if(temp->getName() == current){
//                return temp;
//            }
//            if(temp->getFirstChild()){
//                treeNodeQueue.en_queue(temp->getFirstChild());
//            }
//            temp = temp->getNextSibling();
//        }while(temp);
//    }
//    return nullptr;
//}
//
//treeNode* tree::getParent(string& current) {
//   if(current.empty()){
//       return nullptr;
//   }
//   else{
//       queue<treeNode*> treeNodeQueue;
//       treeNode* temp, *parent;
//       parent = nullptr;
//       temp = root;
//       while(temp){
//           if(temp->getName() == current){
//               return parent;
//           }
//           else{
//               treeNodeQueue.en_queue(temp);
//               temp = temp->getNextSibling();
//           }
//       }
//       while(treeNodeQueue.get_size()){
//           treeNodeQueue.de_queue(parent);
//           temp = parent->getFirstChild();
//           while(temp){
//               if(temp->getName() == current){
//                   return parent;
//               }
//               treeNodeQueue.en_queue(temp);
//               temp = temp->getNextSibling();
//           }
//       }
//       return nullptr;
//   }
//}
//
//void tree::insert(string& parent, hosPartNode *value) {
//    treeNode* parentNode = find(parent);
//    if(parentNode){
//        parentNode->insertFirst(new treeNode(value->getName(), value->getNum()));
//    }
//    else{
//        cout<<"插入失败！没有该节点！"<<endl;
//    }
//}
//
//int tree::count(string& gParent, string& child) {
//    treeNode* gParentNode = find(gParent);
//    treeNode* childNode = find(child);
//    treeNode* parent = nullptr;
//    int sum = 1;
//    if(!gParentNode||!childNode){
//        cout<<"有节点不存在！"<<endl;
//        return 0;
//    }
//    else{
//        while(true){
//            parent = getParent(childNode->getName());
//            if(parent){
//                sum *= childNode->getNum();
//            }
//            else{
//                return 0;
//            }
//            if(gParentNode->getName() == parent->getName()){
//                return sum;
//            }
//            else{
//                childNode = parent;
//            }
//        }
//    }
//}
//
//int main(){
//    tree hospital;
//    string name,parentName,a("a");
//    int num;
//    cout<<"请输入插入的节点的父节点名称以及该节点的名称和数量：(以输入a a 1结束）"<<endl;
//    cin>>parentName>>name>>num;
//    while(!(parentName == a&&name == a&&num == 1)){
//        hospital.insert(parentName,new hosPartNode(name,num));
//        cout<<"请输入插入的节点的父节点名称以及该节点的名称和数量：(以输入a a 1结束）"<<endl;
//        cin>>parentName>>name>>num;
//    }
//    hospital.withTraverse();
//    cout<<"请输入要计算的两个名称："<<endl;
//    cin>>parentName>>name;
//    while(!(parentName == a && name == a)){
//        cout<<parentName<<"中有"<<hospital.count(parentName,name)<<"个"<<name<<endl;
//        cout<<"请输入要计算的两个名称："<<endl;
//        cin>>parentName>>name;
//    }
//    cout<<"请输入一个节点的名称："<<endl;
//    cin>>name;
//    while(name != a){
//        treeNode* s = hospital.find(name);
//        if(!s){
//            cout<<"查无此节点！"<<endl;
//        }
//        else{
//            cout<<"该节点名称："<<s->getName()<<" 数量："<<s->getNum()<<endl;
//            if(s->getFirstChild()){
//                s = s->getFirstChild();
//                while(true){
//                    cout<<"该节点子节点名称："<<s->getName()<<" 数量："<<s->getNum()<<endl;
//                    s = s->getNextSibling();
//                    if(!s){
//                        break;
//                    }
//                }
//            }
//            else{
//                cout<<"该节点没有子节点！"<<endl;
//            }
//        }
//        cout<<"请输入一个节点的名称："<<endl;
//        cin>>name;
//    }
//    return 0;
//}