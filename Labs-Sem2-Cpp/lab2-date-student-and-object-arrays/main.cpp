#include <Windows.h>
#include "StudentsArray.h"
#include "StudentsFactory.h"

using namespace std;

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    while(true){
        StudentsArray students;
        StudentsFactory::fill_students_array(&students); // filling students array
        students.read_students_array(); //reading filled students' array
        // comparing date input
        students.find_oldest_student(StudentsFactory::create_comparing_date());
        // asking user for exiting
        if(StudentsFactory::is_exit_program()){
            break;
        }else{
            system("cls");
        }
    }
    return 0;
}