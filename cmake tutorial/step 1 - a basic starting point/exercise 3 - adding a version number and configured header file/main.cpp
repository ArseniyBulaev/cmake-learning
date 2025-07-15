#include <iostream>
#include <string>

#include "TutorialConfig.h"

int main(){
    std::cout << "Project version " << basic_project_VERSION_MAJOR << "." << basic_project_VERSION_MINOR << std::endl;
    std::cout << "Hello Cmake " << std::stod("99") + 1 << std::endl;
    return 0;
}