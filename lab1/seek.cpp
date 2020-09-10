#include "gen_hash.h"
#include <stdio.h>
#include <iostream>
#include <fstream>

using namespace std;

u_int32_t a[22764] = {0}; //28^3 + 28^2 + 28

/*u_int32_t* search(u_int32_t lower, u_int32_t upper, string s){
    ifstream i_fil = ifstream("/var/tmp/i_fil.bin", ios::binary);
    i_fil.seekg(lower);
    for(int i = 0; i < upper-lower; i++){
        if(i_fil.read)
    }
}*/

int find_upper(int lower){
    int upper = lower+1;
    while(a[upper]==0){
        upper++;
    }
    return upper;
}

int find_lower(string s){
    int lower = gen_hash(s);
    if(s == "aaa") return lower;
    while(a[lower]==0){
        lower--;
    }
    return lower;
}

string get_string(string s){
    string new_s = {'a', 'a', 'a'};
    for(int i = 0; i < s.length() && i < 3; i++)
        new_s[i] = s[i];
    return new_s;
}

int main(int argc, char const *argv[]){
    if(argc > 2){
        cout << "Too many arguments!!!" << endl;
        return 1;
    }
    string s = argv[1];

    ifstream a_fil = ifstream("/var/tmp/a_fil.bin", ios::binary | ios::in);

    for(int i = 0; !a_fil.eof(); i++){
        a_fil.read((char *)&a[i], sizeof(u_int32_t));
    }

    string tmp = get_string(s);
    u_int32_t lower = a[find_lower(tmp)];
    u_int32_t upper = a[find_upper(gen_hash(tmp))];

    return 0;
}
