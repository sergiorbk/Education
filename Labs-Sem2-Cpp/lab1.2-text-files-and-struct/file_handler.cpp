#include "file_handler.h"
#include <fstream>
#include <iostream>

bool create_file(const string& file_path, const string& file_extention){
    if(!check_file_name(file_path, file_extention) || check_does_file_exist(file_path)){
        return false;
    }
    ofstream file(file_path, ios::binary);
    if(!file.good()){
        perror("Error");
        return false;
    }

    file.close();
    return true;
}

bool check_file_name(const string& file_path, const string& file_extention){
    /* This function checks file path.
     * Returns TRUE if file_path is OK or FALSE is wrong.
     * A file path is considered to be wrong in case of:
     * 1) There are rejected symbols in file_name.
     * 2) file_name doesn't have .bin as a file extension.
     * 3) file_name is less than 5 symbols or longer than 255 symbols.
     */

    //const string file_path = file_name + file_extention;
    int file_path_length = file_path.length();

    // Check does file_path's length not shorter than file_extension's length
    // and not shorter than 255
    if(file_path_length <= file_extention.length() || file_path_length > 255){
        cerr << "Error: file path can't be less than " << file_extention.length() + 1 << " symbols and longer than 255 symbols." << endl;
        return false;
    }

    // Check does file_path contains restricted symbols
    const string restricted_symbols = "<>:/|?";
    for(char fp_symbol: file_path){
        for(char restricted_symbol: restricted_symbols){
            if(fp_symbol == restricted_symbol || fp_symbol == '"' || fp_symbol == '\\'){
                cerr << "Error: File name contains restricted symbol(s)." << endl;
                return false;
            }
        }
    }

    // Check does file_path satisfies normal file format
    if(file_path.substr(file_path_length - file_extention.length()) != file_extention){
        cerr << "Error: Invalid file name format." << endl;
        return false;
    }

    return true;
}

bool check_does_file_exist(const string& file_path){
    // returns true if file exists, else returns false.
    ifstream file(file_path);
    if(file.good()){
        file.close();
        return true;
    } else{
        //perror("Error");
        return false;
    }
}