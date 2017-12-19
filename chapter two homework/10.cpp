//#include <iostream>
//#include <string>
//#include <math.h>
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
//public:
//    check();
//    ~check();
//    bool put_in(string string1);
//    int char_to_int(char c);
//};
//
//check::check() {
//    ch = new stack<char>(10);
//}
//
//check::~check() {
//    delete ch;
//}
//
//bool check::put_in(string string1) {
//    char c,ch_top;
//    int n=0;
//    while (n!=string1.size())
//    {
//        c=string1[n];
//        if(c=='{'||c=='['||c=='('){
//            ch->push(c);
//        }
//        if(c=='}'||c==']'||c==')'){
//            ch->Top(ch_top);
//            if(char_to_int(ch_top)==char_to_int(c)){
//                ch->pop(ch_top);
//            }
//            else{
//                break;
//            }
//        }
//        n++;
//    }
//    if(ch->isEmpty()){
//        return true;
//    }
//    else{
//        ch->pop(ch_top);
//        cout<<ch_top<<" error!"<<endl;
//        return false;
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
//class calculator{
//private:
//    string st;
//    int flag;
//public:
//    calculator();
//    ~calculator();
//    bool put_in(string exp);
//    double cal();
//    void icp_less_isp(stack<char>& op,stack<double>& num);
//    int isp(char s);
//    int icp(char s);
//};
//
//calculator::calculator() {
//    st = "";
//    flag=0;
//}
//
//calculator::~calculator() {}
//
//bool calculator::put_in(string e) {
//    if(!e.empty()){
//        st = e;
//        return true;
//    }
//    else{
//        return false;
//    }
//}
//
//double calculator::cal() {
//    stack<char> op(10);
//    stack<double> num(10);
//    char op_top;
//    int i=0;
//    while(i!=st.size()){
//        if(st[i]>='0'&&st[i]<='9'){
//            int j=1;
//            for(;;j++){
//                if(st[i+j]!='.'&&(st[i+j]<'0'||st[i+j]>'9')||(i+j>st.size())) break;
//            };
//            string n = st.substr((unsigned)i,(unsigned)j);
//            num.push(stod(n));
//            i+=j;
//        }
//        else{
//            while(1){
//                if(op.isEmpty()){
//                    op.push(st[i]);
//                    break;
//                }
//                else{
//                    op.Top(op_top);
//                    if(icp(st[i])>isp(op_top)){
//                        op.push(st[i]);
//                        break;
//                    }
//                    else if(icp(st[i])<isp(op_top)){
//                        icp_less_isp(op,num);
//                        if(flag==1){
//                            return 0;
//                        }
//                    }
//                    else{
//                        op.pop(op_top);
//                        break;
//                    }
//                }
//            }
//            i++;
//        }
//    }
//    while(!op.isEmpty()) {
//        icp_less_isp(op,num);
//        if(flag==1){
//            return 0;
//        }
//    }
//    double result;
//    num.pop(result);
//    if(!flag){
//        return result;
//    }
//    else{
//        return 0;
//    }
//}
//
//void calculator::icp_less_isp(stack<char>& op,stack<double>& num) {
//    double num1,num2,result = 0.0;
//    char op_top;
//    op.pop(op_top);
//    if(!num.isEmpty()){
//        num.pop(num2);
//    }
//    else{
//        cout<<"errors!";
//        flag=1;
//        return ;
//    }
//    if(!num.isEmpty()){
//        num.pop(num1);
//    }
//    else{
//        cout<<"errors!";
//        flag=1;
//        return ;
//    }
//    switch (op_top){
//        case '+':
//            result = num1 + num2;
//            break;
//        case '-':
//            result = num1 - num2;
//            break;
//        case '*':
//            result = num1 * num2;
//            break;
//        case '/':
//            if(num2){
//                result = num1 / num2;
//            }
//            else{
//                cout<<"errors!";
//                flag=1;
//            }
//            break;
//        case '%':
//            if(num2){
//                result =(double) ((int)num1 % (int)num2);
//            }
//            else{
//                cout<<"errors!";
//                flag=1;
//            }
//            break;
//        case '^':
//            result = pow(num1,num2);
//            break;
//        default:
//            break;
//    }
//    num.push(result);
//}
//
////栈内优先级
//int calculator::isp(char s) {
//    switch (s){
//        case '#':
//            return 0;
//        case '(':
//            return 1;
//        case '^':
//            return 7;
//        case '*':
//        case '/':
//        case '%':
//            return 5;
//        case '+':
//        case '-':
//            return 3;
//        case ')':
//            return 8;
//        default:
//            return -1;
//    }
//}
//
////栈外优先级
//int calculator::icp(char s) {
//    switch (s){
//        case '#':
//            return 0;
//        case '(':
//            return 8;
//        case '^':
//            return 6;
//        case '*':
//        case '/':
//        case '%':
//            return 4;
//        case '+':
//        case '-':
//            return 2;
//        case ')':
//            return 1;
//        default:
//            return -1;
//    }
//}
//
//int main(){
//    string s;
//    check ch;
//    calculator c;
//    cin>>s;
//    if(ch.put_in(s)){
//        c.put_in(s);
//        cout<<c.cal();
//    }
//    return 0;
//}