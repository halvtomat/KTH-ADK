#include <iostream>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::pair;
using std::vector;
using std::find;


int n, s, k;                 // n = antal roller, s = antal scener, k = antal skådespelare
vector<vector<int>> roles;   // GLÖM INTE 0 INDEX
vector<vector<int>> scenes;
vector<vector<int>> actors;  // GLÖM INTE 0 INDEX, SKÅDESPELARE 0 ÄR ILLEAGAL

void read(){
    cin >> n >> s >> k;
    roles.resize(n);
    scenes.resize(s);
    actors.resize(k+n-1);
    int a,b;
    for(int i = 0; i < n; i++){
        cin >> a;
        for(int j = 0; j < a; j++){
            cin >> b;
            roles[i].push_back(b);
        }
    }
    for(int i = 0; i < s; i++){
        cin >> a;
        for(int j = 0; j < a; j++){
            cin >> b;
            scenes[i].push_back(b);
        }
    }
}

bool diva_check(int d1, int d2){
    for(int i = 0; i < s; i++){
        if(find(scenes[i].begin(), scenes[i].end(), d1) != scenes[i].end())
            if(find(scenes[i].begin(), scenes[i].end(), d2) != scenes[i].end())
                return false;
    }
    return true;
}

void solve(){ // By Valle
    vector<int> diva1;
    vector<int> diva2;

    for(int i = 0; i < n; i++){
        if(find(roles[i].begin(), roles[i].end(), 1) != roles[i].end())
            diva1.push_back(i);
        if(find(roles[i].begin(), roles[i].end(), 2) != roles[i].end())
            diva2.push_back(i);
    }
    for(int i = 0; i < diva1.size(); i++){
        for(int j = 0; j < diva2.size(); j++){
            if(diva_check(diva1[i]+1, diva2[j]+1)){
                actors[1].push_back(diva1[i]);
                actors[2].push_back(diva2[j]);
            }
        }
    }
    int a = k+1;
    for(int i = 0; i < n; i++){ 
        if(i != actors[1][0] && i != actors[2][0])
            actors[a++].push_back(i);
    }
}

void print(){
    cout << n << "\n";
    for(int i = 0; i < actors.size(); i++){
        if(actors[i].empty() == false){
            cout << i << " 1 " << actors[i][0]+1 << "\n";
        }
    }
}

int main(int argc, char const *argv[]){
    read();
    solve();
    print();
    return 0;
}
