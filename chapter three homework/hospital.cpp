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
//    void withTraverse();//������ȱ���
//    void insert(string& parent, hosPartNode* value);//����
//    int count(string& gParent, string& child);//����ĳ���ڵ������һ���ڵ����Ŀ
//    treeNode* find(string& current);//����ĳ���ڵ�
//    treeNode* getParent(string& current);//����ĳ���ڵ�ĸ��ڵ�
//};
//
//tree::tree() {
//    string a("ҽԺ");
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
//            cout<<"���ƣ�"<<temp->getName()<<" ������"<<temp->getNum()<<endl;
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
//        cout<<"����ʧ�ܣ�û�иýڵ㣡"<<endl;
//    }
//}
//
//int tree::count(string& gParent, string& child) {
//    treeNode* gParentNode = find(gParent);
//    treeNode* childNode = find(child);
//    treeNode* parent = nullptr;
//    int sum = 1;
//    if(!gParentNode||!childNode){
//        cout<<"�нڵ㲻���ڣ�"<<endl;
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
//    cout<<"���������Ľڵ�ĸ��ڵ������Լ��ýڵ�����ƺ�������(������a a 1������"<<endl;
//    cin>>parentName>>name>>num;
//    while(!(parentName == a&&name == a&&num == 1)){
//        hospital.insert(parentName,new hosPartNode(name,num));
//        cout<<"���������Ľڵ�ĸ��ڵ������Լ��ýڵ�����ƺ�������(������a a 1������"<<endl;
//        cin>>parentName>>name>>num;
//    }
//    hospital.withTraverse();
//    cout<<"������Ҫ������������ƣ�"<<endl;
//    cin>>parentName>>name;
//    while(!(parentName == a && name == a)){
//        cout<<parentName<<"����"<<hospital.count(parentName,name)<<"��"<<name<<endl;
//        cout<<"������Ҫ������������ƣ�"<<endl;
//        cin>>parentName>>name;
//    }
//    cout<<"������һ���ڵ�����ƣ�"<<endl;
//    cin>>name;
//    while(name != a){
//        treeNode* s = hospital.find(name);
//        if(!s){
//            cout<<"���޴˽ڵ㣡"<<endl;
//        }
//        else{
//            cout<<"�ýڵ����ƣ�"<<s->getName()<<" ������"<<s->getNum()<<endl;
//            if(s->getFirstChild()){
//                s = s->getFirstChild();
//                while(true){
//                    cout<<"�ýڵ��ӽڵ����ƣ�"<<s->getName()<<" ������"<<s->getNum()<<endl;
//                    s = s->getNextSibling();
//                    if(!s){
//                        break;
//                    }
//                }
//            }
//            else{
//                cout<<"�ýڵ�û���ӽڵ㣡"<<endl;
//            }
//        }
//        cout<<"������һ���ڵ�����ƣ�"<<endl;
//        cin>>name;
//    }
//    return 0;
//}