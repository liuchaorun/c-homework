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
//    ~double_link_node();
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
//double_link_node::~double_link_node() {
//    delete prev,next;
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
//    void change();
//};
//
//double_link_list::double_link_list() {
//    head = new double_link_node(0);
//    tail=head;
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
//}
//
//void double_link_list::show() {
//    double_link_node* temp = head->get_next();
//    while(temp){
//        cout<<temp->get_num()<<" ";
//        temp=temp->get_next();
//    }
//    cout<<endl;
//}
//
//void double_link_list::change() {
//    double_link_node* temp,*double_head,*temp1;
//    temp = head->get_next();
//    tail = temp->get_next();
//    double_head =  new double_link_node(0);
//    while(temp&&temp->get_next()){
//        temp1 = temp->get_next();
//        temp->set_next(temp->get_next()->get_next());
//        if(temp->get_next()) {
//            temp->get_next()->set_prev(temp);
//            temp=temp->get_next();
//        }
//        temp1->set_next(double_head->get_next());
//        if(double_head->get_num()>0) temp1->get_next()->set_prev(temp1);
//        double_head->set_next(temp1);
//        temp1->set_prev(double_head);
//        double_head->set_num(double_head->get_num()+1);
//    }
//    tail->set_next(0);
//    temp->set_next(double_head->get_next());
//    double_head->get_next()->set_prev(temp);
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
//    list.change();
//    list.show();
//    return 0;
//}