#ifndef LAB3_DATE_H
#define LAB3_DATE_H

#include <string>
#include <stdexcept>

using namespace std;

class Date {
public:
    // a constructor
    explicit Date(const string& date_str);
    Date(const int& day, const int& month, const int& year);

    // operators
    Date operator +(int days_to_add) const;

    bool operator ==(const Date& another_date) const;
    bool operator >(const Date& another_date) const;
    bool operator <(const Date& another_date) const;
    bool operator >=(const Date& another_date) const;
    bool operator <=(const Date& another_date) const;

    [[nodiscard]] string to_string() const;

    [[maybe_unused]] [[nodiscard]] int get_day() const;
    [[maybe_unused]] [[nodiscard]] int get_month() const;
    [[maybe_unused]] [[nodiscard]] int get_year() const;

private:
    int day;
    int month;
    int year;

    static bool check_date(const string &input_birthday);
    static bool check_date(const int& day_to_check, const int& month_to_check, const int& year_to_check);
    static bool validate_day(const int& day_to_check, const int& month_to_check, const int& year_to_check);
    static int get_max_days(const int &month, const int &year);
};


#endif //LAB3_DATE_H
