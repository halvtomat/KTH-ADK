#include "gen_hash.h"
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

const int PRINT_LENGTH = 60;

u_int32_t a[22765] = {0}; //28^3 + 28^2 + 28 + 1

void print_konkordans(u_int32_t offset, int word_size, ifstream &korpus){
    if(offset > PRINT_LENGTH/2) korpus.seekg(offset - PRINT_LENGTH/2 + word_size / 2);
    if(offset + PRINT_LENGTH/2 > 79506700) korpus.seekg(offset - PRINT_LENGTH + word_size);
    string s (PRINT_LENGTH, ' ');
    korpus.read(&s[0], PRINT_LENGTH);
    replace(s.begin(), s.end(), '\n', ' ');
    cout << s << endl;
}

/**
 * Function that iterates the I-fil between lower and upper bound in search of 
 * the given string value. Reads the first 8 bits to know the size of the word and the followed 16 bits
 * to know the size of the vector. If we find the word we store the byteoffset values in korpus in a vector.
 * @param u_int32_t, string
 * @return vector
 * 
*/
vector<u_int32_t> search(u_int32_t lower, u_int32_t upper, string s){
    ifstream i_fil = ifstream("/var/tmp/i_fil.bin", ios::binary);
    ifstream korpus = ifstream("./korpus");
    i_fil.seekg(lower);
    vector<u_int32_t> v;
    while(i_fil.tellg() < upper){
        u_int8_t word_size = 0;
        u_int32_t v_size = 0;
        i_fil.read(reinterpret_cast<char *>(&word_size), sizeof(word_size));
        i_fil.read(reinterpret_cast<char *>(&v_size), sizeof(v_size));
        string word = "";
        word.resize(word_size);
        i_fil.read(&word[0], word.size());
        if(s == word){
            for(int j = 0; j < v_size; j++){
                if(v_size > 20 && j == 20){
                   cout << "Word Count = " << v_size << "\nDo you want to print the rest? (y/n)\n"; 
                   if(getchar() != 121) break;
                }
                u_int32_t elem;
                i_fil.read(reinterpret_cast<char *>(&elem), sizeof(u_int32_t));
                print_konkordans(elem, word_size, korpus);
            }
            cout << "Word Count = " << v_size << endl;
            break;
        }

        u_int32_t jump = v_size*sizeof(u_int32_t) + i_fil.tellg();
        i_fil.seekg(jump);
    }
    i_fil.close();
    korpus.close();
    return v;
}

u_int32_t find_upper(string s){
    u_int32_t upper = gen_hash(s)+1;
    while(a[upper] == 0 && upper < sizeof(a)/sizeof(u_int32_t)){
        upper++;
    }
    if(upper == sizeof(a)/sizeof(u_int32_t)) return 22765;
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
    a[22765] = 56961858;
}

int main(int argc, char const *argv[]){
    if(argc != 2){
        cout << "Check your arguments" << endl;
        return 1;
    }
    
    string s = argv[1];
    load_a();

    string tmp = get_string(s);
    u_int32_t lower = a[find_lower(tmp)];
    u_int32_t upper = a[find_upper(tmp)];

    search(lower, upper, s);

    return 0;
}
