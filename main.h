#ifndef UNTITLED1_MAIN_H
#define UNTITLED1_MAIN_H

#include "string"

using namespace std;

int get_file_mode(int argc, char* argv[]);
int main_menu(int file_mode);
int format_menu_cpp(string file_path);
int format_menu_c(char *file_path);
string get_file_mode_name(int file_mode_code);

#endif //UNTITLED1_MAIN_H