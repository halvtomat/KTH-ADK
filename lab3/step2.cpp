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

int cap[2000][2000] = {};
int real_flow[2000][2000] = {};
vector<vector<int>> adj;
vector<pair<int,int>> real_edge; 
int n, k, u;

int bfs(int k, int u, vector<int>& path){
    fill(path.begin(), path.end(), -1);
    path[k] = -2;
    queue<pair<int,int>> q;
    q.push({k, 200000000});
    while(!q.empty()) {
        int current = q.front().first;
        int flow = q.front().second;
        q.pop();
        for(int next : adj[current]){//cout << "Current : " << current+1 << " , Next: " << next+1 << " , path: " << path[next]+1 << " , cap: " << cap[current][next] << "\n";
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

int max_flow(int k, int u){
    int flow = 0;
    vector<int> path(n);
    int new_flow;

    while(new_flow = bfs(k, u, path)){
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
    return flow;
}

void init_graph(){
    int e;
    cin >> n >> k >> u >> e;
    cout << n << "\n" << k << " " << u << " ";

    adj.resize(n);
    for(int i = 0; i < e; i++){
        int a, b, c;
        cin >> a >> b >> c;
        if(find(adj[a-1].begin(), adj[a-1].end(), b-1) != adj[a-1].end()){
            cap[a-1][b-1] = c;
        }
        else{
            adj[a-1].push_back(b-1);
            adj[b-1].push_back(a-1);
            cap[a-1][b-1] = c;
            cap[b-1][a-1] = 0;
        }
    }
}

int main(){
    init_graph();
    int flow = max_flow(k-1, u-1);
    sort(real_edge.begin(), real_edge.end());
    cout << flow << "\n" << real_edge.size() << "\n";
    for(int i = 0; i < real_edge.size(); i++){
        int a,b,c;
        a = real_edge[i].first;
        b = real_edge[i].second;
        c = real_flow[a][b];
        cout << a+1 << " " << b+1 << " " << c << "\n";
    }
    return 0;
}
