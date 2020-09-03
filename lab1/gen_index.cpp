#include "gen_index.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

int gen_hash(string s){
    int hash = 0;

    return hash;
}

void gen_i(std::istream &in, map<string, vector<u_int32_t>> &i){
    string s;
    while(getline(in, s)){
        int split = s.find(" ");
        string word = s.substr(0, split);
        u_int32_t  index = stoi(s.substr(split+1,s.length()));
        i[word].push_back(index);
    }
}

void gen_a(map<string, vector<u_int32_t>> i, map<u_int32_t, u_int32_t> a){
    for(int i = 0; i < 30; i++){
        char a = 'a';
        for(int j = 0; j < 30; j++){
            char b = 'a';
            for(int k = 0; k <30; k++){
                char c = 'a';
                string s = {a, b, c};
                int hash = gen_hash(s);
                c++;
            }
            b++;
        }
        a++;
    }
}

int gen_index(std::istream &in){
    map<string, vector<u_int32_t>> i_map;
    map<u_int32_t, u_int32_t> a_map;

    gen_i(in, i_map);
    //gen_a(i_map, a_map);

    for(auto elem : i_map){
        cout << elem.first << " : ";
        for(int i = 0; i < elem.second.size(); i++)
            cout << elem.second[i] << " ";
        cout << endl;
    }

    return 0;
}