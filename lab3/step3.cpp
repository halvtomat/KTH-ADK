#include <iostream>
#include <vector>
#include <queue>
#include <unistd.h>
#include <algorithm>

using std::cin;
using std::cout;
using std::vector;
using std::queue;
using std::pair;
using std::find;
using std::remove;
using std::make_pair;
using std::min;

int16_t x, y, k, u, n, f;
bool cap[10002][10002] = {};
bool real_flow[10002][10002] = {};
vector<vector<int16_t>> adj;
vector<pair<int16_t,int16_t>> real_edge;

bool bfs(vector<int16_t>& path){
    fill(path.begin(), path.end(), -1);
    path[k] = -2;
    queue<int16_t> q;
    q.push(k);
    while(!q.empty()) {
        int16_t current = q.front();
        q.pop();
        for(int16_t next : adj[current]){
            if(path[next] == -1 && cap[current][next]) {
                path[next] = current;
                if(next == u) return true;
                q.push(next);
            }
        }
    }
    return false;
}

void max_flow(){
    int16_t flow = 0;
    vector<int16_t> path(n);

    while(bfs(path)){
        flow++;;
        int16_t current = u;

        while(current != k){
            int16_t prev = path[current];
            cap[prev][current] = false;
            cap[current][prev] = true;

            if(!real_flow[current][prev]){
                real_edge.push_back({prev, current});
                real_flow[prev][current] = true;
            }
            else{
                auto p = make_pair(current, prev);
                real_edge.erase(remove(real_edge.begin(), real_edge.end(), p), real_edge.end());
                real_flow[current][prev] = false;
            }
            current = prev;
        }
    }
    f = flow;
}

void add_edge(int16_t a, int16_t b, bool c){
    if(find(adj[a].begin(), adj[a].end(), b) != adj[a].end()){
        cap[a][b] = c;
    }
    else{
        adj[a].push_back(b);
        adj[b].push_back(a);
        cap[a][b] = c;
        cap[b][a] = false;
    }
}

void reduce_to_flow(){
    int e;
    cin >> x >> y >> e;
    k = 0;
    u = x + y + 1;
    n = x + y + 2;

    adj.resize(n);

    for(int i = 0; i < e; i++){
        int16_t a, b;
        cin >> a >> b;
        add_edge(a,b,true);
    }
    for(int i = 1; i < x+1; i++)
        add_edge(k,i,true);
    for(int i = 1; i < y+1; i++)
        add_edge(x+i,u,true);
}

void flow_to_match() {
    cout << x << " " << y << "\n" << f << "\n";
    for (int i = 0; i < real_edge.size(); i++) {
        int16_t a = real_edge[i].first;
        int16_t b = real_edge[i].second;
        if(a != k && b != u) cout << a << " " << b << "\n";
    }
    cout.flush();
}

int main(int argc, char const *argv[]){
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    reduce_to_flow();
    max_flow();
    sort(real_edge.begin(), real_edge.end());
    flow_to_match();
    return 0;
}