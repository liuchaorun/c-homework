//#include <iostream>
//#include <string>
//
//#define student_number 5
//
//using namespace std;
//
//class student {
//private:
//    string name;
//    int score;
//public:
//    student();
//
//    ~student();
//
//    void set_name(string n);
//
//    void set_score(int s);
//
//    string get_name();
//
//    int get_score();
//};
//
//student::student() {
//    name = "please input the name";
//    score = 0;
//}
//
//student::~student() {}
//
//void student::set_name(string n) {
//    name = n;
//}
//
//void student::set_score(int s) {
//    score = s;
//}
//
//string student::get_name() {
//    return name;
//}
//
//int student::get_score() {
//    return score;
//}
//
//class manager {
//private:
//    student stu[student_number];
//public:
//    manager();
//
//    ~manager();
//
//    void print();
//};
//
//manager::manager() {
//    string n;
//    int s;
//    cout << "������ѧ�������ͳɼ���" << endl;
//    for (int i = 0; i < student_number; ++i) {
//        cout << "��" << i + 1 << "λ��" << "\n������";
//        cin >> n;
//        cout << "�ɼ���";
//        cin >> s;
//        stu[i].set_name(n);
//        stu[i].set_score(s);
//    }
//}
//
//manager::~manager() {
//
//}
//
//void manager::print() {
//    student a;
//    int k = 0, total = 0;
//    for (int i = 0; i < student_number; ++i) {
//        for (int j = i + 1; j < student_number; ++j) {
//            if (stu[i].get_score() > stu[j].get_score()) {
//                a = stu[i];
//                stu[i] = stu[j];
//                stu[j] = a;
//            }
//        }
//    }
//    cout << "�ɼ���" << endl;
//    for (int i = 0; i < student_number; ++i) {
//        cout << "������" << stu[i].get_name() << "�ɼ���" << stu[i].get_score() << endl;
//    }
//    cout << "��������" << student_number;
//    cout << "��߷֣�" << stu[student_number - 1].get_score() << endl;
//    cout << "��ͷ֣�" << stu[0].get_score() << endl;
//    for (int i = 0; i < student_number; i++) {
//        total += stu[i].get_score();
//    }
//    cout << "ƽ���֣�" << total / student_number << endl;
//    for (int i = 1; i < student_number; ++i) {
//        if (stu[i].get_score() < 60)
//            k++;
//    }
//    cout << "������������" << k << endl;
//
//}
//
//int main() {
//    manager c;
//    c.print();
//    system("pause");
//    return 0;
//}