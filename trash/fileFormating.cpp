#include "fileFormating.h"

void format_file_cpp(string filePath){
    ifstream fin(filePath); // Opening input stream for a file
    int lineNumber = 1;
    create_file("buff.txt");
    while(!fin.eof()){ // 1 iteration - 1 line
        string inputString;
        getline(fin, inputString);

        list<char> delimiters = {' ', '.', ','};
        int wordCount = countWordsCpp(inputString, delimiters);

        string words[wordCount]; // масив слів рядка
        splitStringCpp(inputString, words, delimiters);

        string maxSequence="none";
        int maxSeqLen=0;

        for (int wordNum = 0; wordNum < wordCount; wordNum++) { // перебір слів рядка
            //визначимо чи містить слово найдовшу послідовність
            int currentSeqLen = isStrContSequenceCpp(words[wordNum]);
            if(currentSeqLen > maxSeqLen){
                maxSequence = words[wordNum];
                maxSeqLen = currentSeqLen;
            }
        }// кінець перебору слів
        cout << "Max sequence of " << lineNumber << " line is:" << maxSequence << " len: " << maxSeqLen << endl;
        int sorted = 0;
        for (int wordNum = 0; wordNum < wordCount-sorted; wordNum++) { // перебір слів рядка
            //переставимо знайдену послідовність у кінець рядка
            if(isStrContSequenceCpp(words[wordNum]) != 0){
                for(int swapNum = wordNum; swapNum < wordCount-1; swapNum++){
                    swap(words[swapNum], words[swapNum+1]);
                }
                sorted++;
            }
        }// кінець перебору слів


        for(int i=0; i < wordCount; i++){
            writeIntoFileCpp("buff.txt", words[i]);
        }
        writeIntoFileCpp("buff.txt", "\n");
        lineNumber++;
    }//end of while (Line reader)

    fin.close();
    removeEmptyLines("buff.txt");
    remove(filePath.c_str());
    if(::rename("buff.txt", filePath.c_str()) == -1){
        ::perror("Error while renaming file: ");
        exit(1);
    }
}

#include <iostream>
#include <fstream>
#include <cstring>
int findLongestLineLength(FILE *fp) {
    int longest = 0;
    char *line = NULL;
    size_t len = 0;

    while (getline(&line, &len, fp) != -1) {
        int lineLen = strlen(line);
        if (lineLen > longest) {
            longest = lineLen;
        }
    }

    free(line);
    return longest;
}

void format_file_c(char *filePath) {
    FILE *fin = fopen(file_path, "r");
    if (fin == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    createFile("buff.txt");

    char delimiters[] = {' ', '.', ','};

    //char* inputString = (char*) malloc (100 * sizeof(char));
    int line_count = 0;

    while(fin != EOF){ // 1 iteration - 1 line
        char* inputString;
        getline(fin, inputString);

        line_count++;
        //printf("%s", inputString);
        //inputString[strcspn(inputString, "\n")] = '\0';

        int wordCount = countWordsC(inputString, delimiters);
        char** words = NULL;
        splitStringC(&inputString, &words, delimiters);

        /*
        for(int i=0; i<wordCount; i++){
            printf("%s\n", words[i]);
        }
         */

        // finding the longest numerical sequence
        int maxSeqLen = 0;
        char* max_seq_word = (char*) malloc (sizeof(char));
        for (int i = 0; i < wordCount; i++) {
            int currentSeqLen = isStrContSequenceC(words[i]);
            if (currentSeqLen > maxSeqLen) {
                maxSeqLen = currentSeqLen;
                max_seq_word = (char*) realloc (max_seq_word, (strlen(words[i]) + 1) * sizeof(char));
                strcpy(max_seq_word, words[i]);
            }
        }
        cout << "Line: " << line_count << " | Word: " << max_seq_word << " | Seq. len: " << maxSeqLen << endl;

        // swapping words that contain sequences into the end of words' array
        int sorted = 0;
        for (int wordNum = 0; wordNum < wordCount-sorted; wordNum++) { // перебір слів рядка
            //переставимо знайдену послідовність у кінець рядка
            if (isStrContSequenceC(words[wordNum]) != 0) {
                for (int swapNum = wordNum; swapNum < wordCount - 1; swapNum++) {
                    char* buff_word = words[swapNum];
                    words [swapNum] = words [swapNum + 1];
                    words [ swapNum + 1 ] = buff_word;
                    //swap(words[swapNum], words[swapNum + 1]);
                }
                sorted++;
            }
        }

        for (int i = 0; i < wordCount; i++) {
            writeIntoFileCpp("buff.txt", words[i]);
            if (i < wordCount - 1) {
                writeIntoFileCpp("buff.txt", " ");
            }
        }

        writeIntoFileCpp("buff.txt", "\n");

        for(int i=0; i<wordCount; i++){
            free(words[i]);
        }
        free(words);
    }

    fclose(fin);
    remove(file_path);
    if (rename("buff.txt", file_path) == -1) {
        perror("Error while renaming file: ");
        exit(1);
    }
    removeEmptyLines(file_path);
}

int is_str_cont_sequence_cpp(string inputStr){
    int strLen = inputStr.length();
    int sequenceLen=1;
    int maxSequenceLen=0;
    for (int a = 0; a < strLen - 1; a++) { //перебір символів слова
        if(!isCharDigit(inputStr[a])){
            sequenceLen=1;
        }else{
            if(digitCharToInt(inputStr[a]) < digitCharToInt(inputStr[a+1])){
                sequenceLen++;
            }
            if(sequenceLen > maxSequenceLen){
                maxSequenceLen = sequenceLen;
            }
        }
    }//кінець перебору символів слова
    return maxSequenceLen;
}

int is_str_cont_sequence_c(char *inputStr) {
    int strLen = strlen(inputStr);
    int sequenceLen = 1;
    int maxSequenceLen = 0;
    for (int a = 0; a < strLen - 1; a++) { // перебір символів слова
        if(!isdigit(inputStr[a])){
            sequenceLen = 1;
        } else {
            if(inputStr[a] - '0' < inputStr[a+1] - '0'){
                sequenceLen++;
            }
            if(sequenceLen > maxSequenceLen){
                maxSequenceLen = sequenceLen;
            }
        }
    } // кінець перебору символів слова
    return maxSequenceLen;
}

void write_into_file_cpp(string filePath, string text){
    //cout << "*** File before applying ***" << endl;
    //readFile(filePath, fileMode);
    ofstream fout;
    fout.open(filePath, ios::app);
    fout << text;
    fout.close();
    //cout << "*** File after applying ***" << endl;
    //readFile(filePath, fileMode);
}

void writeIntoFileC(char * filePath, string text){
    const char* chText = text.c_str();
    //cout << "*** File before applying ***" << endl;
    //readFileC(filePath);
    FILE* fp;
    fp = fopen(filePath, "a");
    fprintf(fp, chText);
    ::fclose(fp);
    //cout << "*** File before applying ***" << endl;
    //readFileC(filePath);
}

void split_string_cpp(string inputString, string* outputArray, list<char> delimiters){
    int wordsCount = 0;
    string buffStr;

    if(!isCharDelimiterCpp(inputString[inputString.length() - 1], delimiters)){
        inputString += '.';
        //cout << "==>> Warning: Last symbol of line is not a delimiter." << endl;
        //cout << "==>> '.' symbol was appended to this line." << endl;
    }

    bool wasPrevDelim;
    if(isCharDelimiterCpp(inputString[0], delimiters)){
        wasPrevDelim = true;
    }

    for(char c: inputString){
        if(isCharDelimiterCpp(c, delimiters) && wasPrevDelim == false){
            buffStr += c;
            outputArray[wordsCount] = buffStr;
            buffStr = "";
            wordsCount++;
        }
        if(isCharDelimiterCpp(c, delimiters)){
            wasPrevDelim = true;
        }else{
            buffStr += c;
            wasPrevDelim = false;
        }
    }
}


void split_string_c(char **inputString, char*** outputArray, char* delimiters) {
    if(!isCharDelimiterC((*inputString)[strlen(*inputString) - 1], delimiters)){
        *inputString = (char*)realloc(*inputString, (strlen(*inputString) + 3) * sizeof(char));
        strcat(*inputString, " ");
        //cout << "==>> Warning: Last symbol of line is not a delimiter." << endl;
        //cout << "==>> '.' symbol was appended to this line." << endl;
    }

    bool wasPrevDelim = false;
    if(isCharDelimiterC(*inputString[0], delimiters)){
        wasPrevDelim = true;
    }

    int wordsCount = 0;
    int buff_str_len = 0;
    char* buffStr = (char*)malloc(sizeof(char));

    for(int i=0; i < strlen(*inputString); i++){
        char c = (*inputString)[i];
        if(isCharDelimiterC(c, delimiters) && !wasPrevDelim){ // if this char is a delimiter but previous was not
            // adding the first delimiter after word
            buff_str_len++;
            buffStr = (char*)realloc(buffStr, buff_str_len * sizeof(char));
            buffStr[buff_str_len - 1] = c;

            //adding null-terminator
            buff_str_len++;
            buffStr = (char*)realloc(buffStr, buff_str_len * sizeof(char));
            buffStr[buff_str_len - 1] = '\0';

            *outputArray = (char**)realloc(*outputArray, (wordsCount + 1) * sizeof(char*));
            (*outputArray)[wordsCount] = (char*) malloc (buff_str_len * sizeof(char));
            strcpy((*outputArray)[wordsCount], buffStr);
            //cout << "word " << wordsCount << ": " << (*outputArray)[wordsCount] << endl;

            wordsCount++;
            free(buffStr);
            buffStr = nullptr;
            buff_str_len = 0;
        }

        if(isCharDelimiterC(c, delimiters)){
            wasPrevDelim = true;
        }else{
            buff_str_len++;
            if(buffStr != nullptr){
                buffStr = (char*)realloc(buffStr, buff_str_len * sizeof(char));
            }else{
                buffStr = (char*)malloc(sizeof(char));
                //rcout << "Null ptr" << endl;
            }
            buffStr[buff_str_len - 1] = c;
            wasPrevDelim = false;
        }
    }

    *outputArray = (char**) realloc (*outputArray, (wordsCount+1) * sizeof(char*));
    (*outputArray)[wordsCount] = nullptr;

    buffStr = nullptr;
    free(buffStr);
}

int count_words_cpp(string line, list<char> delimiters){
    int words = 0;
    bool wasPrevCharDelimiter = isCharDelimiterCpp(line[0], delimiters); //check if first char is a delimiter

    for(int i = 1; i < line.length(); i++){
        bool isCurrentCharDelimiter = isCharDelimiterCpp(line[i], delimiters);

        if(isCurrentCharDelimiter == true && wasPrevCharDelimiter == false){
            words++;
        }
        if(i == line.length()-1 && isCurrentCharDelimiter == false){
            //cout << "==>> WARNING: Last symbol in this string is NOT delimiter." << endl;
            words++;
        }
        wasPrevCharDelimiter = isCurrentCharDelimiter;
    }
    return words;
}

int count_words_c(char *line, char *delimiters){
    int words = 0;
    bool wasPrevCharDelimiter = isCharDelimiterC(line[0], delimiters); //check if first char is a delimiter

    for(int i = 1; i < strlen(line); i++){
        bool isCurrentCharDelimiter = isCharDelimiterC(line[i], delimiters);

        if(isCurrentCharDelimiter == true && wasPrevCharDelimiter == false){
            words++;
        }
        if(i == strlen(line)-1 && isCurrentCharDelimiter == false){
            //printf("==>> WARNING: Last symbol in this string is NOT delimiter.\n");
            words++;
        }
        wasPrevCharDelimiter = isCurrentCharDelimiter;
    }
    return words;
}

bool is_char_delimiter_cpp(char c, list<char> delimiters){
    for(char delimiter: delimiters){
        if(c == delimiter){
            return true;
        }
    }
    return false;
}

bool is_char_delimiter_c(char c, char *delimiters){
    for(int i=0; i<strlen(delimiters); i++){
        if(c == delimiters[i]){
            return true;
        }
    }
    return false;
}

void readFileCpp(string filePath){
    ifstream file(filePath);
    if (file.is_open()) {
        string line;
        cout << "==>> Reading BEGIN (C++ - style)" << filePath << endl;
        while (getline(file, line)) {
            cout << line << endl;
        }
        cout << "==>> Reading END (C++ - style)" << filePath << endl;
        file.close();
    }
    else {
        cout << "Error opening " << filePath << endl;
    }
}

void read_file_c(char *filePath){
    FILE *file = fopen(filePath, "r");

    if (file != NULL) { // is file available check
        cout << "==>> Reading BEGIN (C - style)" << filePath << endl;
        char bufferLine[1024];
        while (fgets(bufferLine, 1024, file)){
            printf("%s", bufferLine);
        }
        cout << "\n==>> Reading END (C - style)" << filePath << endl;
        fclose(file);
    }else{
        printf("%s%s\n", "Error: Unable to open ", filePath);
    }
}

void append_file_cpp(string filePath){
    cout << "==>> Writing text into file " << filePath << " (C++ - style)" << endl;
    ofstream file(filePath, ios::app);
    if (file.is_open()) {
        cout << "==>> Write your text here. Press ENTER to start writing to the next line. Type 'STOP' to exit writing" << endl;
        string line;
        int lineNum = 1;
        while (getline(cin, line)) {
            if(line == "STOP"){
                break;
            }else{
                if(lineNum != 1){
                    file << endl;
                }
                file << line;
                lineNum++;
            }
        }
        file.close();
        removeEmptyLines(filePath);
    }else{
        cerr << "Failed to open file: " << filePath << endl;
    }
}

void append_file_c(char *filePath) {
    FILE* file = fopen(filePath, "a");
    if (file != NULL) {
        printf("==>> Write your text here. Press ENTER to start writing to the next line. Type '0' to exit writing\n");
        char buffer[256];
        bool is_first_line = true;
        while (fgets(buffer, 256, stdin)) {
            if (buffer[0] == '0') {
                break;
            } else {
                // Удаляем символ перевода строки из буфера
                buffer[strcspn(buffer, "\n")] = '\0';
                // Записываем строку в файл
                if (!is_first_line) {
                    fputc('\n', file);
                }
                fputs(buffer, file);
                is_first_line = false;
            }
        }
        fclose(file);
        printf("==>> Text have been successfully appended to file.\n");
        removeEmptyLines(filePath);
    } else {
        perror("Error opening file");
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
        // Проверяем, является ли строка пустой
        if (!line.empty()) {
            // Если строка не пустая, записываем ее в файл
            fout << line << endl;
        }
    }

    fin.close();
    fout.close();

    // Заменяем исходный файл на файл без пустых строк
    remove(filename.c_str());
    rename("temp.txt", filename.c_str());

    //out << "==>> Empty lines were removed from file " << filename << endl;
}