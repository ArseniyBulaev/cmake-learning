#include <iostream>
#include <string>
#include <cmath>

#include "TutorialConfig.h"

int main(int argc, char * argv []){
    std::cout << "Project version " << basic_project_VERSION_MAJOR << "." << basic_project_VERSION_MINOR << std::endl;
    if (argc > 1){
        std::cout << "sqrt root of " << argv[1] << " equals " << std::sqrt(std::stod(argv[1])) << std::endl;
    }
    else{
        std::cout << "you haven't specified namber to calculate square root" << std::endl;
    }
    return 0;
}