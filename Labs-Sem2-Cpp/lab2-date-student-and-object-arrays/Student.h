#ifndef LAB3_STUDENT_H
#define LAB3_STUDENT_H

#include <string>
#include "FullName.h"
#include "Date.h"
#include "Group.h"

using namespace std;

class Student {
private:
    // overengeniring
    FullName full_name;
    Group group;
    Date birthday;

public:
    Student(FullName full_name, Group group, Date birthday)
    : full_name(full_name), group(group), birthday(birthday) {}

    FullName get_full_name();

    [[maybe_unused]] bool change_full_name(const string& new_full_name);
    Group get_group();

    [[maybe_unused]] bool change_group(const string& new_group);
    Date get_birthday();

    [[maybe_unused]] bool change_birthday(const string& new_birthday);
};

#endif //LAB3_STUDENT_H
