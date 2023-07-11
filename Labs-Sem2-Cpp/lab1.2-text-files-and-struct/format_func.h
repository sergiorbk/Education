#ifndef LAB2_FORMAT_FUNC_H
#define LAB2_FORMAT_FUNC_H

#include <string>
#include "data_input.h"

using namespace std;

void add_record(const string& file_path);
//void add_record(const fstream& file_stream);
void write_record(const string& file_path, const Appointment& appointment);
int read_records(const string& file_path, Appointment** appointments);

#endif //LAB2_FORMAT_FUNC_H