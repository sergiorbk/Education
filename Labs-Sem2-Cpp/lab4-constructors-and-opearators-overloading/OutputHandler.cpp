#include "OutputHandler.h"
void OutputHandler::show_coordinates(const Vector& vector){
    cout << "==>> " << vector.get_name() << " coordinates are ( ";
    for (int i = 1; i <= vector.get_dimension(); i++) {
        std::cout << vector.get_coordinate(i) << " ";
    }
    cout << ")." << endl;
}

void OutputHandler::show_length(const Vector& vector){
    cout << "==>> Vector " << vector.get_name() << "'s length (absolute) is: " << vector.length() << endl;
}

bool OutputHandler::is_exit(){
    cout << endl << "Do you want to continue using program?" << endl;
    cout << "Press ANY KEY to continue or [1] to exit..." << endl;
    if(getch() == '1'){
        return true;
    }else{
        system("cls");
        return false;
    }
}