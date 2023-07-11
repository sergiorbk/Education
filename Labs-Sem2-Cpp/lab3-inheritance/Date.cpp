#include "Date.h"
using namespace std;

// a constructor
Date::Date(const string& date_str){
    if(!check_date(date_str)){
        throw invalid_argument("Incorrect value for date.");
    } else{
        day = stoi(date_str.substr(0, 2));
        month = stoi(date_str.substr(3, 2));
        year = stoi(date_str.substr(6, 4));
    }
}

Date::Date(const int &day, const int &month, const int &year) {
    if(!check_date(day, month, year)){
        throw (invalid_argument("Error: invalid arguments for creating a Date object"));
    }else{
        this->day = day;
        this->month = month;
        this->year = year;
    }
}

bool Date::check_date(const int &day_to_check, const int &month_to_check, const int &year_to_check) {
    if(day_to_check < 1 || day_to_check > 31 || month_to_check < 1 || month_to_check > 12 || year_to_check < 1000 || year_to_check > 9999){
        return false;
    }

    if(!validate_day(day_to_check, month_to_check, year_to_check)){
        return false;
    }

    return true;
}


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

    const int day_to_check = stoi(input_birthday.substr(0, 2));
    const int month_to_check = stoi(input_birthday.substr(3, 2));
    const int year_to_check = stoi(input_birthday.substr(6, 4));

    if(day_to_check < 1 || day_to_check > 31 || month_to_check < 1 || month_to_check > 12 || year_to_check < 1000 || year_to_check > 9999){
        return false;
    }

    if(!validate_day(day_to_check, month_to_check, year_to_check)){
        return false;
    }
    return true;
}


bool Date::validate_day(const int& day_to_check, const int& month_to_check, const int& year_to_check){

    if(day_to_check < 1){
        return false;
    }

    if (month_to_check == 2)
    {
        if ((year_to_check % 4 == 0 && year_to_check % 100 != 0) || year_to_check % 400 == 0)
        {
            if(day_to_check > 29){
                return false;
            }
        }
        else
        {
            if(day_to_check > 28){
                return false;
            }
        }
    }
    else if (month_to_check == 4 || month_to_check == 6 || month_to_check == 9 || month_to_check == 11)
    {
        if(day_to_check > 30){
            return false;
        }
    }
    else
    {
        if(day_to_check > 31){
            return false;
        }
    }

    return true;
}

[[maybe_unused]] int Date::get_day() const{
    return day;
}

[[maybe_unused]] int Date::get_month() const{
    return month;
}

[[maybe_unused]] int Date::get_year() const{
    return year;
}

bool Date::operator>=(const Date &another_date) const {
    if(year >= another_date.year){
        if(month >= another_date.month){
            if(day >= another_date.day){
                return true;
            }else{
                return false;
            }
        }else{
            return false;
        }
    }else{
        return false;
    }
}

bool Date::operator<=(const Date &another_date) const {
    if(year <= another_date.year){
        if(month <= another_date.month){
            if(day <= another_date.day){
                return true;
            }else{
                return false;
            }
        }else{
            return false;
        }
    }else{
        return false;
    }
}

bool Date::operator>(const Date &another_date) const {
    if(year > another_date.year){
        return true;
    } else if(year == another_date.year && month > another_date.month){
        return true;
    } else if(month == another_date.month && day > another_date.day){
        return true;
    } else{
        return false;
    }
}

bool Date::operator<(const Date &another_date) const {
    if(year < another_date.year){
        return true;
    } else if(year == another_date.year && month < another_date.month){
        return true;
    } else if(month == another_date.month && day < another_date.day){
        return true;
    } else{
        return false;
    }
}

bool Date::operator==(const Date &another_date) const {
    if(year == another_date.year && month == another_date.month && day == another_date.day){
        return true;
    }else{
        return false;
    }
}

Date Date::operator+(int days_to_add) const {
    Date new_date(day, month, year);
    int max_days;
    while (days_to_add > 0) {
        max_days = get_max_days(new_date.month, new_date.year);
        if (new_date.day + days_to_add <= max_days) {
            new_date.day += days_to_add;
            days_to_add = 0;
        } else {
            days_to_add -= max_days - new_date.day + 1;
            new_date.day = 1;
            if (new_date.month == 12) {
                new_date.month = 1;
                new_date.year += 1;
            } else {
                new_date.month += 1;
            }
        }
    }
    return new_date;
}



int Date::get_max_days(const int &month, const int &year) {
    if (month == 2){
        if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0){
            return 29;
        }else{
            return 28;
        }
    }
    else if (month == 4 || month == 6 || month == 9 || month == 11){
        return 30;
    }
    else{
        return 31;
    }
}

string Date::to_string() const {
    return ::to_string(day) + '-' + ::to_string(month) + '-'+ ::to_string(year);
}

