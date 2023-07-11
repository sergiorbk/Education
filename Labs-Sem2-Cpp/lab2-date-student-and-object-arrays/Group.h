#ifndef LAB31_GROUP_H
#define LAB31_GROUP_H

#include <string>
#include <stdexcept>

using namespace std;

class Group {
private:
    string group;

    string id;
    [[maybe_unused]] int number;

public:
    explicit Group(const string& input_group){
        if(!check_group(input_group)){
            throw invalid_argument("Invalid value for group.");
        }else{
            group = input_group;
            id = input_group.substr(0, 2);
            number = stoi(input_group.substr(3, 2));
        }
    }

    static bool check_group(const string& input_group);
    string get_group();
};


#endif //LAB31_GROUP_H
