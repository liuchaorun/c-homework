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
//    void show();
//    void add(int n);
//    link_node* get_head();
//    int get_max(link_node* temp);
//    int get_node_number(link_node* temp);
//    double get_average(link_node* temp,int n);
//};
//
//link_list::link_list() {
//    head = new link_node(0);
//    tail = head;
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
//void link_list::show() {
//    link_node* temp;
//    temp = head->get_next();
//    while(temp){
//        cout<<temp->get_num()<<" ";
//        temp = temp->get_next();
//    }
//    cout<<endl;
//}
//
//void link_list::add(int n) {
//    link_node* temp;
//    temp = new link_node(n);
//    tail->set_next(temp);
//    tail = temp;
//    head->set_num(head->get_num()+1);
//}
//
//link_node* link_list::get_head() {
//    return head;
//}
//
//int link_list::get_max(link_node* temp) {
//    if(temp->get_next()==0){
//        return temp->get_num();
//    }
//    else{
//        int n = get_max(temp->get_next());
//        return n>temp->get_num()?n:temp->get_num();
//    }
//}
//
//int link_list::get_node_number(link_node* temp) {
//    if(temp->get_next()==0){
//        return 1;
//    }
//    else{
//        return get_node_number(temp->get_next())+1;
//    }
//}
//
//double link_list::get_average(link_node *temp,int n) {
//    if(temp->get_next()==0){
//        return temp->get_num()*1.0/n;
//    }
//    else{
//        return get_average(temp->get_next(),n)+(temp->get_num()*1.0/n);
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
//    cout<<list.get_max(list.get_head())<<endl;
//    cout<<list.get_node_number(list.get_head()->get_next())<<endl;
//    cout<<list.get_average(list.get_head()->get_next(),list.get_node_number(list.get_head()->get_next()))<<endl;
//    return 0;
//}