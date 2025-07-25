#include <iostream>
#include <string>
#include <cmath>

#include "TutorialConfig.h"
#include "MathFunctions.h"

int main(int argc, char * argv []){
    std::cout << "Project version " << Tutorial_VERSION_MAJOR << "." <<  Tutorial_VERSION_MINOR << std::endl;
    if (argc > 1){
       double sqrt_value = mathfunctions::sqrt(std::stod(argv[1]));
       std::cout << "square root of " << argv[1] << " equals " << sqrt_value << std::endl;
    }
    else{
        std::cout << "you haven't specified namber to calculate square root" << std::endl;
    }
    return 0;
}