#include <iostream>
#include <vector>
#include <queue>
#include <unistd.h>
#include <algorithm>

using std::cin;
using std::cout;
using std::vector;
using std::find;
using std::queue;
using std::pair;
using std::remove;
using std::make_pair;
using std::min;

int x, y, k, u, n, f;
int cap[10000][10000] = {};
int real_flow[10000][10000] = {};
vector<vector<int>> adj;
vector<pair<int,int>> real_edge;

int bfs(vector<int>& path){
    fill(path.begin(), path.end(), -1);
    path[k] = -2;
    queue<pair<int,int>> q;
    q.push({k, 200000000});
    while(!q.empty()) {
        int current = q.front().first;
        int flow = q.front().second;
        q.pop();
        for(int next : adj[current]){
            if(path[next] == -1 && cap[current][next] > 0) {
                path[next] = current;
                int new_flow = min(flow, cap[current][next]);
                
                if(next == u) return new_flow;
                q.push({next, new_flow});
            }
        }
    }
    return 0;
}

void max_flow(){
    int flow = 0;
    vector<int> path(n);
    int new_flow;

    while(new_flow = bfs(path)){
        flow += new_flow;
        int current = u;

        while(current != k){
            int prev = path[current];
            cap[prev][current] -= new_flow;
            cap[current][prev] += new_flow;

            if(real_flow[current][prev] == 0){
                if(real_flow[prev][current] == 0)
                    real_edge.push_back({prev, current});
                real_flow[prev][current] += new_flow;
            }
            else{
                if(real_flow[current][prev] > new_flow)
                    real_flow[current][prev] -= new_flow;
                else{
                    auto p = make_pair(current, prev);
                    real_edge.erase(remove(real_edge.begin(), real_edge.end(), p), real_edge.end());
                    if(real_flow[current][prev] < new_flow){
                        real_edge.push_back({prev, current});
                        real_flow[prev][current] = new_flow;
                    }
                    real_flow[current][prev] = 0;
                }
            }
            current = prev;
        }
    }
    f = flow;
}

void add_edge(int a, int b, int c){
    if(find(adj[a].begin(), adj[a].end(), b) != adj[a].end()){
        cap[a][b] = c;
    }
    else{
        adj[a].push_back(b);
        adj[b].push_back(a);
        cap[a][b] = c;
        cap[b][a] = 0;
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
        int a, b;
        cin >> a >> b;
        add_edge(a,b,1);
    }
    for(int i = 1; i < x+1; i++)
        add_edge(k,i,1);
    for(int i = 1; i < y+1; i++)
        add_edge(x+i,u,1);
}

void flow_to_match() {
    cout << x << " " << y << "\n" << f << "\n";

    for (int i = 0; i < real_edge.size(); i++) {
        int a = real_edge[i].first;
        int b = real_edge[i].second;
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