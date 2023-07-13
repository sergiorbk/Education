#include "sergolib.h"
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

int read_line(char** line) {
    free(*line);
    fflush(stdin);
    size_t line_size = 0;
    *line = (char*) malloc(1);
    int c = getchar();
    if (c == EOF) {
        return 1;
    }
    while (c != '\n' && c != EOF) {
        char* tmp = (char*) realloc(*line, line_size + 1);
        if (!tmp) {
            free(*line);
            return 1;
        }
        *line = tmp;
        (*line)[line_size++] = c;
        c = getchar();
    }
    char* tmp = (char*) realloc(*line, line_size + 1);
    if (!tmp) {
        free(*line);
        return 1;
    }
    *line = tmp;
    (*line)[line_size] = '\0';
    return 0;
}

int is_file_available(string file_path){
    // check does file available to open
    ifstream file(file_path);
    if (file.good()) {
        file.close();
        return 1;
    } else{
        return 0;
    }
}

int is_file_available(char *filePath){
    // check does file exists
    FILE *file;
    file = fopen(filePath, "r");
    if(file != NULL){
        fclose(file);
        return 1; // file is already exists
    }else{
        return -1;
    }
}

int check_file_path_txt(string file_path){
    if(file_path.length() < 5){
        cout << "Error: file path can't be less than 5 symbols (containing .txt)." << endl;
        return 1;
    }

    const string restricted_symbols = "<>:/|?";
    for(char fp_symbol: file_path){
        for(char restricted_symbol: restricted_symbols){
            if(fp_symbol == restricted_symbol || fp_symbol == '"' || fp_symbol == '\\'){
                cout << "Error: File name contains restricted symbol(s)." << endl;
                return 1;
            }
        }
    }

    int fp_len = file_path.length();
    if(file_path[fp_len-1] != 't' || file_path[fp_len-2] != 'x' || file_path[fp_len-3] != 't' || file_path[fp_len-4] != '.' ){
        cout << "Error: Invalid format. File's name must be like text.txt . Try again." << endl;
        return 1;
    }

    return 0;
}

int check_file_path_txt(char* file_path){
    if(strlen(file_path) < 5) {
        printf("Error: file path can't be less than 5 symbols (containing .txt).\n");
        return 1;
    }

    const char* restricted_symbols = "<>:/|?";
    for(int i=0; i < strlen(file_path); i++){
        char fp_symbol = file_path[i];
        for(int rs_num = 0; rs_num < strlen(restricted_symbols); rs_num++){
            char restricted_symbol = restricted_symbols[rs_num];
            if(fp_symbol == restricted_symbol || fp_symbol == '"' || fp_symbol == '\\'){
                printf("Error: File name contains restricted symbol(s).\n");
                return 1;
            }
        }
    }

    int fp_len = strlen(file_path);
    if(file_path[fp_len-1] != 't' || file_path[fp_len-2] != 'x' || file_path[fp_len-3] != 't' || file_path[fp_len-4] != '.' ){
        printf("Error: Invalid format. File's name must be like text.txt . Try again.\n");
        return 1;
    }

    return 0;
}


int create_file(string file_path) {
    cout << "==>> Creating file using File Stream" << endl;
    if(check_file_path_txt(file_path) != 0){
        return 1;
    }

    ifstream file(file_path);
    if (is_file_available(file_path) == 1){
        return 1;
    }
    // creating a file
    ofstream new_file(file_path);
    // creating errors check
    if (new_file.is_open()) {
        new_file.close();
        return 0;

    } else {
        return 1;
    }
}

int create_file(char *file_path){
    printf("==>> Creating file using File Pointer\n");
    if(check_file_path_txt(file_path) != 0){
        return 1;
    }
    // check does file exists
    FILE *file;
    if(is_file_available(file_path) == 1){
        return -1;
    }
    // creating a file
    file = fopen(file_path, "w");
    // creating errors check
    if (file != NULL) {
        //fprintf(file, file_path);
        fclose(file);
        return 0;
    } else {
        return -1; // unable to create a file
    }
}

void remove_empty_lines(string filename) {
    ifstream fin(filename);
    ofstream fout("temp.txt");

    if (!fin.is_open()) {
        cout << "Error: Could not open file " << filename << endl;
        return;
    }

    string line;
    while (getline(fin, line)) {
        if (!line.empty()) {
            fout << line << endl;
        }
    }

    fin.close();
    fout.close();

    remove(filename.c_str());
    rename("temp.txt", filename.c_str());

    //out << "==>> Empty lines were removed from file " << filename << endl;
}

char call_input_form(string answers){
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
    }while(1);
}

void break_chat(){
    cout << endl << "==>> Press any key to continue...";
    getch();
}

bool is_char_digit(char c){
    char digits[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    for(int i=0; i<10; i++){
        if(c == digits[i]){
            return true;
        }
    }
    return false;
}

int digit_char_to_int(char c){
    if(is_char_digit(c)){
        char digits[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
        for(int i=0; i<10; i++){
            if(c == digits[i]){
                return i;
            }
        }
    }else{
        return -1;
    }
}