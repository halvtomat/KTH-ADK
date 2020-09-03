#include "gen_index.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

int gen_index(std::istream &in){
    map<string, vector<u_int32_t>> data_map;
    string s;
    
    while(getline(in, s)){
        int split = s.find(" ");
        string word = s.substr(0, split);
        u_int32_t  index = stoi(s.substr(split+1,s.length()));
        data_map[word].push_back(index);
    }
    for (auto elem : data_map){
        cout << elem.first << " : ";
        for(int i = 0; i < elem.second.size(); i++){
            cout << elem.second[i] << " ";
        }
        cout << endl;
    }

    return 0;
}

/*
    hej 0
    adssna 4
    hejdå 11
*/