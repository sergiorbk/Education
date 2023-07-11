#ifndef LAB3_DATE_H
#define LAB3_DATE_H

#include <string>
#include <stdexcept>

using namespace std;

class Date {
private:
    string date;
    int day;
    int month;
    int year;

public:

    explicit Date(const string& input_date){
        if(!check_date(input_date)){
            throw invalid_argument("Incorrect value for date.");
        } else{
            date = input_date;
            day = stoi(input_date.substr(0, 2));
            month = stoi(input_date.substr(3, 2));
            year = stoi(input_date.substr(6, 4));
        }
    }
    //DRY
//operator -
//operator +
//operator >
//operatorn -
    //static bool check_date(const string &input_birthday);
    //static bool validate_day(const int& day, const int& month, const int& year);

    string get_date();
    [[nodiscard]] int getDay() const;
    [[nodiscard]] int getMonth() const;
    [[nodiscard]] int getYear() const;
};

#endif //LAB3_DATE_H