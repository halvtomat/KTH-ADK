#include "gen_hash.h"
#include <string>

using namespace std;

u_int32_t gen_hash(string s){
    u_int32_t hash = 0;
    hash += (s[0] - 'a')*900;
    hash += (s[1] - 'a')*30;
    hash += (s[2] - 'a');
    return hash;
}

