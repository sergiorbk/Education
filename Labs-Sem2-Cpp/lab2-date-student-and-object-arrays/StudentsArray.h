#ifndef STUDENTS_ARRAY_H
#define STUDENTS_ARRAY_H

#include "Student.h"

class StudentsArray{
private:
    Student** students;
    int size;

public:
    StudentsArray(){
        students = nullptr;
        size = 0;
    }

    ~StudentsArray(){
        for (int i = 0; i < size; i++) {
            delete students[i];
        }

        delete[] students;
    }

    void add_student(Student* new_student);
    Student* find_oldest_student(Date selected_date);
    bool read_students_array();
};

#endif // STUDENTS_ARRAY_H
