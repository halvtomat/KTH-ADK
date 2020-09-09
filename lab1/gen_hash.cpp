#include "gen_hash.h"
#include <string>

using namespace std;

int get_value(char c){
    switch(c){
        case (char)228:
            return 26;
        case (char)229:
            return 27;
        case (char)246:
            return 28;
        default:
            return c - 'a';
    }
}
u_int32_t gen_hash(string s){
    u_int32_t hash = 0;
    hash += get_value(s[0])*784; // 28^2
    hash += get_value(s[1])*28;
    hash += get_value(s[2]);
    return hash;
}

//ä = 228
//å = 229
//ö = 246