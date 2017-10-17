#include <iostream>
#include <random>
#include <windows.h>

const int  BUSINESS_PROCESSING_TIME = 4;

using namespace std;

template <class T>
class link_node{
private:
    T item;
    link_node<T>* next;
public:
    link_node(T n,link_node<T>* nt= nullptr);
    T get_item();
    void set_item(T n);
    link_node<T>* get_next();
    void set_next(link_node<T>* ne);
};

template <class T>
link_node<T>::link_node(T n,link_node* nt) {
    item = n;
    next = nt;
}

template <class T>
T link_node<T>::get_item() {
    return item;
}

template <class T>
void link_node<T>::set_item(T n) {
    item = n;
}

template <class T>
void link_node<T>::set_next(link_node *ne) {
    next = ne;
}

template <class T>
link_node<T>* link_node<T>::get_next() {
    return next;
}

template <class T>
class queue{
private:
    int size;
    link_node<T> *front;
    link_node<T> *rear;
public:
    queue();
    ~queue();
    bool clear();
    bool en_queue(T item);
    bool de_queue(T &item);
    bool get_front(T &item);
    int get_size();
};

template <class T>
queue<T>::queue() {
    size = 0;
    front = rear = nullptr;
}

template <class T>
queue<T>::~queue() {
    clear();
}

template <class T>
bool queue<T>::clear() {
    link_node<T>* temp = nullptr;
    while(front!=rear){
        temp = front;
        front = front->get_next();
        delete temp;
    }
    delete front;
    size = 0;
    return true;
}

template <class T>
bool queue<T>::en_queue(T item) {
    link_node<T>* new_node = new link_node<T>(item);
    if(size == 0){
        front = rear = new_node;
    }
    else{
        rear->set_next(new_node);
        rear = rear->get_next();
    }
    size++;
    return true;
}

template <class T>
bool queue<T>::de_queue(T &item) {
    link_node<T>* temp = nullptr;
    if(size == 0){
        return false;
    }
    else{
        item = front->get_item();
        temp = front;
        front = front->get_next();
        delete temp;
        size--;
        return true;
    }
}

template <class T>
bool queue<T>::get_front(T &item) {
    if(size == 0){
        return false;
    }
    else{
        item = front->get_item();
        return true;
    }
}

template <class T>
int queue<T>::get_size() {
    return size;
}

class user{
private:
    int id;
    int is_await;
    int arrive_time;
    int serve_time;
public:
    user(int id=0,int current_time=0);
    void get_served(int a,int s);
    int get_id();
    int get_is_await();
    int get_arrive_time();
    int get_serve_time();
    void set_arrive_time(int a);
    void set_serve_time(int s);
    virtual void print_type()=0;
};

user::user(int id,int current_time):id(id) {
    is_await = 1;
    arrive_time = current_time;
    serve_time = 0;
}

int user::get_id() {
    return id;
}

int user::get_is_await() {
    return is_await;
}

int user::get_arrive_time() {
    return arrive_time;
}

int user::get_serve_time() {
    return serve_time;
}

void user::set_arrive_time(int a) {
    arrive_time = a;
}

void user::set_serve_time(int s) {
    serve_time = s;
}

void user::get_served(int a,int s) {
    is_await = 0;
    arrive_time = a;
    serve_time = s;
}

class normal_user:public user{
public:
    normal_user(int id=0,int current_time=0);
    void print_type();
};

normal_user::normal_user(int id,int current_time):user(id,current_time) {}

void normal_user::print_type() {
    cout<<"普通业务用户";
}

class vip_user:public user{
public:
    vip_user(int id=0,int current_time=0);
    void print_type();
};

vip_user::vip_user(int id,int current_time):user(id,current_time) {}

void vip_user::print_type() {
    cout<<"VIP业务用户";
}

class office_user:public user{
public:
    office_user(int id,int current_time);
    void print_type();
};

office_user::office_user(int id,int current_time):user(id,current_time) {}

void office_user::print_type() {
    cout<<"对公业务用户";
}

class bank_window{
private:
    int is_busy;
    user* client;
    int id;
public:
    bank_window(int id=0);
    int get_is_busy();
    int get_id();
    void set_id(int i);
    user* get_client();
    void hand_user(user* u,int current_time);
    void user_leave();
};

bank_window::bank_window(int id):id(id) {
    is_busy = 0;
    client = nullptr;
}

int bank_window::get_is_busy() {
    return is_busy;
}

int bank_window::get_id() {
    return id;
}

void bank_window::set_id(int i) {
    id = i;
}

user* bank_window::get_client() {
    return client;
}

void bank_window::hand_user(user *u, int current_time) {
    client = u;
    is_busy = 1;
    u->set_serve_time(current_time);
    cout<<u->get_id()<<"号";
    u->print_type();
    cout<<"开始办理业务！"<<endl;
}

void bank_window::user_leave() {
    cout<<client->get_id()<<"号"<<client->get_arrive_time()<<"秒进来的";
    client->print_type();
    cout<<"办理完业务离开！"<<endl;
    is_busy = 0;
    client = nullptr;
}

class normal_bank_window:public bank_window{
public:
    normal_bank_window(int id=0);
};

normal_bank_window::normal_bank_window(int id):bank_window(id) {}

class vip_bank_window:public bank_window{
public:
    vip_bank_window(int id=0);
};

vip_bank_window::vip_bank_window(int id):bank_window(id) {}

class office_bank_window:public bank_window{
public:
    office_bank_window(int id=0);
};

office_bank_window::office_bank_window(int id):bank_window(id) {}

class simulator{
private:
    queue<normal_user*> normal_user_queue;
    queue<vip_user*> vip_user_queue;
    queue<office_user*> office_user_queue;
    normal_bank_window* nbw;
    vip_bank_window* vbw;
    office_bank_window* obw;
    int nbw_size;
    int vbw_size;
    int obw_size;
    int nu;
    int vu;
    int ou;
    int current_time;
    int random_time;
public:
    simulator(int n,int v,int o);
    ~simulator();
    void customer_enter();
    void simulator_hand_customer();
    void start();
};

simulator::simulator(int n, int v, int o) {
    random_device rd;
    current_time = 0;
    nu = 0;
    vu = 0;
    ou = 0;
    nbw_size = n;
    vbw_size = v;
    obw_size = o;
    nbw = new normal_bank_window[nbw_size];
    vbw = new vip_bank_window[vbw_size];
    obw = new office_bank_window[obw_size];
    random_time = (rd() % 5) + 3;
    for (int i = 0; i < nbw_size; ++i) {
        nbw[i].set_id(i);
    }
    for (int i = 0; i < vbw_size; ++i) {
        vbw[i].set_id(i);
    }
    for (int i = 0; i < obw_size; ++i) {
        obw[i].set_id(i);
    }
}

simulator::~simulator() {
    delete[] nbw;
    delete[] vbw;
    delete[] obw;
}

void simulator::customer_enter() {
    random_device rd;
    for (int i = 0; i < (rd() % 5); ++i) {
        normal_user* temp = new normal_user(++nu,current_time);
        normal_user_queue.en_queue(temp);
        cout<<temp->get_id()<<"号";
        temp->print_type();
        cout<<"进入队列"<<endl;
    }
    for (int i = 0; i < (rd() % 3); ++i) {
        vip_user* temp = new vip_user(++vu,current_time);
        vip_user_queue.en_queue(temp);
        cout<<temp->get_id()<<"号";
        temp->print_type();
        cout<<"进入队列"<<endl;
    }
    for (int i = 0; i < (rd() % 3); ++i) {
        office_user* temp  = new office_user(++ou,current_time);
        office_user_queue.en_queue(temp);
        cout<<temp->get_id()<<"号";
        temp->print_type();
        cout<<"进入队列"<<endl;
    }
    random_time = (rd() % 5) + 3;
}

void simulator::simulator_hand_customer() {
    for (int i = 0; i < obw_size; ++i) {
        cout<<obw[i].get_id()+1<<"号对公业务窗口："<<endl;
        if(obw[i].get_is_busy()){
            if(current_time-obw[i].get_client()->get_serve_time()>=BUSINESS_PROCESSING_TIME){
                obw[i].user_leave();
            }
            else{
                cout<<obw[i].get_client()->get_id()<<"号";
                obw[i].get_client()->print_type();
                cout<<"正在办理业务！"<<endl;
            }
        }
        if(!obw[i].get_is_busy()){
            if(office_user_queue.get_size()){
                office_user* temp;
                office_user_queue.de_queue(temp);
                obw[i].hand_user(temp,current_time);

            }
            else if(normal_user_queue.get_size()){
                normal_user* temp;
                normal_user_queue.de_queue(temp);
                obw[i].hand_user(temp,current_time);
            }
            else{
                cout<<"当前窗口空闲！"<<endl;
            }
        }
    }
    for (int j = 0; j < vbw_size; ++j) {
        cout<<vbw[j].get_id()+1<<"号VIP业务窗口："<<endl;
        if(vbw[j].get_is_busy()){
            if(current_time-vbw[j].get_client()->get_serve_time()>=BUSINESS_PROCESSING_TIME){
                vbw[j].user_leave();
            }
            else{
                cout<<vbw[j].get_client()->get_id()<<"号";
                obw[j].get_client()->print_type();
                cout<<"正在办理业务！"<<endl;
            }
        }
        if(!vbw[j].get_is_busy()){
            if(vip_user_queue.get_size()){
                vip_user* temp;
                vip_user_queue.de_queue(temp);
                vbw[j].hand_user(temp,current_time);
            }
            else if(normal_user_queue.get_size()){
                normal_user* temp;
                normal_user_queue.de_queue(temp);
                vbw[j].hand_user(temp,current_time);

            }
            else{
                cout<<"当前窗口空闲！"<<endl;
            }
        }
    }
    for (int k = 0; k < nbw_size; ++k) {
        cout<<nbw[k].get_id()+1<<"号普通业务窗口："<<endl;
        if(nbw[k].get_is_busy()){
            if(current_time-nbw[k].get_client()->get_serve_time()>=BUSINESS_PROCESSING_TIME){
                nbw[k].user_leave();
            }
            else{
                cout<<nbw[k].get_client()->get_id()<<"号";
                nbw[k].get_client()->print_type();
                cout<<"正在办理业务！"<<endl;
            }
        }
        if(!nbw[k].get_is_busy()){
            if(normal_user_queue.get_size()){
                normal_user* temp;
                normal_user_queue.de_queue(temp);
                nbw[k].hand_user(temp,current_time);
            }
            else{
                cout<<"当前窗口空闲！"<<endl;
            }
        }
    }
}

void simulator::start() {
    while(true){
        cout<<current_time<<"秒："<<endl;
        if(current_time%random_time==0){
            customer_enter();
        }
        simulator_hand_customer();
        if(current_time==24*60*60){
            break;
        }
        current_time++;
        Sleep(2000);
    }
}

int main(){
    simulator s(3,1,1);
    s.start();
    return 0;
}