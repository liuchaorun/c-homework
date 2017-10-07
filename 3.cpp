//#include <iostream>
//using namespace std;
//
//class link_node{
//private:
//    int num;
//    link_node* next;
//public:
//    link_node(int n=0,link_node* nt=0);
//    int get_num();
//    void set_num(int n);
//    link_node* get_next();
//    void set_next(link_node* ne);
//};
//
//link_node::link_node(int n,link_node* nt) {
//    num = n;
//    next = nt;
//}
//
//void link_node::set_num(int n) {
//    num = n;
//}
//
//int link_node::get_num() {
//    return num;
//}
//
//void link_node::set_next(link_node *ne) {
//    next = ne;
//}
//
//link_node* link_node::get_next() {
//    return next;
//}
//
//class link_list{
//private:
//    link_node *head;
//    link_node *tail;
//public:
//    link_list();
//    ~link_list();
//    void add(int n);
//    void show();
//    void invert();
//};
//
//link_list::link_list() {
//    head=0;
//    tail=0;
//}
//
//link_list::~link_list() {
//    tail = head;
//    while(head){
//        head=head->get_next();
//        delete tail;
//        tail = head;
//    }
//}
//
//void link_list::add(int n) {
//    link_node* temp;
//    temp = new link_node(n);
//    if(!head){
//        head=tail=temp;
//    }
//    else{
//        tail->set_next(temp);
//        tail = temp;
//    }
//}
//
//void link_list::show() {
//    link_node* temp;
//    temp = head;
//    while(temp){
//        cout<<temp->get_num()<<" ";
//        temp = temp->get_next();
//    }
//    cout<<endl;
//}
//
//void link_list::invert() {
//    if(head->get_next()){
//        link_node* temp,*t;
//        tail=head;
//        head=head->get_next();
//        tail->set_next(0);
//        temp=head;
//        head=head->get_next();
//        temp->set_next(tail);
//        while(head){
//            t = head;
//            head=head->get_next();
//            t->set_next(temp);
//            temp=t;
//        }
//        head = temp;
//    }
//}
//
//int main(){
//    link_list list;
//    cout<<"please input a number(end of 0):\n";
//    int n;
//    cin>>n;
//    while(n!=0){
//        list.add(n);
//        cin>>n;
//    }
//    list.show();
//    list.invert();
//    list.show();
//    return 0;
//}