#include "Student.h"
#include <regex>
#include <string>

bool Student::change_full_name(const string& new_full_name){
    try{
        this->full_name = FullName(new_full_name);
    }catch (exception& e){
        return false;
    }
}


[[maybe_unused]] bool Student::change_group(const string& new_group){
    try{
        this->group = Group(new_group);
    }catch (exception& e){
        return false;
    }
}

[[maybe_unused]] bool Student::change_birthday(const string& new_birthday){
    try{
        this->birthday = Date(new_birthday);
    }catch (exception& e){
        return false;
    }
}

FullName Student::get_full_name(){
    return full_name;
}

Group Student::get_group(){
    return group;
}

Date Student::get_birthday(){
    return birthday;
}