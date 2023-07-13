#include "c_style_func.h"
#include "sergolib.h"
#include <string.h>

void format_file_c(char *file_path) {
    FILE *fin = fopen(file_path, "r");
    if (fin == NULL) {
        printf("Error opening file!\n");
        return;
    }
    create_file("buff.txt");
    char delimiters[] = " ,.";
    int line_count = 0;
    const int max_line_len = get_longest_line_length_c(file_path) + 5;
    char* buffer_line = (char*) malloc (max_line_len * sizeof(char));

    while (fgets(buffer_line, max_line_len, fin)){
        if(buffer_line[strlen(buffer_line) - 1] == '\n'){
            buffer_line[strlen(buffer_line) - 1] = '\0';
        }

        line_count++;

        int word_count = count_words_c(buffer_line, delimiters);
        char** words = (char**) malloc(word_count * sizeof(char*) );
        split_string_c(&buffer_line, &words, delimiters);

        // finding the longest numerical sequence
        int max_seq_len = 0;
        char* max_seq_word = (char*) malloc ( (strlen("none") + 3) * sizeof(char));
        strcpy(max_seq_word, "none");
        for (int i = 0; i < word_count; i++) {
            int current_seq_len = is_str_cont_sequence_c(words[i]);
            if (current_seq_len > max_seq_len && current_seq_len > 1) {
                max_seq_len = current_seq_len;
                max_seq_word = (char*) realloc (max_seq_word, (strlen(words[i]) + 3) * sizeof(char));
                strcpy(max_seq_word, words[i]);
            }
        }
        printf("%s %d | %s %s | %s %d\n", "Line: ", line_count, " | Word: ", max_seq_word, " | Seq. len: ", max_seq_len);

        // swapping words that contain sequences into the end of words' array
        if(word_count > 2){
            bool is_sorted;
            int sorted = 0;
            do{
                is_sorted = true;
                for (int word_num = 0; word_num < word_count - sorted; word_num++) {
                    if(is_str_cont_sequence_c(words[word_num]) > 1){
                        is_sorted = false;
                        for(int swap_num = word_num; swap_num < word_count - 1; swap_num++){
                            //swap(words[swap_num], words[swap_num + 1]);
                            char* buff_str = words[swap_num];
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
            write_into_file_c("buff.txt", encrypt_longest_sequence_c(words[i]));
        }
        write_into_file_c("buff.txt", "\n");

        for(int i=0; i < word_count; i++){
            free(words[i]);
        }
        free(words);

    } // end of reading lines of text file
     fclose(fin);

    remove(file_path);
    if (rename("buff.txt", file_path) == -1) {
        perror("Error while renaming file: ");
        exit(1);
    }
    remove_empty_lines(file_path);
}

char* encrypt_longest_sequence_c(char* line) {
    int max_len = 0;
    int cur_len = 1;
    char* max_start = NULL;
    char* cur_start = line;
    int i;

    for (i = 0; i < strlen(line) - 1; i++) {
        if (isdigit(line[i]) && isdigit(line[i+1])) {
            if (line[i+1] - line[i] == 1) {
                cur_len++;
            } else {
                if (cur_len > max_len) {
                    max_len = cur_len;
                    max_start = cur_start;
                }
                cur_len = 1;
                cur_start = line + i + 1;
            }

        } else {
            if (cur_len > max_len) {
                max_len = cur_len;
                max_start = cur_start;
            }
            cur_len = 1;
            cur_start = line + i + 1;
        }
    }

    if (cur_len > max_len) {
        max_len = cur_len;
        max_start = cur_start;
    }

    if (max_len > 1) {
        for (i = 0; i < max_len; i++) {
            max_start[i] = '*';
        }
    }

    return line;
}

//char * str = new char[sizeof (file)]
int get_longest_line_length_c(char* file_path) {
    FILE *fp = fopen(file_path, "r");
    if (!fp){
        return -1;
    }

    int len = 0, max_len = 0;
    char c;
    while (1) { // do while
        fread(&c, 1, 1, fp);
        if (c == '\r') continue;

        int is_end_of_file = feof(fp);
        if (c == '\n' || is_end_of_file) {
            if (len > max_len) max_len = len;
            len = 0;
        }
        else len++;
        if (is_end_of_file) break;
    }
    fclose(fp);
    return max_len;
}

int is_str_cont_sequence_c(char* input_str){
    int str_len = strlen(input_str);
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

void split_string_c(char **input_string, char*** output_array, char* delimiters) {
    if(!is_char_delimiter_c((*input_string)[strlen(*input_string) - 1], delimiters)){
        *input_string = (char*)realloc(*input_string, (strlen(*input_string) + 3) * sizeof(char));
        strcat(*input_string, " ");
    }

    bool was_prev_delim = false;
    if(is_char_delimiter_c((*input_string)[0], delimiters)){
        was_prev_delim = true;
    }

    int words_count = 0;
    int buff_str_len = 0;
    char* buff_str = (char*)malloc(sizeof(char));

    for(int i=0; i < strlen(*input_string); i++){
        char c = (*input_string)[i];
        if(is_char_delimiter_c(c, delimiters) && !was_prev_delim){ // if this char is a delimiter but previous was not
            // adding the first delimiter after word
            buff_str_len++;
            buff_str = (char*)realloc(buff_str, buff_str_len * sizeof(char));
            buff_str[buff_str_len - 1] = c;

            //adding null-terminator
            buff_str_len++;
            buff_str = (char*)realloc(buff_str, buff_str_len * sizeof(char));
            buff_str[buff_str_len - 1] = '\0';

            *output_array = (char**)realloc(*output_array, (words_count + 1) * sizeof(char*));
            (*output_array)[words_count] = (char*) malloc (buff_str_len * sizeof(char));
            strcpy((*output_array)[words_count], buff_str);

            words_count++;
            free(buff_str);
            buff_str = nullptr;
            buff_str_len = 0;
        }

        if(is_char_delimiter_c(c, delimiters)){
            was_prev_delim = true;
        }else{
            buff_str_len++;
            if(buff_str != nullptr){
                buff_str = (char*)realloc(buff_str, buff_str_len * sizeof(char));
            }else{
                buff_str = (char*)malloc(sizeof(char));
            }
            buff_str[buff_str_len - 1] = c;
            was_prev_delim = false;
        }
    }

    *output_array = (char**) realloc (*output_array, (words_count + 1) * sizeof(char*));
    (*output_array)[words_count] = nullptr;

    buff_str = nullptr;
    free(buff_str);
}

int count_words_c(char *line, char *delimiters){
    int words = 0;
    bool was_prev_char_delimiter = is_char_delimiter_c(line[0], delimiters); //check if first char is a delimiter

    for(int i = 1; i < strlen(line); i++){
        bool is_current_char_delimiter = is_char_delimiter_c(line[i], delimiters);

        if(is_current_char_delimiter && was_prev_char_delimiter){ // is_current_char_delimiter && was_prev_char_delimiter
            words++;
        }
        if(i == strlen(line)-1 && is_current_char_delimiter){ // Last symbol in this string is NOT a delimiter.
            words++;
        }
        was_prev_char_delimiter = is_current_char_delimiter;
    }
    return words;
}

bool is_char_delimiter_c(char c, char *delimiters){
    for(int i=0; i<strlen(delimiters); i++){
        if(c == delimiters[i]){
            return true;
        }
    }
    return false;
}

int read_file_c(char *file_path){
    FILE *file = fopen(file_path, "r");

    if (file != NULL) { // is file available check
        printf("\n%s %s\n\n", "==>> Reading BEGIN (C - style)", file_path);

        const int max_line_len = get_longest_line_length_c(file_path) + 5;
        char* buffer_line = (char*) malloc (max_line_len * sizeof(char));

        while (fgets(buffer_line, max_line_len, file)) {
            printf("%s", buffer_line);
        }

        printf("\n\n%s %s\n", "==>> Reading END (C - style)", file_path);
        fclose(file);
        free(buffer_line);
        buffer_line = NULL;
        return 0;
    }else{
        printf("%s%s\n", "Error: Unable to open ", file_path);
        return 1;
    }
}

int append_file_c(char *file_path){
    FILE* file = fopen(file_path, "a");
    if (file != NULL) {
        printf("==>> Write your text here. Press ENTER to start writing to the next line. Type '0' to exit writing\n");

        char* input_line = NULL;
        do{
            read_line(&input_line);
            if(strcmp(input_line, "0") != 0){
                fputc('\n', file);
                fputs(input_line, file);
            }
        }while(strcmp(input_line, "0") !=0 );

        fclose(file);
        printf("==>> Text have been successfully appended to file.\n");
        remove_empty_lines(file_path);
        return 0;
    } else {
        perror("Error opening file");
        return 1;
    }
}

int write_into_file_c(char * file_path, char* text){
    FILE* fp = fopen(file_path, "a");
    if(fp != NULL){ // DAL (no input output) | Logic(no input output) | UI  N-tier architecture SOLID D-read
        fprintf(fp, text);
        fclose(fp);
        return 0;
    }else{
        perror("Error opening file");
        return 1;
    }
}