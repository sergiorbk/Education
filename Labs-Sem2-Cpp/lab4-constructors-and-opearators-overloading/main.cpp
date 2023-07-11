#include <windows.h>
#include "Activity.h"

using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    while(true){
        Activity::call();

        if(OutputHandler::is_exit()){
            break;
        }
    }
    return 0;
}