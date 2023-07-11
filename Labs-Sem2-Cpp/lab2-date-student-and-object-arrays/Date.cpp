#include "Date.h"

bool Date::check_date(const string &input_birthday) {
    if(input_birthday.length() != 10){
        return false;
    }

    if(input_birthday[2] != '-' || input_birthday[5] != '-'){
        return false;
    }

    int num_indexes[8] = {0, 1, 3, 4, 6, 7, 8,9};
    for(int index: num_indexes){
        if(!isdigit(input_birthday[index])){
            return false;
        }
    }

    const int day = stoi(input_birthday.substr(0, 2));
    const int month = stoi(input_birthday.substr(3, 2));
    const int year = stoi(input_birthday.substr(6, 4));

    if(day < 1 || day > 31 || month < 1 || month > 12 || year < 1000 || year > 9999){
        return false;
    }

    if(!validate_day(day, month, year)){
        return false;
    }
    return true;
}

bool Date::validate_day(const int& day, const int& month, const int& year){

    if(day < 1){
        return false;
    }

    if (month == 2)
    {
        if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        {
            if(day > 29){
                return false;
            }
        }
        else
        {
            if(day > 28){
                return false;
            }
        }
    }
    else if (month == 4 || month == 6 || month == 9 || month == 11)
    {
        if(day > 30){
            return false;
        }
    }
    else
    {
        if(day > 31){
            return false;
        }
    }

    return true;
}

string Date::get_date() {
    return date;
}

int Date::getDay() const{
    return day;
}

int Date::getMonth() const{
    return month;
}

int Date::getYear() const{
    return year;
}