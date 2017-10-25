#include <iostream>
#include <windows.h>
#include <fstream>
#include <cassert>

using namespace std;

int Strlen(char *s) {
    int n = 0;
    while (*s != '\0') {
        n++;
        s++;
    }
    return n;
}

class String {
private:
    char* str;
    int size;
public:
    String();
    String(char* s);
    ~String();
    int Size();
    String& operator = (String s);
    String& operator = (char *s);
    String& operator + (String&s);
    String& operator += (String& s);
    String& operator += (char* s);
    String& operator += (char s);
    friend ostream& operator<<(ostream& out, const String& s);
    friend istream  &operator>>(istream &is, String &s);
    char& operator[](int i);
    String substr(int index, int l);
    char* get_str();
    int naive_str_matching(String p);
};

int String::naive_str_matching(String p) {
    int i = 0, j = 0, p_length = p.Size(), t_length = size;
    if (t_length<p_length) {
        return -1;
    }
    while (i<t_length&&j<p_length) {
        if (str[i] == p[j]) {
            i++;
            j++;
        }
        else {
            i = i - j + 1;
            j = 0;
        }
    }
    if (j == p_length) {
        return i - j;
    }
    else {
        return -1;
    }
}

String::String() {
    str = nullptr;
    size = 0;
}

String::String(char *s) {
    if (size == Strlen(s)) {
        str = s;
    }
    else {
        delete str;
        size = Strlen(s);
        str = new char[size + 1];
        for (int i = 0; i < size; ++i) {
            str[i] = s[i];
        }
        str[size] = '\0';
    }
}

String::~String() {
    //delete[](str);
}

int String::Size() {
    return size;
}

char& String::operator[](int i) {
    if (i >= size || i<0) {
        cout << "Array out of bounds!" << endl;
        char s = '0';
        return s;
    }
    else {
        return str[i];
    }
}

String& String::operator+(String &s) {
    char *new_string = new char[s.Size() + size + 1];
    for (int i = 0; i<s.Size() + size + 1; ++i) {
        if (i<size) {
            new_string[i] = str[i];
        }
        else if (i == s.Size() + size) {
            new_string[i] = '\0';
        }
        else {
            new_string[i] = s[i - size];
        }
    }
    String temp = new_string;
    return temp;
}

String& String::operator=(String s) {
    size = s.Size();
    delete str;
    str = new char[size + 1];
    int i = 0;
    for (i = 0; i<size; ++i) {
        str[i] = s[i];
    }
    str[i] = '\0';
    return *this;
}

String& String::operator=(char *s) {
    if (size == Strlen(s)) {
        str = s;
    }
    else {
        delete str;
        size = Strlen(s);
        str = new char[size + 1];
        str = s;
        str[size + 1] = '\0';
    }
    return *this;
}

String& String::operator+=(String &s) {
    char *temp = str;
    size += s.Size();
    str = new char[size + 1];
    int i = 0;
    for (i = 0; i<size; ++i) {
        if (i<size - s.Size()) {
            str[i] = temp[i];
        }
        else {
            str[i] = s[i - size + s.Size()];
        }
    }
    str[i] = '\0';
    delete[](temp);
    return *this;
}

String& String::operator+=(char *s) {
    char *temp = str;
    int s_length = Strlen(s);
    size += s_length;
    str = new char[size + 1];
    int i = 0;
    for (i = 0; i<size; ++i) {
        if (i<size - s_length) {
            str[i] = temp[i];
        }
        else {
            str[i] = s[i - size + s_length];
        }
    }
    str[i] = '\0';
    delete[](temp);
    return *this;
}

String& String::operator+=(char s) {
    char *temp = str;
    size += 1;
    str = new char[size + 1];
    int i = 0;
    for (i = 0; i<size; ++i) {
        if (i<size - 1) {
            str[i] = temp[i];
        }
        else {
            str[i] = s;
        }
    }
    str[i] = '\0';
    delete[](temp);
    return *this;
}

ostream& operator<<(ostream& out, const String& s) {
    out << s.str;
    return out;
}

istream &operator>>(istream &is, String &s) {
    char *a = new char[1024];
    is >> a;
    s = a;
    return is;
}

String String::substr(int index, int l) {
    int left = size - index;
    String temp;
    if (l>left || left < 0) {
        cout << "error length!";
        return temp;
    }
    else {
        for (int i = 0; i< l; ++i) {
            temp += str[index + i];
        }
        return temp;
    }
}


char* String::get_str() {
    return str;
}

template <class T>
class link_node {
private:
    T *item;
    link_node<T>* next;
public:
    link_node(T *n, link_node<T>* nt = nullptr);
    T* get_item();
    void set_item(T *n);
    link_node<T>* get_next();
    void set_next(link_node<T>* ne);
};

template <class T>
link_node<T>::link_node(T* n, link_node* nt) {
    item = n;
    next = nt;
}

template <class T>
T* link_node<T>::get_item() {
    return item;
}

template <class T>
void link_node<T>::set_item(T* n) {
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
class link_list {
private:
    link_node<T>* head;
    link_node<T>* tail;
public:
    link_list();
    ~link_list();
    bool add(T* item);
    void show();
    bool print(char* file_path);
    T* get_line(int line);
    void insert_one(int l, T* n);
    void delete_one(int l);
    int Size();
};

template <class T>
link_list<T>::link_list() {
    head = tail = 0;
}

template <class T>
link_list<T>::~link_list() {
    while (head) {
        tail = head;
        head = head->get_next();
        delete tail;
    }
}

template <class T>
bool link_list<T>::add(T* item) {
    link_node<T>* new_node = new link_node<T>(item, nullptr);
    if (!head) {
        head = tail = new_node;
    }
    else {
        tail->set_next(new_node);
        tail = tail->get_next();
    }
    return true;
}

template <class T>
void link_list<T>::show() {
    link_node<T> *temp = head;
    while (temp) {
        cout << *(temp->get_item()) << endl;
        temp = temp->get_next();
    }
}

template <class T>
bool link_list<T>::print(char* file_path) {
    ofstream file_out;
    file_out.open(file_path, ios::out | ios::app);
    link_node<T> *temp = head;
    while (temp) {
        file_out << *(temp->get_item()) << endl;
        temp = temp->get_next();
    }
    file_out.close();
    return true;
}

template <class T>
T* link_list<T>::get_line(int line) {
    int i = 0;
    link_node<T> *temp = head;
    while (temp) {
        if (line == i) {
            break;
        }
        temp = temp->get_next();
        i++;
    }
    return temp->get_item();
}

template <class T>
void link_list<T>::insert_one(int l, T *n) {
    int i = 0;
    link_node<T> *temp = head;
    while (temp) {
        if (l-1 == i) {
            break;
        }
        temp = temp->get_next();
        i++;
    }
    link_node<T>* new_node = new link_node<T>(n);
    new_node->set_next(temp->get_next());
    temp->set_next(new_node);
}

template <class T>
void link_list<T>::delete_one(int l) {
    int i = 0;
    link_node<T> *temp = head,*d;
    if (l >= 1) {
        while (temp) {
            if (l - 1 == i) {
                break;
            }
            temp = temp->get_next();
            i++;
        }
        d = temp->get_next();
        temp->set_next(d->get_next());
        delete d;
    }
    else {
        head = head->get_next();
        delete temp;
    }
}

template<class T>
int link_list<T>::Size() {
    int i = 0;
    link_node<T> *temp = head;
    while (temp) {
        temp = temp->get_next();
        i++;
    }
    return i;
}

class text_editor {
private:
    link_list<String> article;
    String name;
    int total_words;
    int line;
    short cursor_x;
    short cursor_y;
    void set_cursor(short x, short y);
public:
    text_editor();
    ~text_editor();
    String get_name();
    bool set_name(String n);
    bool get_text_from_file(char* file_path);
    bool save_text_to_file(char* file_path);
    bool search();
    bool insert_one_word(char c);
    bool delete_one_word();
    int word_stst();
    void srart();
    bool move_cursor(int i, int j);
    void rename_file();
};

text_editor::text_editor() {
    total_words = 0;
    cursor_x = 0;
    cursor_y = 1;
    line = 0;
    set_cursor(0, 0);
}

text_editor::~text_editor() {}

bool text_editor::move_cursor(int i, int j) {
    if (i == -1) {
        cursor_x == 0 ? cursor_x = 0 : cursor_x--;
    }
    if (i == 1) {
        String *temp = article.get_line(cursor_y - 1);
        if (cursor_x < temp->Size()) {
            cursor_x++;
        }
    }
    if (j == -1) {
        cursor_y <= 1 ? cursor_y = 1 : cursor_y--;
        String *temp = article.get_line(cursor_y - 1);
        if (cursor_x > temp->Size()) {
            cursor_x= temp->Size();
        }
    }
    if (j == 1) {
        if (cursor_y <= line) {
            cursor_y++;
        }
        String *temp = article.get_line(cursor_y - 1);
        if (cursor_x >temp->Size()) {
            cursor_x = temp->Size();
        }
    }
    set_cursor(cursor_x, cursor_y);
    return true;
}

String text_editor::get_name() {
    return name;
}

bool text_editor::set_name(String n) {
    if (n.Size() <= 0) {
        return false;
    }
    else {
        name = n;
        return true;
    }
}

bool text_editor::get_text_from_file(char* file_path) {
    ifstream infile;
    infile.open(file_path);
    assert(infile.is_open());   //若失败,则输出错误消息,并终止程序运行

    char c;
    infile >> noskipws;
    String *temp = new String;
    infile >> c;
    while (!infile.eof()) {
        if (c == '\n') {
            line++;
            article.add(temp);
            temp = new String;
        }
        else {
            (*temp) += c;
        }
        infile >> c;
    }
    article.add(temp);
    return true;
}

bool text_editor::save_text_to_file(char *file_path) {
    DeleteFile(file_path);
    article.print(file_path);
    return true;
}

void text_editor::set_cursor(short x, short y) {
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(hOut, pos);
}

bool text_editor::insert_one_word(char c) {
    if (c == '\n') {
        String* temp = article.get_line(cursor_y - 1);
        String *temp_left = new String, *temp_right = new String;
        *temp_left = temp->substr(0, cursor_x);
        *temp_right = temp->substr(cursor_x, temp->Size() - cursor_x);
        line++;
        *temp = *temp_left;
        article.insert_one(cursor_y, temp_right);
        cursor_y++;
        cursor_x = 0;
    }
    else {
        String* temp = article.get_line(cursor_y - 1);
        String temp_left, temp_right;
        temp_left = temp->substr(0, cursor_x);
        temp_right = temp->substr(cursor_x, temp->Size() - cursor_x);
        *temp = temp_left;
        *temp += c;
        *temp += temp_right;
    }
    return true;
}

bool text_editor::delete_one_word() {
    if (cursor_x == 0) {
        if (cursor_y == 1) {
            article.delete_one(cursor_y - 1);
        }
        else {
            String* temp1 = article.get_line(cursor_y - 2);
            String* temp2 = article.get_line(cursor_y - 1);
            cursor_x = temp1->Size();
            *temp1 += *temp2;
            cursor_y--;
            article.delete_one(cursor_y);
        }
    }
    else {
        String* temp = article.get_line(cursor_y - 1);
        String temp_left, temp_right;
        temp_left = temp->substr(0, cursor_x-1);
        temp_right = temp->substr(cursor_x, temp->Size() - cursor_x);
        cursor_x--;
        *temp = temp_left;
        *temp += temp_right;
    }
    return true;
}

bool text_editor::search() {
    system("cls");
    cout << "pleas input a string:";
    String s;
    cin >> s;
    for (int i = 0; i <= line; ++i) {
        String *temp = article.get_line(i);
        if (temp->naive_str_matching(s) >= 0) {
            cursor_x = temp->naive_str_matching(s);
            cursor_y = i + 1;
            break;
        }
    }
    return true;
}

int text_editor::word_stst() {
    total_words = 0;
    for (int i = 0; i<=line; ++i) {
        total_words += article.get_line(i)->Size();
    }
    return total_words;
}

void text_editor::rename_file() {
    system("cls");
    cout << "pleas input the new name:";
    String s;
    cin >> s;
    set_name(s);
}

void text_editor::srart() {
    bool edit_mode = false;//编辑模式 false时为命令模式 true时为编辑模式
    system("cls");
    cout << "欢迎使用该文本编辑器" << endl;
    cout << "请输入文件名称及目录，与该软件同目录可省略不写：";
    cin >> name;
    get_text_from_file(name.get_str());
    word_stst();
    system("cls");
    // 获取标准输入输出设备句柄
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    HANDLE hIn = GetStdHandle(STD_INPUT_HANDLE);

    DWORD           dwRes, dwState = 0;
    INPUT_RECORD    keyRec;
    COORD           crHome = { 0, 0 }, crPos;
    bool            bCaps, bNum, bScroll;
    char            ch;
    CONSOLE_SCREEN_BUFFER_INFO bInfo;

    cout << "name:" << name << " total_words:" << total_words<<" edit mode:"<< edit_mode << endl;
    set_cursor(0, 1);
    article.show();
    set_cursor(cursor_x, cursor_y);
    char c;
    while (1)     // 消息循环
    {
        ReadConsoleInput(hIn, &keyRec, 1, &dwRes);
        if (keyRec.EventType == KEY_EVENT)
        {
            // 只在按下时判断，弹起时不判断
            if (keyRec.Event.KeyEvent.bKeyDown)
            {

                // -- 基础功能键
                switch (keyRec.Event.KeyEvent.wVirtualKeyCode)
                {
                    case VK_RETURN:         // 按回车时跳到下一行
                        if (edit_mode == true) {
                            c = '\n';
                            insert_one_word(c);
                            system("cls");
                            cout << "name:" << name << " total_words:" << total_words << " edit mode:" << edit_mode << endl;
                            article.show();
                            set_cursor(cursor_x, cursor_y);
                        }
                        break;

                    case VK_SPACE:          // 按空格时输出一个空格
                        if (edit_mode == true) {
                            c = 32;
                            insert_one_word(c);
                            system("cls");
                            cout << "name:" << name << " total_words:" << total_words << " edit mode:" << edit_mode << endl;
                            article.show();
                            set_cursor(++cursor_x, cursor_y);
                        }
                        break;
                    case VK_BACK:           // 按删除时删掉一个字符(只能当前行操作)
                        if (edit_mode == true) {
                            delete_one_word();
                            system("cls");
                            cout << "name:" << name << " total_words:" << total_words << " edit mode:" << edit_mode << endl;
                            article.show();
                            set_cursor(cursor_x, cursor_y);
                        }
                        break;

                    case VK_ESCAPE:
                        if (edit_mode == true) {
                            edit_mode = false;
                            system("cls");
                            cout << "name:" << name << " total_words:" << total_words << " edit mode:" << edit_mode << endl;
                            article.show();
                            set_cursor(cursor_x, cursor_y);
                        }
                        break;
                    case VK_UP:
                        move_cursor(0, -1);
                        break;
                    case VK_DOWN:
                        move_cursor(0, 1);
                        break;
                    case VK_LEFT:
                        move_cursor(-1, 0);
                        break;
                    case VK_RIGHT:
                        move_cursor(1, 0);
                        break;
                    default:
                        break;
                }

                // -- 打印字符
                ch = keyRec.Event.KeyEvent.uChar.AsciiChar;

                // 输出可以打印的字符（详参ASCII表）
                if (ch>0x20 && ch<0x7e)
                {
                    if (edit_mode == false) {
                        switch (ch) {
                            case 'a':
                                edit_mode = true;
                                system("cls");
                                cout << "name:" << name << " total_words:" << total_words << " edit mode:" << edit_mode << endl;
                                article.show();
                                set_cursor(cursor_x, cursor_y);
                                break;
                            case 'q':
                                break;
                            case 'w':
                                save_text_to_file(name.get_str());
                                break;
                            case 's':
                                search();
                                system("cls");
                                cout << "name:" << name << " total_words:" << total_words << " edit mode:" << edit_mode << endl;
                                article.show();
                                set_cursor(cursor_x, cursor_y);
                            case 'r':
                                rename_file();
                                system("cls");
                                cout << "name:" << name << " total_words:" << total_words << " edit mode:" << edit_mode << endl;
                                article.show();
                                set_cursor(cursor_x, cursor_y);
                            default:
                                break;
                        }
                    }
                    else {
                        insert_one_word(ch);
                        system("cls");
                        cout << "name:" << name << " total_words:" << total_words << " edit mode:" << edit_mode << endl;
                        article.show();
                        cursor_x++;
                        set_cursor(cursor_x, cursor_y);
                    }
                }
            }
        }
    }
}

int main() {
    system("cls");
    text_editor a;
    a.srart();
    return 0;
}