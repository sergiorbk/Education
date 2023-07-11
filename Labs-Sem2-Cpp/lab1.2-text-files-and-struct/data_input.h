#ifndef LAB2_DATA_INPUT_H
#define LAB2_DATA_INPUT_H

#include <string>
using namespace std;

struct Appointment{
    string surname;
    string start_time;
    string end_time;
};

struct Time{
    int hours;
    int minutes;
};

int hh_mm_to_minutes(Time time);
Time get_time(const string& time);
Appointment input_appointment_info(const string& file_path);
bool check_time_format(const string& time);
void break_chat();
char call_input_form(const string& answers);

#endif //LAB2_DATA_INPUT_H
