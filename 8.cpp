//#include <iostream>
//using namespace std;
//
//class double_link_node{
//private:
//    int num;
//    double_link_node* next;
//    double_link_node* prev;
//public:
//    double_link_node(int number=0,double_link_node* p = 0,double_link_node* n =0);
//    int get_num();
//    double_link_node* get_prev();
//    double_link_node* get_next();
//    void set_num(int n);
//    void set_prev(double_link_node* p);
//    void set_next(double_link_node* n);
//};
//
//double_link_node::double_link_node(int number, double_link_node *p, double_link_node *n) {
//    num = number;
//    prev = p;
//    next = n;
//}
//
//void double_link_node::set_num(int n) {
//    num = n;
//}
//
//void double_link_node::set_prev(double_link_node *p) {
//    prev = p;
//}
//
//void double_link_node::set_next(double_link_node *n) {
//    next = n;
//}
//
//int double_link_node::get_num() {
//    return num;
//}
//
//double_link_node* double_link_node::get_prev() {
//    return prev;
//}
//
//double_link_node* double_link_node::get_next() {
//    return next;
//}
//
//class double_link_list{
//private:
//    double_link_node* head;
//    double_link_node* tail;
//public:
//    double_link_list();
//    void add(int n);
//    void show();
//    void del_one_by_val(int v);
//};
//
//double_link_list::double_link_list() {
//    head = new double_link_node(0);
//    tail=head;
//}
//
//void double_link_list::show() {
//    double_link_node* temp = head->get_next();
//    while(temp!=head){
//        cout<<temp->get_num()<<" ";
//        temp=temp->get_next();
//    }
//    cout<<endl;
//}
//
//void double_link_list::add(int n) {
//    double_link_node* temp;
//    temp = new double_link_node();
//    temp->set_num(n);
//    tail->set_next(temp);
//    temp->set_prev(tail);
//    tail = temp;
//    head->set_num(head->get_num()+1);
//    head->set_prev(tail);
//    tail->set_next(head);
//}
//
//void double_link_list::del_one_by_val(int v) {
//    double_link_node* p = head->get_next();
//    int flag = 0;
//    while(p!=head){
//        if(p->get_num()==v){
//            flag = 1;
//            break;
//        }
//        p = p->get_next();
//    }
//    if(flag==1){
//        p->get_prev()->set_next(p->get_next());
//        p->get_next()->set_prev(p->get_prev());
//        delete p;
//    }
//    else{
//        cout<<"no this number"<<endl;
//    }
//}
//
//int main(){
//    double_link_list list;
//    cout<<"please input a number(end of 0):\n";
//    int n;
//    cin>>n;
//    while(n!=0){
//        list.add(n);
//        cin>>n;
//    }
//    list.show();
//    cout<<"please input the number you want to delete:";
//    int v;
//    cin>>v;
//    list.del_one_by_val(v);
//    list.show();
//    return 0;
//}