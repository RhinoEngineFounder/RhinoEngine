#pragma once
#include <iostream>

#define DEBUG(m, x) std::cout << m << x << std::endl;
#define MESSAGE(m) std::cout << m << std::endl;

#define FATAL_ERROR(m) \
        std::cerr << m << std::endl;
        //std::terminate();