#include <iostream>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::vector;
using std::pair;
using std::find;
using std::make_pair;

int main(int argc, char const *argv[]){
    int v,e,c;
    cin >> v >> e >> c;
    vector<pair<int,int>> edges;
    
    for(int i = 0; i < v; i++){
        int a,b;
        cin >> a;
        for(int j = 0; j < a; j++)
            cin >> b;
    }
    for(int i = 0; i < e; i++){
        int a;
        cin >> a;
        vector<int> b(a);
        for(int j = 0; j < a; j++)
            cin >> b[j];
        for(int j = 0; j < a; j++){
            for(int k = j+1; k < a; k++){
                auto p = make_pair(b[j], b[k]);
                if(find(edges.begin(), edges.end(), p) == edges.end())
                    edges.push_back({b[j], b[k]});
            }
        }
    }
    cout << v << "\n" << edges.size() << "\n" << c << "\n";
    for(int i = 0; i < edges.size(); i++)
        cout << edges[i].first << " " << edges[i].second << "\n";
}
