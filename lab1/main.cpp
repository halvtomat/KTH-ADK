#include "gen_index.h"
#include <iostream>
#include <fstream>

using namespace std;


int main(){
    if(gen_index(cin) == 0) return 0;
    else{
        cout << "BIG ERROR" << endl;
        return 1;
    } 
}