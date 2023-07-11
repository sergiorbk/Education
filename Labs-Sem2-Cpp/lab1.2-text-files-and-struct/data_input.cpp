#include "data_input.h"
#include "format_func.h"
#include <iostream>
#include <regex>
#include <conio.h>


Appointment input_appointment_info(const string& file_path){
    Appointment* appointments = nullptr;
    int records_amount = read_records(file_path, &appointments);

    regex pattern("[a-zA-Zа-яА-ЯіІїЇєЄ]+");
    string surname;

    do{
        cout << "==>> Enter a surname: ";
        cin >> surname;
        if(!regex_match(surname, pattern) && surname.length() >= 1 || surname.length()<=0){
            cout << "Error: input surname contains restricted symbols." << endl << endl;
            continue;
        }

        bool is_same_surname_exists = false;
        for(int i=0; i < records_amount; i++){
            if(surname == appointments[i].surname){
                cout << "Error: a client with surname " << surname << " is already exists." << endl << endl;
                is_same_surname_exists = true;
                break;
            }
       }
        if(is_same_surname_exists){
            continue;
        }

        break;
    }while(true);

    string start_time;
    string end_time;
    do{
        // start time check
        do{
            cout << "==>> Enter the time of start (hh:mm): ";
            cin >> start_time;
            if(!check_time_format(start_time)){
                cout << "Error: Invalid time format." << endl << endl;
                continue;
            }
            if(records_amount > 0){
                if(hh_mm_to_minutes(get_time(start_time)) < hh_mm_to_minutes(get_time(appointments[records_amount-1].end_time))) {
                    cout << "Error: A start time can't be earlier than " << appointments[records_amount-1].end_time << "." << endl << endl;
                    continue;
                }
            }
            break;
        }while(true);

        // end time check
        do{
            cout << "==>> Enter the time of end (hh:mm): ";
            cin >> end_time;
            if(!check_time_format(end_time)){
                cout << "Error: Incorrect time format." << endl;
                continue;
            }else{
                break;
            }
        }while(true);

        Time start_time_struct = get_time(start_time);
        Time end_time_struct = get_time(end_time);

        if(hh_mm_to_minutes(start_time_struct) > hh_mm_to_minutes(end_time_struct)) {
            cout << "Error: End time can't be earlier than start time." << endl << endl;
            continue;
        }
        break;
    }while(true);

    return {surname, start_time, end_time};
}

bool check_time_format(const string& time){
    if(time.length() != 5){
        return false;
    }
    if(time[2] != ':'){
        return false;
    }
    if(!isdigit(time[0]) || !isdigit(time[1]) || !isdigit(time[3]) || !isdigit(time[4])){
        return false;
    }

    if(stoi(time.substr(0, 2)) > 23){
        return false;
    }
    if(stoi(time.substr(3, 2)) > 59){
        return false;
    }

    return true;
}

int hh_mm_to_minutes(Time time){
    return time.hours*60+time.minutes;
}

Time get_time(const string& time){
    int hours = stoi(time.substr(0, 2));
    int minutes = stoi(time.substr(3, 2));
    return {hours, minutes};
}

char call_input_form(const string& answers){
    cout << "==========================================================================" << endl;
    cout << "==>> Enter your choice: ";
    do{
        fflush(stdin);
        string input;
        cin >> input;
        if(input.length() == 1){
            for(char c: answers){
                if(input[0] == c){
                    cout << "==========================================================================" << endl;
                    return input[0];
                }
            }
        }
        cout << "==>> Incorrect input. Try again: ";
    }while(true);
}

void break_chat(){
    cout << endl << "==>> Press any key to continue..." << endl;
    getch();
}