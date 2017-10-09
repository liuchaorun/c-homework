#include <iostream>
#include <string>
#include <math.h>

using namespace std;

template<class T>
class stack {
private:
    T *s;
    int top;
    int max_length;
public:
    stack(int size=1);

    ~stack();

    bool clear();

    bool push(T element);

    bool Top(T &element);

    bool pop(T &element);

    bool isEmpty();

    bool isFull();
};

template<class T>
stack<T>::stack(int size) {
    top = -1;
    max_length = size;
    s = new T[size];
}

template <class T>
stack<T>::~stack() {
    delete s;
}

template <class T>
bool stack<T>::clear() {
    top = -1;
}

template <class T>
bool stack<T>::isEmpty() {
    if(top==-1){
        return true;
    }
    else{
        return false;
    }
}

template <class T>
bool stack<T>::isFull() {
    if(top==max_length-1){
        return true;
    }
    else{
        return false;
    }
}

template <class T>
bool stack<T>::push(T element) {
    if(isFull()){
        T* old = s;
        s =new T[max_length*2];
        for(int i=0;i<max_length;++i){
            s[i]=old[i];
        }
        max_length*=2;
        s[++top] = element;
        delete old;
        return true;
    }
    else{
        s[++top] = element;
        return true;
    }
}

template <class T>
bool stack<T>::Top(T &element) {
    if(isEmpty()){
        return false;
    }
    else{
        element = s[top];
        return true;
    }
}

template <class T>
bool stack<T>::pop(T &element) {
    if(isEmpty()){
        return false;
    }
    else{
        element = s[top--];
        return true;
    }
}

class calculator{
private:
    string st;
public:
    calculator();
    ~calculator();
    bool put_in(string exp);
    double cal();
    void icp_less_isp(stack<char>& op,stack<double>& num);
    int isp(char s);
    int icp(char s);
};

calculator::calculator() {
    st = "";
}

calculator::~calculator() {}

bool calculator::put_in(string e) {
    if(!e.empty()){
        st = e;
        return true;
    }
    else{
        return false;
    }
}

double calculator::cal() {
    stack<char> op(10);
    stack<double> num(10);
    char op_top;
    int i=0;
    while(i!=st.size()){
        if(st[i]>='0'&&st[i]<='9'){
            int j=1;
            for(;;j++){
                if(st[i+j]!='.'&&(st[i+j]<'0'||st[i+j]>'9')||(i+j>st.size())) break;
            };
            string n = st.substr((unsigned)i,(unsigned)j);
            num.push(stod(n));
            i+=j;
        }
        else{
            while(1){
                if(op.isEmpty()){
                    op.push(st[i]);
                    break;
                }
                else{
                    op.Top(op_top);
                    if(icp(st[i])>isp(op_top)){
                        op.push(st[i]);
                        break;
                    }
                    else if(icp(st[i])<isp(op_top)){
                        icp_less_isp(op,num);
                    }
                    else{
                        op.pop(op_top);
                        break;
                    }
                }
            }
            i++;
        }
    }
    while(!op.isEmpty()) icp_less_isp(op,num);
    double result;
    num.pop(result);
    return result;
}

void calculator::icp_less_isp(stack<char>& op,stack<double>& num) {
    double num1,num2,result = 0.0;
    char op_top;
    op.pop(op_top);
    num.pop(num2);
    num.pop(num1);
    switch (op_top){
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            result = num1 / num2;
            break;
        case '%':
            result =(double) ((int)num1 % (int)num2);
            break;
        case '^':
            result = pow(num1,num2);
            break;
        default:
            break;
    }
    num.push(result);
}

//栈内优先级
int calculator::isp(char s) {
    switch (s){
        case '#':
            return 0;
        case '(':
            return 1;
        case '^':
            return 7;
        case '*':
        case '/':
        case '%':
            return 5;
        case '+':
        case '-':
            return 3;
        case ')':
            return 8;
        default:
            return -1;
    }
}

//栈外优先级
int calculator::icp(char s) {
    switch (s){
        case '#':
            return 0;
        case '(':
            return 8;
        case '^':
            return 6;
        case '*':
        case '/':
        case '%':
            return 4;
        case '+':
        case '-':
            return 2;
        case ')':
            return 1;
        default:
            return -1;
    }
}

int main(){
    string s;
    cin>>s;
    calculator c;
    c.put_in(s);
    cout<<c.cal();
    return 0;
}