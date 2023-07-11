#ifndef LAB2_FILE_HANDLER_H
#define LAB2_FILE_HANDLER_H

#include <string>
using namespace std;

bool create_file(const string& file_path, const string& file_extention);
//Transactions in SQL
//bool try_open_file(const string& file_path, const string& file_extention, fstream &out_file);

bool check_file_name(const string& file_path, const string& file_extention);
bool check_does_file_exist(const string& file_path);

#endif //LAB2_FILE_HANDLER_H
