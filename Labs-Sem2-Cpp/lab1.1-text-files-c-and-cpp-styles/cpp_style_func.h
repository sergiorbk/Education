#ifndef UNTITLED1_CPPFUNCTIONS_H
#define UNTITLED1_CPPFUNCTIONS_H

#include <string>

using namespace std;

void format_file_cpp(string file_path);
void write_into_file_cpp(string file_path, string text);
void split_string_cpp(string input_string, string* output_array, string delimiters);
void read_file_cpp(string file_path);
void append_file_cpp(string file_path);
int is_str_cont_sequence_cpp(string input_str);
int count_words_cpp(string line, string delimiters);
bool is_char_delimiter_cpp(char c, string delimiters);
string encrypt_longest_sequence_cpp(string line);

#endif //UNTITLED1_CPPFUNCTIONS_H