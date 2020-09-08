#include "gen_index.h"
#include "gen_hash.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

map<string, vector<u_int32_t>> i_map;
map<u_int32_t, u_int32_t> a_map;

u_int32_t find_index(string s, int startPos){
    map<string, vector<u_int32_t>>::iterator it = i_map.begin();
    //advance(it, startPos);
    u_int32_t offset = 0;
    for(it; it != i_map.end(); it++){
        if(it->first.substr(0,3) == s) break;

        cout << "IT-FIRST : " << it->first << endl;
        cout << "S : " << s << endl;
        cout << "SIZEOF : " << sizeof(it->first) + sizeof(it->second) << endl;

        offset += sizeof(it->first) + sizeof(it->second);
    }
    if(it == i_map.end()) offset = startPos;
    cout << offset << endl;
    return offset;
}

void gen_i(std::istream &in){
    string s;
    while(getline(in, s)){
        int split = s.find(" ");
        string word = s.substr(0, split);
        u_int32_t  index = stoi(s.substr(split+1,s.length()));
        i_map[word].push_back(index);
    }
}

void gen_a(){
    int prevPos=0;
    for(int i = 0; i < 30; i++){
        for(int j = 0; j < 30; j++){
            for(int k = 0; k < 30; k++){
                string s = {(char)('a' + i), (char)('a' + j), (char)('a' + k)};
                u_int32_t hash = gen_hash(s);
                prevPos = find_index(s, prevPos);
                a_map[hash] = prevPos;
            }
        }
    }
}

int gen_index(std::istream &in){
    

    gen_i(in);
    gen_a();

    /*for(auto elem : i_map){
        cout << elem.first << " : ";
        for(int i = 0; i < elem.second.size(); i++)
            cout << elem.second[i] << " ";
        cout << endl;
    }*/
    /*
    cout << endl << endl << endl;
    cout << "------------A FILEN BÖRJAR HÄR------------------" << endl;
    cout << endl << endl << endl;

    for(auto elem : a_map)
        cout << elem.first << " : " << elem.second << endl;
    */
    return 0;
}