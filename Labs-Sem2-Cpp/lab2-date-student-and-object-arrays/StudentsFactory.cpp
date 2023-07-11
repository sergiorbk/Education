#include "StudentsFactory.h"
#include <iostream>
#include <conio.h>
using namespace std;

Student StudentsFactory::create_student(){
    FullName* full_name_ptr;
    Group* group_ptr;
    Date* birthday_ptr;

    while(true){
        string input_full_name_str;
        cout << "==>>Enter student's full name: ";
        getline(cin, input_full_name_str);

        try{
            full_name_ptr = new FullName(input_full_name_str);
            break;
        }catch (invalid_argument& e){
            continue;
        }
    }

    while(true){
        string input_group_str;
        cout << "==>>Enter student's group (IP-24): ";
        getline(cin, input_group_str);

        try{
            group_ptr = new Group(input_group_str);
            break;
        }catch (invalid_argument& e){
            continue;
        }
    }

    while(true){
        string input_birthday_str;
        cout << "==>>Enter student's birthday (11-11-2011): ";
        getline(cin, input_birthday_str);

        try{
            birthday_ptr = new Date(input_birthday_str);
            break;
        }catch (invalid_argument& e){
            continue;
        }
    }
    Student student(*full_name_ptr, *group_ptr, *birthday_ptr);

    delete full_name_ptr;
    delete group_ptr;
    delete birthday_ptr;

    return student;
}

Date StudentsFactory::create_comparing_date(){
    while(true){
        string comparing_date_str;
        cout << "==>> Enter a comparing date to find the oldest student: ";
        getline(cin, comparing_date_str);
        try{
            return Date(comparing_date_str);
        }catch (invalid_argument& e){
            cout << "Invalid argument for Date." << endl;
            continue;
        }
    }
}

void StudentsFactory::fill_students_array(StudentsArray* students){
    // filling students' array
    while(true){
        auto new_student_ptr = new Student(StudentsFactory::create_student()); // type: Student*
        students->add_student(new_student_ptr);

        cout << endl << "==>> Enter press any key to create another student or 2 to exit..." << endl;
        if(getch() == '2'){
            cout << endl;
            break;
        }else{
            cout << "============================================================" << endl << endl;
        }
    }
}

bool StudentsFactory::is_exit_program() {
    cout << endl << "Press 1 to continue or 2 to exit: " << endl;
    if (getch() == '2') {
        return true;
    } else {
        return false;
    }
}