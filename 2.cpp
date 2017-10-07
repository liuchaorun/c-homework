//#include <iostream>
//using namespace std;
//
//class array_list
//{
//private:
//
// int *array;
//    int max_length;
//    int current_length;
//public:
//    array_list(int length);
//    ~array_list();
//    void del_min_one();
//    void del_by_val();
//    void del_by_range();
//    void show();
//};
//
//array_list::array_list(int length) {
//    if(length<=0){
//        cout<<"err! please input right length!";
//    }
//    else{
//        array = new int[length];
//        max_length = current_length = length;
//        cout<<"please input array number:"<<endl;
//        for (int i = 0; i < current_length ; ++i) {
//            cin>>array[i];
//        }
//    }
//}
//
//array_list::~array_list() {
//    delete[](array);
//}
//
//void array_list::del_min_one() {
//    int min=0;
//    for(int i=1;i<current_length;i++){
//        if(array[i]<array[min]){
//            min=i;
//        }
//    }
//    min = array[min];
//    for(int i=0;i<current_length;i++){
//        if(array[i]==min){
//            array[i]=array[current_length-1];
//        }
//    }
//}
//
//void array_list::del_by_val() {
//    int v;
//    cout<<"please input the value:";
//    cin>>v;
//    for (int i = 0; i < current_length ; ++i) {
//        if(array[i]==v){
//            for (int j = i ; j < current_length-1 ; ++j) {
//                array[j]=array[j+1];
//            }
//            current_length--;
//            i--;
//        }
//    }
//}
//
//void array_list::del_by_range() {
//    int s,t;
//    cout<<"please input th range:";
//    cin>>s>>t;
//    for (int i = 0; i < current_length ; ++i) {
//        if(array[i]>=s&&array[i]<=t){
//            for (int j = i ; j < current_length-1 ; ++j) {
//                array[j]=array[j+1];
//            }
//            current_length--;
//            i--;
//        }
//    }
//}
//
//void array_list::show() {
//    if(current_length==0){
//        cout<<"this array is empty"<<endl;
//    }
//    else{
//        for (int i = 0; i < current_length; ++i) {
//            cout<<array[i]<<" ";
//        }
//        cout<<endl;
//    }
//}
//
//int main(){
//    cout<<"please input the length of array list:";
//    int n;
//    cin>>n;
//    array_list a(n);
//    a.show();
//    a.del_min_one();
//    a.show();
//    a.del_by_val();
//    a.show();
//    a.del_by_range();
//    a.show();
//    return 0;
//}