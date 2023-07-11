#include "FullName.h"
#include <iostream>
#include <regex>

bool FullName::check_full_name(const string& input_name){
    regex pattern("[a-zA-Zа-яА-ЯіІїЇєЄ ]+");
    if(!regex_match(input_name, pattern)){
        cout << "Error: Full name contains rejected symbols." << endl;
        return false;
    }

    if(input_name.length() < 5){
        return false;
    }

    int spaces_num = 0;
    for(char c: input_name){
        if(c == ' '){
            spaces_num++;
        }
    }
    if(spaces_num != 2){
        return false;
    }

    return true;
}

string FullName::get_full_name(){
    return full_name;
}
