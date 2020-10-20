#include <iostream>
#include <vector>
#include <queue>

using std::cin;
using std::cout;
using std::vector;
using std::queue;
using std::pair;
using std::min;

vector<vector<int>> cap;
vector<vector<int>> adj;
int n;

int bfs(int k, int u, vector<int>& path){
    fill(path.begin(), path.end(), -1);
    path[k] = -2;
    queue<pair<int,int>> q;
    q.push({k, 200000000});

    while(!q.empty()) {
        int current = q.front().first;
        int flow = q.front().second;
        q.pop();

        for(int next : adj[current]){
            if(path[next] == -1 && cap[current][next]) {
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
    vector<int> path(100);
    int new_flow;

    while(new_flow = bfs(k, u, path)){
        flow += new_flow;
        int current = u;
        while(current != k){
            int prev = path[current];
            cap[prev][current] -= new_flow;
            cap[current][prev] += new_flow;
            current = prev;
        }
    }
    return flow;
}

void solve_flow(){

}

void init_graph(){
    int v, k, u, f, e;
    cin >> v >> k >> u >> f >> e;
    cout << v << "\n" << k << " " << u << " ";
    n = v;
    adj.resize(e);
    cap.resize(e);

    for(int i = 0; i < e; i++){
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back(b);
        adj[b].push_back(a);
        cap[a].push_back(c);
        cap[b].push_back(c);
    }
}

int main(){
    init_graph();
    int flow = max_flow(1,n);
    return 0;
}
