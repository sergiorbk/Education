#include "StudentsArray.h"
#include <iostream>
#include <stdexcept>
#include "Student.h"

using namespace std;

void StudentsArray::add_student(Student* new_student){
    size++;
    auto new_students_array = new Student*[size]; // type: Student**
    for(int i=0; i < size - 1; i++){
        new_students_array[i] = students[i];
    }
    new_students_array[size - 1] = new_student;
    students = new_students_array;
}

bool StudentsArray::read_students_array(){
    if(size == 0){
        return false;
    }

    cout << endl << "=============== READING STUDENTS ===============" << endl << endl;
    for(int num = 0; num < size; num++){
        cout << "=============== Student [" << num << "] ===============" << endl;
        cout << "==>> Full name: " << students[num]->get_full_name().get_full_name() << endl;
        cout << "==>> Group: " << students[num]->get_group().get_group() << endl;
        cout << "==>> Birthday: " << students[num]->get_birthday().get_date() << endl;
        cout << endl;
    }
    cout << endl << "=============== READING END ===============" << endl << endl << endl;
    return true;
}

Student* StudentsArray::find_oldest_student(Date selected_date) {
    Student* oldest_student_ptr = nullptr;

    for(int num=0; num < size; num++) {
        Date curr_student_birthday = students[num]->get_birthday();

        // check does current student's date is before selected date
        if(curr_student_birthday.getYear() > selected_date.getYear()){
            continue;
        }
        // date compare logic is date responcebility date operator - > 0
        if(curr_student_birthday.getYear() == selected_date.getYear()){
            if(curr_student_birthday.getMonth() > selected_date.getMonth()){
                continue;
            }else if(curr_student_birthday.getMonth() == selected_date.getMonth()){
                if(curr_student_birthday.getDay() > selected_date.getDay()){
                    continue;
                }
            }
        }

        // oldest student check part
        if(oldest_student_ptr != nullptr){
            Date oldest_user_date = oldest_student_ptr->get_birthday();
            if(oldest_user_date.getYear() > curr_student_birthday.getYear()){
                continue;
            }

            if(oldest_user_date.getYear() == curr_student_birthday.getYear()){
                if(oldest_user_date.getMonth() > curr_student_birthday.getMonth()){
                    continue;
                }else if(oldest_user_date.getMonth() == curr_student_birthday.getMonth()){
                    if(oldest_user_date.getDay() > curr_student_birthday.getDay()){
                        continue;
                    }
                }
            }

            oldest_student_ptr = students[num];
            // in case of ptr of the oldest student is nullptr
        }else{
            oldest_student_ptr = students[num];
            continue;
        }
    }

    if (oldest_student_ptr != nullptr) {
        cout << endl << "==>> The oldest student on " << selected_date.get_date() <<
        " is " << oldest_student_ptr->get_full_name().get_full_name() <<
        " (" << oldest_student_ptr->get_birthday().get_date() << ")" << endl;
    } else {
        cout << "No student found" << endl;
    }
    return oldest_student_ptr;
}