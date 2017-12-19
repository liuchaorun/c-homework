//#include <iostream>
//#include <string>
//
//using namespace std;
//
//int naive_str_matching(string &t,string &p){
//    int i=0,j=0,p_length = p.size(),t_length = t.length();
//    if(t_length<p_length){
//        return -1;
//    }
//    while(i<t_length&&j<p_length){
//        if(t[i]==p[j]){
//            i++;
//            j++;
//        }
//        else{
//            i = i - j + 1;
//            j = 0;
//        }
//    }
//    if(j==p_length){
//        return i-j;
//    }
//    else{
//        return -1;
//    }
//}
//
//int main(){
//    string t,p;
//    cout<<"please input the T string and P sting:";
//    cin>>t;
//    cin>>p;
//    cout<<naive_str_matching(t,p);
//    return 0;
//}