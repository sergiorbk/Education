#include "format_func.h"
#include "file_handler.h"
#include <fstream>
#include <iostream>
using namespace std;

void add_record(const string& file_path){
    Appointment new_record = input_appointment_info(file_path);

    Time start_time = get_time(new_record.start_time);
    Time end_time = get_time(new_record.end_time);

    if(hh_mm_to_minutes(end_time) - hh_mm_to_minutes(start_time) >= 30){
        string overtime_file_path = file_path.substr(0, file_path.length()-4);
        overtime_file_path += "_overtime.bin";
        if(!check_does_file_exist(overtime_file_path)){
            create_file(file_path, ".bin");
        }
        write_record(overtime_file_path, new_record);
    }
    write_record(file_path, new_record);
}

void write_record(const string& file_path, const Appointment& appointment) {
    ofstream ofs(file_path, ios::binary | ios::app);
    if (!ofs.is_open()) {
        return;
    }

    int surname_len = (int)appointment.surname.length();
    ofs.write((char*)&surname_len, sizeof(int));
    ofs.write(appointment.surname.c_str(), surname_len);

    int start_time_len = (int)appointment.start_time.length();
    ofs.write((char*)&start_time_len, sizeof(int));
    ofs.write(appointment.start_time.c_str(), start_time_len);

    int end_time_len = (int)appointment.end_time.length();
    ofs.write((char*)&end_time_len, sizeof(int));
    ofs.write(appointment.end_time.c_str(), end_time_len);
    ofs.close();
}

int read_records(const string& file_path, Appointment** appointments) {
    ifstream ifs(file_path, ios::binary);
    if (!ifs.is_open()) {
        return -1;
    }

    int count = 0;
    while (ifs.peek() != EOF) {
        Appointment appointment;
        int surname_len;
        ifs.read((char*)&surname_len, sizeof(int));
        char* surname_buffer = new char[surname_len + 1];
        ifs.read(surname_buffer, surname_len);
        surname_buffer[surname_len] = '\0';
        appointment.surname = string(surname_buffer);
        delete[] surname_buffer;

        int start_time_len;
        ifs.read((char*)&start_time_len, sizeof(int));
        char* start_time_buffer = new char[start_time_len + 1];
        ifs.read(start_time_buffer, start_time_len);
        start_time_buffer[start_time_len] = '\0';
        appointment.start_time = std::string(start_time_buffer);
        delete[] start_time_buffer;

        int end_time_len;
        ifs.read((char*)&end_time_len, sizeof(int));
        char* end_time_buffer = new char[end_time_len + 1];
        ifs.read(end_time_buffer, end_time_len);
        end_time_buffer[end_time_len] = '\0';
        appointment.end_time = std::string(end_time_buffer);
        delete[] end_time_buffer;

        if (count == 0) {
            //return nullptr;
            *appointments = new Appointment[1];
        } else {
            auto tmp = new Appointment[count + 1]; // type : Appointment*
            //for (int i = 0; i < count; i++) {
            //    tmp[i] = (*appointments)[i];
            //}
            copy(*appointments, *appointments + count, tmp);
            delete[] *appointments;
            *appointments = tmp;
        }
        (*appointments)[count] = appointment;
        count++;
    }
    ifs.close();
    return count;
}