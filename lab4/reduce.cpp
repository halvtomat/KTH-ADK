#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
using std::pair;

int main(int argc, char const *argv[]){
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    int v,e,c;
    cin >> v >> e >> c;
    vector<bool> role(v, false);
    vector<pair<pair<int,int>,pair<int,int>>> edges(e);
    
    for(int i = 0; i < e; i++){
        int a,b;
        cin >> a >> b;
        role[a-1] = true;
        role[b-1] = true;
        edges[i] = {{a,a},{b,b}};
    }

    int v2 = v;
    for(int i = 0; i < v2; i++){
        if(role[i] == false){
            v--;
            for(int j = 0; j < edges.size(); j++){
                if(edges[j].first.first > i) edges[j].first.second = edges[j].first.second-1;
                if(edges[j].second.first > i) edges[j].second.second = edges[j].second.second-1;
            }
        }
    }
    if(v < c) c = v;
    
    cout << v+3 << "\n" << e+2 << "\n" << c+3 << "\n";
    cout << "1 1\n1 2\n1 3\n";
    for(int i = 0; i < v; i++){
        cout << c;
        for(int j = 0; j < c; j++)
            cout << " " << j+4;
        cout << "\n";
    }
    cout << "2 1 3\n2 2 3\n";
    for(int i = 0; i < edges.size(); i++)
        cout << "2 " << edges[i].first.second+3 << " " << edges[i].second.second+3 << "\n";
    cout.flush();
    return 0;
}
//O(V*C+E+V)