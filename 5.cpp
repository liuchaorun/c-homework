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
//    void show();
//    void add(int n);
//    link_node* get_head();
//    void merge(link_list a,link_list b);
//};
//
//link_list::link_list() {
//    head = new link_node(0);
//    tail = head;
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
//    if(head->get_num()==0){
//        head->set_next(temp);
//        tail=temp;
//    }
//    else{
//        link_node* temp1 = head;
//        while(temp1){
//            if(temp1->get_next()==0){
//                temp1->set_next(temp);
//                break;
//            }
//            else if(n<temp1->get_next()->get_num()){
//                temp->set_next(temp1->get_next());
//                temp1->set_next(temp);
//                break;
//            }
//            temp1=temp1->get_next();
//        }
//    }
//    head->set_num(head->get_num()+1);
//}
//
//link_node* link_list::get_head() {
//    return head;
//}
//
//void link_list::merge(link_list a, link_list b) {
//    link_node *insert,*a_head,*b_head;
//    a_head=a.get_head()->get_next();
//    b_head=b.get_head()->get_next();
//    while(a_head||b_head){
//        if(a_head&&b_head){
//            if(a_head->get_num()<b_head->get_num()){
//                insert=a_head;
//                a_head=a_head->get_next();
//            }
//            else{
//                insert=b_head;
//                b_head=b_head->get_next();
//            }
//        }
//        else if(a_head){
//            insert = a_head;
//            a_head = a_head->get_next();
//        }
//        else if(b_head){
//            insert = b_head;
//            b_head = b_head->get_next();
//        }
//        if(head->get_num()==0){
//            insert->set_next(0);
//            head->set_next(insert);
//        }
//        else{
//            insert->set_next(head->get_next());
//            head->set_next(insert);
//        }
//        head->set_num(head->get_num()+1);
//    }
//}
//
//int main(){
//    link_list a,b,c;
//    cout<<"please input a number(end of 0):\n";
//    int n;
//    cin>>n;
//    while(n!=0){
//        a.add(n);
//        cin>>n;
//    }
//    cout<<"please input a number(end of 0):\n";
//    cin>>n;
//    while(n!=0){
//        b.add(n);
//        cin>>n;
//    }
//    c.merge(a,b);
//    c.show();
//    return 0;
//}