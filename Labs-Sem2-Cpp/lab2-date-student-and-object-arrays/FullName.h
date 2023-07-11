#ifndef LAB31_FULLNAME_H
#define LAB31_FULLNAME_H

#include <string>
#include <stdexcept>

using namespace std;
//read about fluent validator
// chain of responcebility (GOF pattern)
class FullName {

private:
    string full_name;

public:
    FullName(string input_full_name){
        if(!check_full_name(input_full_name)){
            throw invalid_argument("Invalid value for full name.");
        }else{
            full_name = input_full_name;
        }
    }

    static bool check_full_name(const string& input_name);
    string get_full_name();
};


#endif //LAB31_FULLNAME_H
