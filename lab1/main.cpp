#include "gen_files.h"
#include <iostream>
#include <fstream>

int main(){
    if(gen_files(std::cin) == 0) return 0;
    else{
        std::cout << "BIG ERROR" << std::endl;
        return 1;
    } 
}