#ifndef LAB32_STUDENTSFACTORY_H
#define LAB32_STUDENTSFACTORY_H


#include "Student.h"
#include "StudentsArray.h"

class StudentsFactory { // should be abstract factory pattern of GOF
public:
    static Student create_student();
    static Date create_comparing_date();
    static void fill_students_array(StudentsArray* students);
    static bool is_exit_program();
};


#endif //LAB32_STUDENTSFACTORY_H
