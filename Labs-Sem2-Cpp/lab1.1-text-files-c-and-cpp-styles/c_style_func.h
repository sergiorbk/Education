#ifndef UNTITLED1_CFUNCTIONS_H
#define UNTITLED1_CFUNCTIONS_H

using namespace std;

int get_longest_line_length_c(char *file_path);
int is_str_cont_sequence_c(char *input_str);
int count_words_c(char *line, char *delimiters);
int read_file_c(char *file_path);
void format_file_c(char *file_path);
void split_string_c(char **input_string, char*** output_array, char* delimiters);
int append_file_c(char *file_path);
int write_into_file_c(char* file_path, char* text);
char* encrypt_longest_sequence_c(char* line);
bool is_char_delimiter_c(char c, char *delimiters);

#endif //UNTITLED1_CFUNCTIONS_H