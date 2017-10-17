//#include <iostream>
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
//char int_to_char(int number){
//    if(number>=0&&number<=9){
//        return (char)('0'+number);
//    }
//    else{
//        return (char)('A'+number-10);
//    }
//}
//
//int main(){
//    stack<int> change(10);
//    int number,n;
//    cout<<"please input a number:";
//    cin>>number;
//    cout<<"please input the Positional notation:";
//    cin>>n;
//    if((n>=2&&n<=9)||n==16){
//        while(number!=0){
//            change.push(number%n);
//            number/=n;
//        }
//        int element;
//        while(change.pop(element)){
//            if(n==16){
//                cout<<int_to_char(element);
//            }
//            else{
//                cout<<element;
//            }
//        }
//    }
//    else{
//        cout<<"please input the Positional notation!";
//    }
//
//    return 0;
//}