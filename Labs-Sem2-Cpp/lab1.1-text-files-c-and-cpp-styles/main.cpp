#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool create_file(const string& file_path);
bool read_file(const string& file_path, string* output_lines, const int MAX_LINES);
void sort_input_lines(string* output_lines);
void write_lines(const string& output_file_path, string* output_lines);

int main() {
    string input_file_path;
    cout << "Enter input filepath: " << endl;
    cin >> input_file_path;
    cout << "Enter output filepath to create: " << endl;
    string output_file_path;
    cin >> output_file_path;
    create_file(output_file_path);
    const int MAX_LINES = 100;
    string input_lines[MAX_LINES];
    read_file(input_file_path, input_lines, MAX_LINES);
    sort_input_lines(input_lines);
    write_lines(output_file_path, input_lines);

    string final_file_path[MAX_LINES];
    cout << "READING FINAL FILE" << endl;
    read_file(output_file_path, input_lines, MAX_LINES);

    return 0;
}
void write_lines(const string& output_file_path, string* output_lines) {
    ofstream fout(output_file_path);
    for (int i = 0; i < output_lines->length(); i++) {
        fout << output_lines[i] << endl;
    }
    fout.close();
}

void sort_input_lines(string* output_lines) {
    while (true) {
        bool isSorted = true;
        for (int i = 0; i < output_lines->length() - 1; i++) {
            if (output_lines[i].length() > output_lines[i + 1].length()) {
                swap(output_lines[i], output_lines[i + 1]);
                isSorted = false;
            }
        }
        if (isSorted == true) {
            break;
        }
    }
}

bool read_file(const string& file_path, string* output_lines, const int MAX_LINES) {
    ifstream fin(file_path);
    string lines[MAX_LINES];
    int i = 0;
    while (getline(fin, lines[i])) {
        i++;
        if (i == MAX_LINES) {
            break;
        }
    }

    cout << "=== READING INPUT FILE ===" << endl;
    for (int j = 0; j < i; j++) {
        cout << lines[j] << endl;
        output_lines[j] = lines[j];
    }
    cout << "=== END ===" << endl;
    //output_lines = lines;
}

bool create_file(const string& file_path) {
    ofstream fout(file_path);
    if (fout.good()) {
        cout << "New file " << file_path << " was created successfully" << endl;
        fout.close();
        return true;
    }
    else {
        return false;
    }
}
