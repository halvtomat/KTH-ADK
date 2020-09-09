#include "gen_files.h"
#include "gen_hash.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

map<string, vector<u_int32_t>> i_map;
u_int32_t a_map[22764] = {0}; //28^3 + 28^2 + 28

void gen_i(std::istream &in){
    string s;
    while(getline(in, s)){
        int split = s.find(" ");
        string word = s.substr(0, split);
        u_int32_t  index = stoi(s.substr(split+1,s.length()));
        i_map[word].push_back(index);
    }
}

void gen_a_2_PUNKT_NOLL(){
    map<string, vector<u_int32_t>>::iterator it = i_map.begin();
    u_int32_t offset = 0;
    for(it; it != i_map.end(); it++){
        int hash = 0;
        if(it->first.length() < 3){
            string s = {'a', 'a', 'a'};
            for(int i = 0; i < it->first.length(); i++){
                s[i] = it->first[i];
            }
            hash = gen_hash(s);
        }else hash = gen_hash(it->first.substr(0,3));
        if(a_map[hash] == 0) a_map[hash] = offset;
        offset += it->first.size() + it->second.size()*sizeof(u_int32_t);
    }
}


int gen_files(std::istream &in){
    gen_i(in);
    gen_a_2_PUNKT_NOLL();

    ofstream i_fil = ofstream("/var/tmp/i_fil.bin", ios::binary);
    ofstream a_fil = ofstream("/var/tmp/a_fil.bin", ios::binary);

    map<string, vector<u_int32_t>>::iterator it = i_map.begin();

    for(it; it != i_map.end(); it++){
        i_fil.write(it->first.c_str(), it->first.size());
        for(int i = 0; i < it->second.size(); i++)
            i_fil.write((char *)&it->second[i], sizeof(u_int32_t));
    }
    for(int i = 0; i < sizeof(a_map)/sizeof(u_int32_t); i++){
        a_fil.write((char *)&i, sizeof(i));
        a_fil.write((char *)&a_map[i], sizeof(u_int32_t));
    }

    i_fil.close();
    a_fil.close();

    return 0;
}