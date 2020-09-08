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
u_int32_t a_map[27000] = {0};

u_int32_t find_index(string s, int &pos){
    map<string, vector<u_int32_t>>::iterator it = i_map.begin();
    advance(it, pos);
    int hash = gen_hash(s);
    u_int32_t offset = 0;
    if(s != "aaa") offset = a_map[gen_hash(s)-1];
    for(it; it != i_map.end(); it++){
        int it_hash = gen_hash(it->first.substr(0,3));
        if(it_hash == hash){
            //cout << "POSITION = " << pos << endl;
            //cout << "HASH = " << hash << " : IT_HASH = " << it_hash << endl;
            //cout << "OFFSET = " << offset << endl;
            break;
        } 
        /*if(it_hash > hash){
            offset = 0;
            if(s != "aaa") offset = a_map[gen_hash(s)-1];
            break;
        }*/
        //cout << it->first << endl;
        pos++;
        offset += it->first.size() + it->second.size()*sizeof(u_int32_t);
        //cout << "OFFSET++ = " << offset << endl;
    }
    if(it == i_map.end()){
        pos = 0;
        offset = 0;
        if(s != "aaa") offset = a_map[gen_hash(s)-1];
    }
    //cout << offset << endl;
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

/*
void gen_a(){
    int prevPos = 0;
    
    for(int i = 0; i < 30; i++){
        for(int j = 0; j < 30; j++){
            for(int k = 0; k < 30; k++){
                string s = {(char)('a' + i), (char)('a' + j), (char)('a' + k)};
                u_int32_t hash = gen_hash(s);
                a_map[hash] = find_index(s, prevPos);
                cout << k + j*30 + i*900 << endl;
            }
        }
    }
    
}
*/


void gen_a_2_PUNKT_NOLL(){
    map<string, vector<u_int32_t>>::iterator it = i_map.begin();
    u_int32_t offset = 0;
    for(it; it != i_map.end(); it++){
        cout << it->first << endl;
        int hash = 0;
        if(it->first.length() < 3){
            string s = {' ', ' ', ' '};
            for(int i = 0; i < it->first.length(); i++){
                s[i] = it->first[i];
            }
            for(int i = 2; i > it->first.length(); i--){
                s[i] = 'a';
            }
            hash = gen_hash(s);
        }else hash = gen_hash(it->first.substr(0,3));
        if(a_map[hash] == 0) a_map[hash] = offset;
        offset += it->first.size() + it->second.size()*sizeof(u_int32_t);
    }
}


int gen_index(std::istream &in){
    

    gen_i(in);
    gen_a_2_PUNKT_NOLL();

    cout << endl << endl << endl;
    cout << "------------I FILEN BÖRJAR HÄR------------------" << endl;
    cout << endl << endl << endl;

    /*for(auto elem : i_map){
        cout << elem.first << " : ";
        for(int i = 0; i < elem.second.size(); i++)
            cout << elem.second[i] << " ";
        cout << endl;
    }
    
    cout << endl << endl << endl;
    cout << "------------A FILEN BÖRJAR HÄR------------------" << endl;
    cout << endl << endl << endl;
    
    for(int i = 0; i < 27000; i++)
        cout << i << " : " << a_map[i] << endl;
    */
    return 0;
}