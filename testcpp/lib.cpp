#include <iostream>

#include "lib.h"

namespace cmakelib{

    void say_hello(){
        std::cout << "In lib.cpp!" << std::endl;
        std::cout << "Hello World!" << std::endl;
    }
}