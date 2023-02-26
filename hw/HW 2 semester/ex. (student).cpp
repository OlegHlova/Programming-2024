#include <iostream>
using namespace std;
class Student {
private:
    string name;
    string group_name;
    int id;
public:
    Student() : name(" "), group_name(" "), id(0) {

    }
    Student(string n, string g_n, int i) : name(n), group_name(g_n), id(i) {

    }
    string Get_Name() {
        return name;
    }
    string Get_Group_name() {
        return group_name;
    }
    int Get_id() {
        return id;
    }
    void Set_Name(string new_name) {
        name = new_name;
    }
    void Set_group_name(string new_group_name) {
        group_name = new_group_name;
    }
    void Set_id(int new_id) {
        id = new_id;
    }
    void Input() {
        cout << "Enter name: " << endl;
        cin >> name;
        cout << "Enter name of group: " << endl;
        cin >> group_name;
        cout << "Enter id : " << endl;
        cin >> id;
    }
    void Print() {
        cout << "Name -- " << name << endl;
        cout << "Group -- " << group_name << endl;
        cout << "Id -- " << id << endl;
    }


};
Student* sort_array(Student* array, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (array[i].Get_id() > array[j].Get_id()) {
                Student temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
    return array;
}
int main() {
    int n;
    string group, name;
    string name_id;
    int id;
    cout << "Enter a count of students: " << endl;
    cin >> n;
    Student* array = new Student[n];
    for (int i = 0; i < n; ++i) {
        array[i].Input();
    }
    cout << "-----" << endl;
    cout << "Enter looking for group" << endl;
    cin >> group;
    for (int i = 0; i < n; ++i) {
        if (group == array[i].Get_Group_name()) {
            cout << "Name: " << endl;
            cout << array[i].Get_Name() << endl;
        }
    }
    cout << "-----" << endl;
    cout << "Enter looking for name" << endl;
    cin >> name;
    for (int i = 0; i < n; ++i) {
        if (name == array[i].Get_Name()) {
            array[i].Print();
            cout << endl;
        }
    }
    cout << "-----" << endl;
    cout << "Enter name for change id:" << endl;
    cin >> name_id;
    cout << "Enter new id" << endl;
    cin >> id;
    for (int i = 0; i < n; ++i) {
        if (name_id == array[i].Get_Name()) {
            array[i].Set_id(id);
        }
    }
    cout << "-----" << endl;


    array = sort_array(array, n);
    for (int i = 0; i < n; ++i) {
        array[i].Print();
    }


    return 0;
}