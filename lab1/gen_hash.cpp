#include "gen_hash.h"
#include <string>

using namespace std;
/**
 * Function that gives a value between 0-28 corresponding to the swedish alphabet.
 * @param char
 * @return integer
 * 
*/
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
/**
 * Function that generates a hash value based on 3 letters which will be the index in a_fil corresponding
 * to that 3 letter combination
 * 
 * @param string
 * @return integer
 */
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