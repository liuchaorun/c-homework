//#include <iostream>
//#include <windows.h>
//
//using namespace std;
//
//int Strlen(char *s){
//    int n = 0;
//    while(*s!='\0'){
//        n++;
//        s++;
//    }
//    return n;
//}
//
//class String{
//private:
//    char* str;
//    int size;
//public:
//    String();
//    String(char* s);
//    ~String();
//    int Size();
//    String& operator = (String&s);
//    String& operator = (char *s);
//    String& operator + (String&s);
//    String& operator += (String& s);
//    String& operator += (char* s);
//    friend ostream& operator<<(ostream& out,const String& s);
//    friend istream  &operator>>(istream &is,String &s);
//    char& operator[](int i);
//};
//
//String::String() {
//    str = new char[1];
//    size = 1;
//}
//
//String::String(char *s) {
//    if(size==Strlen(s)){
//        str = s;
//    }
//    else{
//        delete str;
//        size = Strlen(s);
//        str = new char[size+1];
//        str = s;
//        str[size+1] = '\0';
//    }
//}
//
//String::~String() {
//    delete[](str);
//}
//
//int String::Size() {
//    return size;
//}
//
//char& String::operator[](int i) {
//    if(i>=size||i<0){
//        cout<<"Array out of bounds!"<<endl;
//        char s = '0';
//        return s;
//    }
//    else{
//        return str[i];
//    }
//}
//
//String& String::operator+(String &s) {
//    char *new_string = new char[s.Size()+size+1];
//    for(int i=0;i<s.Size()+size+1;++i){
//        if(i<size){
//            new_string[i] = str[i];
//        }
//        else if(i==s.Size()+size){
//            new_string[i] = '\0';
//        }
//        else{
//            new_string[i] = s[i-size];
//        }
//    }
//    String temp = new_string;
//    return temp;
//}
//
//String& String::operator=(String &s) {
//    size = s.Size();
//    delete str;
//    str = new char[size + 1];
//    int i = 0;
//    for(i=0;i<size;++i){
//        str[i]=s[i];
//    }
//    str[i]='\0';
//    return *this;
//}
//
//String& String::operator=(char *s) {
//    if(size==Strlen(s)){
//        str = s;
//    }
//    else{
//        delete str;
//        size = Strlen(s);
//        str = new char[size+1];
//        str = s;
//        str[size+1] = '\0';
//    }
//    return *this;
//}
//
//String& String::operator+=(String &s) {
//    char *temp = str;
//    size+=s.Size();
//    str = new char[size + 1];
//    int i=0;
//    for(i=0;i<size;++i){
//        if(i<size-s.Size()){
//            str[i]=temp[i];
//        }
//        else{
//            str[i]=s[i-size+s.Size()];
//        }
//    }
//    str[i]='\0';
//    delete[](temp);
//    return *this;
//}
//
//String& String::operator+=(char *s) {
//    char *temp = str;
//    int s_length = Strlen(s);
//    size+=s_length;
//    str = new char[size + 1];
//    int i=0;
//    for(i=0;i<size;++i){
//        if(i<size-s_length){
//            str[i]=temp[i];
//        }
//        else{
//            str[i]=s[i-size+s_length];
//        }
//    }
//    str[i]='\0';
//    delete[](temp);
//    return *this;
//}
//
//ostream& operator<<(ostream& out,const String& s){
//    out<<s.str;
//    return out;
//}
//
//istream &operator>>(istream &is,String &s){
//    char *a = new char[1024];
//    is>>a;
//    s = a;
//    return is;
//}
//
//int Strstr(String& s,String& t){
//    for(int i = s.Size() - 1;i>=0;--i){
//        int j = t.Size() - 1;
//        if(s[i]==t[j]){
//            for(;j>=0&&i>=0;j--,i--){
//                if(s[i]!=t[j]){
//                    break;
//                }
//            }
//            if(j==-1){
//                return i+2;
//            }
//        }
//    }
//    return -1;
//}
//
//int main(){
//    String a,b;
//    cin>>a;
//    cin>>b;
//    cout<<Strstr(a,b);
//    return 0;
//}