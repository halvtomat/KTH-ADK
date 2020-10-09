#include <iostream>
#include <vector>

int vertix_amount(){
    int x,y;
    std::cin >> x;
    std::cin >> y;
    return x + y;
}

void add_edge(std::vector<int> adj[], int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int main(int argc, char const *argv[]){
    int v_size = vertix_amount();
    std::vector<int> adj[v_size];
    int n = 0;
    std::cin >> n;
    for (int i = 0; i < n; i++){
        int v, u;
        std::cin >> v;
        std::cin >> u;
        add_edge(adj,u,v);
    }

    return 0;
}
