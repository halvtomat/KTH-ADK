#include "gen_index.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class element{
    private:
        string word;
        vector<u_int16_t> indices;
    public:
        element(string word, u_int16_t index){
            word = word;
            append(index);
        }
        void append(u_int16_t index){
            indices.push_back(index);
        }
};

int gen_index(std::istream &in){
    vector<element> index_data;
    string s;
    
    while(getline(in, s)){
        int split = s.find(" ");
        string word = s.substr(0, split);
        u_int16_t  index = stoi(s.substr(split+1,s.length()));

        cout << word << endl;
        cout << index << endl;
    }

    return 0;
}

/*
    hej 0
    adssna 4
    hejdå 11
*/