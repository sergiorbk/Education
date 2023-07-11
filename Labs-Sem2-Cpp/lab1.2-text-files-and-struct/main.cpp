#include "main.h"
#include <iostream>
#include <Windows.h>
#include "file_handler.h"
#include "format_func.h"

using namespace std;

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    while(true){
        if(!main_menu()){
            return 0;
        }
    }
}

bool main_menu(){
    system("cls");
    cout << "==================== MAIN MENU ====================" << endl;
    cout << "[1] Choose a file to format" << endl << "[2] Create a new file" << endl << "[0] Exit" << endl;
    string input_file_path;
    switch(call_input_form("120")){
        case '1':
            system("cls");
            cout << "==================== Choose a file to format ====================" << endl;
            do{
                cout << endl << "Enter a file path: ";
                cin >> input_file_path;
                fflush(stdin);
            } while (!check_does_file_exist(input_file_path));

            while(true){
                if(!format_menu(input_file_path)){
                    return true;
                }
            }

        case '2':
            system("cls");
            cout << "==================== Create a new file ====================" << endl;
            do{
                cout << endl << "Enter a file path: ";
                cin >> input_file_path;
            }while(!create_file(input_file_path, ".bin"));
            cout << input_file_path << " was created successfully!" << endl;
            break_chat();
            return true;

        case '0':
            return false;
    }
    return true;
}

bool format_menu(const string& file_path){
    system("cls");
    cout << "==================== FORMAT MENU ====================" << endl;
    cout << "[1] Append file" << endl << "[2] Read file" << endl << "[3] Remove file" << endl << "[0] Main menu" << endl;
    Appointment* input_records = nullptr;
    Appointment* input_extra_records = nullptr;
    int records_amount;
    int extra_records_amount;
    string overtime_file_path;
    switch(call_input_form("1230")){
        case '1':
            system("cls");
            cout << "==================== Append file " << file_path << " ====================" << endl;
            add_record(file_path);
            return true;

        case '2':
            system("cls");
            cout << "==================== Read file " << file_path << " ====================" << endl;
            records_amount = read_records(file_path, &input_records);
            for(int i=0; i < records_amount; i++){
                cout << "Record " << i+1 << ": Surname: " << input_records[i].surname << " "
                     << "Start time: " << input_records[i].start_time << " " << "End time: "
                     << input_records[i].end_time << endl;
            }
            free(input_records);
            input_records = nullptr;
            break_chat();

            overtime_file_path = file_path.substr(0, file_path.length()-4);
            overtime_file_path += "_overtime.bin";
            if(check_does_file_exist(overtime_file_path)){
                cout << "==>> File with extra time records detected (" <<overtime_file_path<<")"<< endl << endl;
                extra_records_amount = read_records(overtime_file_path, &input_extra_records);
                for(int i=0; i < extra_records_amount; i++){
                    cout << "Record " << i+1 << ": Surname: " << input_extra_records[i].surname << " "
                         << "Start time: " << input_extra_records[i].start_time << " " << "End time: "
                         << input_extra_records[i].end_time << endl;
                }
                free(input_extra_records);
                input_extra_records = nullptr;
            }
            cout << endl << "==================== READING END ====================";
            break_chat();
            return true;

        case '3':
            system("cls");
            cout << "==================== Delete file " << file_path << " ====================" << endl;
            if(!remove(file_path.c_str())){
                overtime_file_path = file_path.substr(0, file_path.length()-4);
                overtime_file_path += "_overtime.bin";
                if(!remove(overtime_file_path.c_str())){
                    cout << "==>> " << file_path << " and linked file were removed successfully." << endl;
                }else{
                    cout << "==>> Linked file with overtime users was not found." << endl;
                    cout << "==>> " << file_path << " was removed successfully." << endl;
                }
            }else{
                cout << "Error: unable to remove " << file_path;
            }
            break_chat();
            return true;

        case '0':
            return false;
    }
    return true;
}