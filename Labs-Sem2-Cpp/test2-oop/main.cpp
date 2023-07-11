#include <iostream>
#include <string>

using namespace std;

class Student {
private:
    string first_name;
    string middle_name;
    string last_name;
    string academic_group;

public:
    // Конструктор для створення порожніх студентів
    Student(){
        count ++;
    };

    // Конструктор для створення студентів з усіма параметрами
    Student(string first_name, string middle_name, string last_name, string group){
        this->first_name = first_name;
        this->middle_name = middle_name;
        this->last_name = last_name;
        this->academic_group = group;
        count ++;
    }

    // Деструктор
    ~Student(){
        count--;
    }

    // Сетери
    void set_first_name(string first_name){
        this->first_name = first_name;
    }

    void set_middle_name(string middle_name){
        this->middle_name = middle_name;
    }

    void set_last_name(string last_name){
        this->last_name = last_name;
    }

    void set_academic_group(string academic_group){
        this->academic_group = academic_group;
    }

    // Гетери
    string get_first_name(){
        return this->first_name;
    }

    string get_middle_name(){
        return this->middle_name;
    }

    string get_last_name(){
        return this->last_name;
    }

    string get_academic_group(){
        return this->academic_group;
    }

    // метод отримання кылькості створення повідбних об'єктів
    static int get_count(){
        return count;
    }

    static int count;

    friend ostream & operator << (ostream& os, const Student& s){
        os << s.first_name << " " << s.middle_name << " " << s.last_name << " " << s.academic_group << endl;
        return os;
    }
};

// змінна для підрахунку створених екземплярів класів студент.
int Student::count = 0;

int main(){
    // Створення езмемплярів класу конструктором за параментрами
    Student s1("Rybak", "Serhii", "Mykolayovych", "IP-24");
    Student s2("Petrenko", "Petro", "Petrovich", "IP-21");
    Student s3("Dmitrenko", "Dmytro", "Dmytrovych", "IP-22");

    // Створення екземплярів порожніх студентів використовуючи базовий конструктор.
    Student s4 = Student();
    Student s5 = Student();
    Student s6 = Student();

    s4.set_first_name("Leonova");
    s4.set_middle_name("Tetyana");
    s4.set_last_name("Anatoliyivna");
    s4.set_academic_group("IP-25");

    s5.set_first_name("Ivanova");
    s5.set_middle_name("Ivanka");
    s5.set_last_name("Ivanivna");
    s5.set_academic_group("IP-21");

    s6.set_first_name("Somko");
    s6.set_middle_name("Viktoriya");
    s6.set_last_name("Ruslanivna");
    s6.set_academic_group("IP-23");

    cout << "==>> Total amount of students: " << Student::count << endl;
    cout << s1;
    cout << s2;
    cout << s3;
    cout << s4;
    cout << s5;
    cout << s6;
}