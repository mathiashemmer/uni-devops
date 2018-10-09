#ifndef AUXLIB_H
#define AUXLIB_H

#include <iostream>
#include <sstream>
#include <../lib/educore.h>

int get_int(int min, std::string prompt)
{
    int ret_integer;
    std::string str_number;

    while(true)
    {
        std::cout << prompt;
        std::getline(std::cin, str_number);
        std::stringstream convert(str_number);

        if(convert>> ret_integer && !(convert >> str_number) && ret_integer >= min) return ret_integer;

        std::cin.clear();
        clearScreen();
        std::cerr << "Apenas valores maiores que " << min-1 << std::endl;
    }
}

#endif // AUXLIB_H
