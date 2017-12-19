//#include <iostream>
//#include <fstream>
//#include <cassert>
//
//using namespace std;
//
//template<class T>
//class stack {
//private:
//    T *s;
//    int top;
//    int max_length;
//public:
//    stack(int size=1);
//
//    ~stack();
//
//    bool clear();
//
//    bool push(T element);
//
//    bool Top(T &element);
//
//    bool pop(T &element);
//
//    bool isEmpty();
//
//    bool isFull();
//};
//
//template<class T>
//stack<T>::stack(int size) {
//    top = -1;
//    max_length = size;
//    s = new T[size];
//}
//
//template <class T>
//stack<T>::~stack() {
//    delete s;
//}
//
//template <class T>
//bool stack<T>::clear() {
//    top = -1;
//}
//
//template <class T>
//bool stack<T>::isEmpty() {
//    if(top==-1){
//        return true;
//    }
//    else{
//        return false;
//    }
//}
//
//template <class T>
//bool stack<T>::isFull() {
//    if(top==max_length-1){
//        return true;
//    }
//    else{
//        return false;
//    }
//}
//
//template <class T>
//bool stack<T>::push(T element) {
//    if(isFull()){
//        T* old = s;
//        s =new T[max_length*2];
//        for(int i=0;i<max_length;++i){
//            s[i]=old[i];
//        }
//        max_length*=2;
//        s[++top] = element;
//        delete old;
//        return true;
//    }
//    else{
//        s[++top] = element;
//        return true;
//    }
//}
//
//template <class T>
//bool stack<T>::Top(T &element) {
//    if(isEmpty()){
//        return false;
//    }
//    else{
//        element = s[top];
//        return true;
//    }
//}
//
//template <class T>
//bool stack<T>::pop(T &element) {
//    if(isEmpty()){
//        return false;
//    }
//    else{
//        element = s[top--];
//        return true;
//    }
//}
//
//class check{
//private:
//    stack<char>* ch;
//    stack<int>* ch_row;
//public:
//    check();
//    ~check();
//    bool put_in(string file_address);
//    int char_to_int(char c);
//};
//
//check::check() {
//    ch = new stack<char>(10);
//    ch_row = new stack<int>(10);
//}
//
//check::~check() {
//    delete ch,ch_row;
//}
//
//bool check::put_in(string file_address) {
//    ifstream infile;
//    infile.open(file_address);
//    assert(infile.is_open());   //若失败,则输出错误消息,并终止程序运行
//
//    char c,ch_top;
//    int row=1;
//    bool double_quotes_flag=false,annotations=false;
//    infile >> noskipws;
//    infile>>c;
//    while (!infile.eof())
//    {
//        if(c == '\n'){
//            row++;
//        }
//        if(c=='\"'){
//            if(!annotations){
//                if(!double_quotes_flag){
//                    double_quotes_flag=true;
//                    ch_row->push(row);
//                    ch->push(c);
//                }
//                else{
//                    double_quotes_flag=false;
//                    int i;
//                    ch_row->pop(i);
//                    ch->pop(ch_top);
//                }
//            }
//        }
//        else{
//            if(!double_quotes_flag){
//                if(c=='/'){
//                    infile>>c;
//                    if(c=='*'){
//                        annotations=true;
//                        ch->push('/');
//                        ch_row->push(row);
//                    }
//                }
//                if(c=='*'){
//                    infile>>c;
//                    if(c=='/'){
//                        if(annotations){
//                            annotations=false;
//                            ch->pop(ch_top);
//                            int i;
//                            ch_row->pop(i);
//                        }
//                        else{
//                            ch->push('*');
//                            ch_row->push(row);
//                            break;
//                        }
//                    }
//                }
//                if(!annotations){
//                    if(c=='{'||c=='['||c=='('){
//                        ch->push(c);
//                        ch_row->push(row);
//                    }
//                    if(c=='}'||c==']'||c==')'){
//                        ch->Top(ch_top);
//                        if(char_to_int(ch_top)==char_to_int(c)){
//                            ch->pop(ch_top);
//                            int i;
//                            ch_row->pop(i);
//                        }
//                        else{
//                            break;
//                        }
//                    }
//                }
//            }
//        }
//        infile>>c;
//    }
//    infile.close();
//    if(ch_row->isEmpty()){
//        cout<<"no errors";
//    }
//    else{
//        int i;
//        ch_row->pop(i);
//        ch->pop(ch_top);
//        cout<<i<<" row ";
//        if(ch_top=='/'){
//            cout<<"/* error";
//        }
//        else if(ch_top=='*'){
//            cout<<"*/ error";
//        }
//        else{
//            cout<<ch_top<<" error";
//        }
//    }
//}
//
//int check::char_to_int(char c) {
//    switch (c){
//        case '{':
//        case '}':
//            return 0;
//        case '(':
//        case ')':
//            return 1;
//        case '[':
//        case ']':
//            return 2;
//        default:
//            return 3;
//    }
//}
//
//int main(){
//    check a;
//    a.put_in("12.txt");
//    return 0;
//}