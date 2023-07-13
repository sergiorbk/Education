#include "cpp_style_func.h"
#include "sergolib.h"
#include <iostream>
#include <fstream>

void format_file_cpp(string file_path){
    ifstream fin(file_path); // Opening input stream for a file
    int line_number = 1;
    create_file("buff.txt");
    cout << endl << "=============== Max sequences ==============" << endl;
    while(!fin.eof()){ // 1 iteration - 1 line
        string input_string;
        getline(fin, input_string);

        string delimiters = " ,.";
        int word_count = count_words_cpp(input_string, delimiters);

        string words[word_count];
        split_string_cpp(input_string, words, delimiters);

        string max_sequence = "none";
        int max_seq_len = 0;

        for (int word_num = 0; word_num < word_count; word_num++) {
            int current_seq_len = is_str_cont_sequence_cpp(words[word_num]);
            if(current_seq_len > max_seq_len && current_seq_len > 1){
                max_sequence = words[word_num];
                max_seq_len = current_seq_len;
            }
        }

        if(max_seq_len > 0){
            cout << "Line:\t" << line_number << "\tWord:\t" << max_sequence << "\tLength:\t" << max_seq_len << endl;
        }else{
            cout << "Line:\t" << line_number << "\tDoes not contains words with sequences." << endl;
        }

        if(word_count > 2){
            bool is_sorted;
            int sorted = 0;
            do{
                is_sorted = true;
                for (int word_num = 0; word_num < word_count - sorted; word_num++) {
                    if(is_str_cont_sequence_cpp(words[word_num]) > 1){
                        is_sorted = false;
                        for(int swap_num = word_num; swap_num < word_count - 1; swap_num++){
                            //swap(words[swap_num], words[swap_num + 1]);
                            string buff_str = words[swap_num];
                            words[swap_num] = words[swap_num + 1];
                            words[swap_num + 1] = buff_str;
                        }
                        sorted++;
                    }
                    if(is_sorted == false){
                        break;
                    }
                }
            }while(!is_sorted);
        }

        for(int i=0; i < word_count; i++){
            write_into_file_cpp("buff.txt", encrypt_longest_sequence_cpp(words[i]));
        }
        write_into_file_cpp("buff.txt", "\n");
        line_number++;
    }//end of while (Line reader)

    fin.close();
    remove_empty_lines("buff.txt");
    remove(file_path.c_str());
    if(rename("buff.txt", file_path.c_str()) == -1){
        perror("Error while renaming file: ");
        return;
    }
}

int is_str_cont_sequence_cpp(string input_str){
    int str_len = input_str.length();
    int sequence_len = 1;
    int max_sequence_len = 0;
    for (int a = 0; a < str_len - 1; a++) {
        if(!is_char_digit(input_str[a])){
            sequence_len=1;
        }else{
            if(digit_char_to_int(input_str[a]) < digit_char_to_int(input_str[a + 1])){
                sequence_len++;
            }
            if(sequence_len > max_sequence_len){
                max_sequence_len = sequence_len;
            }
        }
    }
    return max_sequence_len;
}

string encrypt_longest_sequence_cpp(string line) {
    int max_len = 0; // lenth of the longest sequence
    int cur_len = 1; // current sequence length
    int max_start = 0; // amount of symbols since line.begin() iterator to the first symbol of the longest sequence
    int cur_start = 0; // amount of symbols since line.begin() iterator to the first symbol of current sequence
    int i;

    for (i = 0; i < line.size() - 1; i++) {
        if (isdigit(line[i]) && isdigit(line[i+1])) {
            if (line[i+1] - line[i] == 1) {
                cur_len++;
            } else {
                if (cur_len > max_len) {
                    max_len = cur_len;
                    max_start = cur_start;
                }
                cur_len = 1;
                cur_start = i + 1;
            }
        } else {
            if (cur_len > max_len) {
                max_len = cur_len;
                max_start = cur_start;
            }
            cur_len = 1;
            cur_start = i + 1;
        }
    }

    if (cur_len > max_len) {
        max_len = cur_len;
        max_start = cur_start;
    }

    if (max_len > 1) {
        std::fill(line.begin() + max_start, line.begin() + max_start + max_len, '*');
    }

    return line;
}

void write_into_file_cpp(string file_path, string text){
    ofstream fout(file_path, ios::app);
    fout << text;
    fout.close();
}

void split_string_cpp(string input_string, string* output_array, string delimiters){
    int words_count = 0;
    string buff_str;

    if(!is_char_delimiter_cpp(input_string[input_string.length() - 1], delimiters)){
        input_string += ' ';
    }

    bool was_prev_delim;
    if(is_char_delimiter_cpp(input_string[0], delimiters)){
        was_prev_delim = true;
    }

    for(char c: input_string){
        if(is_char_delimiter_cpp(c, delimiters) && was_prev_delim == false){
            buff_str += c;
            output_array[words_count] = buff_str;
            buff_str = "";
            words_count++;
        }
        if(is_char_delimiter_cpp(c, delimiters)){
            was_prev_delim = true;
        }else{
            buff_str += c;
            was_prev_delim = false;
        }
    }
}

int count_words_cpp(string line, string delimiters){
    int words = 0;
    bool was_prev_char_delimiter = is_char_delimiter_cpp(line[0], delimiters); //check if first char is a delimiter

    for(int i = 1; i < line.length(); i++){
        bool is_current_char_delimiter = is_char_delimiter_cpp(line[i], delimiters);

        if(is_current_char_delimiter == true && was_prev_char_delimiter == false){
            words++;
        }
        if(i == line.length()-1 && is_current_char_delimiter == false){ // Last symbol in this string is NOT a delimiter.
            words++;
        }
        was_prev_char_delimiter = is_current_char_delimiter;
    }
    return words;
}

void read_file_cpp(string file_path) {
    ifstream file(file_path);
    if (file.is_open()) {
        string line;
        cout << "==>> Reading BEGIN (C++ - style) " << file_path << endl << endl;
        while (getline(file, line)) {
            cout << line << endl;
        }
        cout << endl << "==>> Reading END (C++ - style) " << file_path << endl;
        file.close();
    } else {
        cout << "Error opening " << file_path << endl;
    }
}

bool is_char_delimiter_cpp(char c, string delimiters){
    for(char delimiter: delimiters){
        if(c == delimiter){
            return true;
        }
    }
    return false;
}

void append_file_cpp(string file_path){
    cout << "==>> Writing text into file " << file_path << " (C++ - style)" << endl;
    ofstream file(file_path, ios::app);
    if (file.is_open()) {
        cout << "==>> Write your text here. Press ENTER to start writing to the next line. Type 'STP' to exit writing" << endl;
        string line;
        int line_num = 1;
        while (getline(cin, line)) {
            if(line == "STP"){
                break;
            }else{
                if(line_num != 1){
                    file << endl;
                }
                file << line;
                line_num++;
            }
        }
        file.close();
        remove_empty_lines(file_path);
    }else{
        cerr << "Failed to open file: " << file_path << endl;
    }
}