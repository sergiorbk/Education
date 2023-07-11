#ifndef UNTITLED1_SERGOLIB_H
#define UNTITLED1_SERGOLIB_H

#include <string>

using namespace std;

int create_file(string file_path);
int create_file(char *file_path);
int is_file_available(string file_path);
int is_file_available(char *filePath);
char call_input_form(string answers);
int ctoi(char c);
int read_line(char** out_str_ptr);
void break_chat();
void remove_empty_lines(string filename);
//bool is_char_digit(char c);
int check_file_path_txt(string file_path);
int check_file_path_txt(char* file_path);

#endif //UNTITLED1_SERGOLIB_H