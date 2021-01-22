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
    actors.resize(k+n+1);
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

bool role_check(int d1, int d2){ //True if roles dont play against each other, otherwise false
    for(int i = 0; i < scenes.size(); i++){
        if(find(scenes[i].begin(), scenes[i].end(), d1) != scenes[i].end())
            if(find(scenes[i].begin(), scenes[i].end(), d2) != scenes[i].end())
                return false;
    }
    return true;
}

bool actor_check(int actor, int role){ 
    if(actor == 1 || actor == 2){
        for(int i = 0; i < actors[1].size(); i++){
            if(role_check(actors[1][i]+1, role) == false)
                return false;
        }
        for(int i = 0; i < actors[2].size(); i++){
            if(role_check(actors[2][i]+1, role) == false)
                return false;
        }
    }
    else{
        for(int i = 0; i < actors[actor].size(); i++){
            if(role_check(actors[actor][i]+1, role) == false)
                return false;
        }
    }
    return true;
}

void solve(){
    vector<int> diva1;
    vector<int> diva2;

    for(int i = 0; i < n; i++){                                                 //Tar ut alla de rollerna divorna kan spela
        if(find(roles[i].begin(), roles[i].end(), 1) != roles[i].end())
            diva1.push_back(i);
        if(find(roles[i].begin(), roles[i].end(), 2) != roles[i].end())
            diva2.push_back(i);
    }
    for(int i = 0; i < diva1.size(); i++){                                     
        for(int j = 0; j < diva2.size(); j++){
            if(role_check(diva1[i]+1, diva2[j]+1)){
                actors[1].push_back(diva1[i]);
                actors[2].push_back(diva2[j]);
                roles[diva1[i]].clear();
                roles[diva2[j]].clear();
                break;
            }
        }
        if(actors[1].empty() == false)
            break;
    }

    for(int i = 0; i < roles.size(); i++){
        for(int j = 0; j < roles[i].size(); j++){
            int actor_nr = roles[i][j];
            if(actor_check(actor_nr, i+1)){
                actors[actor_nr].push_back(i);
                roles[i].clear();
            }
        }
    }

    int a = k + 1;
    for(int i = 0; i < n; i++){ 
        if(roles[i].empty() == false)
            actors[a++].push_back(i);
    }
}

void print(){
    int actor_count = 0;
    for(int i = 0; i < actors.size(); i++){
        if(actors[i].empty() == false)
            actor_count++;
    }
    cout << actor_count << "\n";
    for(int i = 0; i < actors.size(); i++){
        if(actors[i].empty() == false){
            cout << i << " " << actors[i].size();
            for(int j = 0; j < actors[i].size(); j++){
                cout << " " << actors[i][j]+1;
            }
            cout << "\n";
        }
    }
}

int main(int argc, char const *argv[]){
    read();
    solve();
    print();
    return 0;
}