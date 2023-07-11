#include "Group.h"
#include <regex>
//GroupValidationRule : ValidationRule
//bool isValid (Student s,string & message);
//NameValidationRule : ValidationRule
//bool isValid (Student s,string & message);
//DateValidationRule : ValidationRule
//bool isValid (Student s,string & message);


//StudentValidationService
//       ValidationRule ** validators;
//ctor() {
//    validators.Add(GroupValidationRule);
//    validators.Add(NameValidationRule);

//    validators.Add(DateValidationRule);
//}
//bool validate(string & message) {foreach () {validators[i].Validate(Student, message)}};

bool Group::check_group(const string& input_group){
    if(input_group.length() > 5){
        return false;
    }

    if(input_group[2] != '-'){
        return false;
    }

    regex group_cipher_pattern("[a-zA-Zа-яА-ЯіІїЇєЄ]+");
    if(!regex_match(input_group.substr(0, 2), group_cipher_pattern)){
        return false;
    }

    if(!isdigit(input_group[3]) || !isdigit(input_group[4])){
        return false;
    }

    return true;
}

string Group::get_group(){
    return group;
}