#ifndef UNTITLED1_FILEFORMATING_H
#define UNTITLED1_FILEFORMATING_H

#endif //UNTITLED1_FILEFORMATING_H

#include <iostream>
#include "sergolib.h"
#include <string>
#include <fstream>
#include <conio.h>
#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <list>
#include <windows.h>

#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

void read_file_c(char *file_path);
void readFileCpp(string filePath);
void append_file_cpp(string file_path);
void append_file_c(char *file_path);
void format_file_cpp(string file_path);
void format_file_c(char *file_path);
void split_string_cpp(string input_string, string* output_array, list<char> delimiters);
void split_string_c(char **input_string, char*** output_array, char* delimiters);
bool is_char_delimiter_cpp(char c, list<char> delimiters);
bool is_char_delimiter_c(char c, char *delimiters);
int count_words_cpp(string line, list<char> delimiters);
int count_words_c(char *line, char *delimiters);
void write_into_file_cpp(string file_path, string text);
void writeIntoFileC(char * filePath, string text);
int is_str_cont_sequence_cpp(string input_str);
int is_str_cont_sequence_c(char *input_str);
void remove_empty_lines(string filename);
int getLongestLineLen(FILE* file_ptr);