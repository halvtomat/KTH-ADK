#include "gen_files.h"
#include "gen_hash.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;
//initialize datastructures to contain data.
map<string, vector<u_int32_t>> i_map;
u_int32_t a[22764] = {0}; //28^3 + 28^2 + 28

/**
 * Function that picks out data from tokenizer output and
 * stores it in a map. 
 * 
 * @param inputstream
 * @return void
 *
 */
void gen_i(std::istream &in){
    string s;
    while(getline(in, s)){
        int split = s.find(" ");
        string word = s.substr(0, split);
        u_int32_t  index = stoi(s.substr(split+1,s.length()));
        i_map[word].push_back(index);
    }
}
/**
 * Function that iterates through i_map in order to map the offset of i_map in a
 * if the word in i_map is less than 3 chars function will extend it with 'a's.
 * @return void
 */
void gen_a(){
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
        if(a[hash] == 0 && hash != 0) a[hash] = offset;
        offset += sizeof(u_int8_t) + sizeof(u_int32_t) + it->first.size() + it->second.size()*sizeof(u_int32_t);
    }
}
/**
 * Function that generates I_map and a, creates 2 different binary files (I-file and A-file)
 * and iterates through I_map and starts with storing the size of the word in 8 bits followed by
 * the length of the index vector in 16bits followed by the actual word and vector. 
 * 
 * To generate a_fil function iterates through a and stores the data in a_fil.
 * 
 * @param inputstream
 * @return 0
 * 
*/
int gen_files(std::istream &in){
    gen_i(in);
    gen_a();

    ofstream i_fil = ofstream("/var/tmp/i_fil.bin", ios::binary | ios::out);
    ofstream a_fil = ofstream("/var/tmp/a_fil.bin", ios::binary | ios::out);

    map<string, vector<u_int32_t>>::iterator it = i_map.begin();
    for(it; it != i_map.end(); it++){
        u_int8_t s_size = (u_int8_t)it->first.size();
        u_int32_t v_size = (u_int32_t)it->second.size();
        i_fil.write((char *) &s_size, sizeof(u_int8_t));
        i_fil.write((char *) &v_size, sizeof(u_int32_t));
        i_fil.write(it->first.c_str(), it->first.size());
        for(int i = 0; i < it->second.size(); i++)
            i_fil.write((char *)&it->second[i], sizeof(u_int32_t));
    }
    for(int i = 0; i < sizeof(a)/sizeof(u_int32_t); i++)
        a_fil.write((char *)&a[i], sizeof(u_int32_t));

    i_fil.close();
    a_fil.close();

    return 0;    
}