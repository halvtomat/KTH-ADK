#include "gen_hash.h"
#include <stdio.h>
#include <iostream>
#include <fstream>

using namespace std;

u_int32_t a[22764] = {0}; //28^3 + 28^2 + 28

u_int32_t* search(u_int32_t lower, u_int32_t upper, string s){
    ifstream i_fil = ifstream("/var/tmp/i_fil.bin", ios::binary);
    i_fil.seekg(lower);
    u_int8_t word_size = 0;
    u_int16_t v_size = 0;
    i_fil.read(reinterpret_cast<char *>(&word_size), sizeof(word_size));
    i_fil.read(reinterpret_cast<char *>(&v_size), sizeof(v_size));
    string word = "";
    i_fil.read((char *)&word, word_size);
    cout << "current word_size is = " << unsigned(word_size) << endl;
    cout << "current v_size is = " << v_size << endl;
    cout << "current word is = " << word << endl;

    return 0;
}


u_int32_t find_upper(string s){
    u_int32_t upper = gen_hash(s)+1;
    while(a[upper] == 0 && upper < sizeof(a)/sizeof(u_int32_t)){
        upper++;
        cout << "current upper = " << upper << endl;
    }
    return upper;
}

u_int32_t find_lower(string s){
    u_int32_t lower = gen_hash(s);
    while(a[lower] == 0 && lower > 0){
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

void load_a(){
    ifstream a_fil = ifstream("/var/tmp/a_fil.bin", ios::binary | ios::in);
    for(int i = 0; !a_fil.eof(); i++){
        a_fil.read((char *)&a[i], sizeof(u_int32_t));
    }
    a_fil.close();
}

int main(int argc, char const *argv[]){
    if(argc > 2){
        cout << "Too many arguments!!!" << endl;
        return 1;
    }
    string s = argv[1];
    load_a();

    string tmp = get_string(s);
    u_int32_t lower = a[find_lower(tmp)];
    u_int32_t upper = a[find_upper(tmp)];
    cout << "lower : " << lower << endl;
    cout << "upper : " << upper << endl;

    search(lower, upper, s);
    return 0;
}
