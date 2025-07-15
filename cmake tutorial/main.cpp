#include <iostream>
#include <string>
#include <cmath>

#include "TutorialConfig.h"
#include "MathFunctions.h"

int main(int argc, char * argv []){
    std::cout << "Project version " << basic_project_VERSION_MAJOR << "." << basic_project_VERSION_MINOR << std::endl;
    if (argc > 1){
        mathfunctions::sqrt(std::stod(argv[1]));
    }
    else{
        std::cout << "you haven't specified namber to calculate square root" << std::endl;
    }
    return 0;
}