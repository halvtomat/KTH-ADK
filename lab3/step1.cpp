#include <iostream>

using std::cin;
using std::cout;

int x, y;

void reduce_to_flow(){
    int e, k, u;
    cin >> x >> y >> e;
    k = 1;
    u = x + y + 2;
    cout << x+y+2 << "\n" << k << " " << u << "\n" << x+y+e << "\n";

    for(int i = 0; i < e; i++){
        int a, b;
        cin >> a >> b;
        cout << a+1 << " " << b+1 << " " << 1 << "\n";
    }
    for(int i = 1; i < x+1; i++)
        cout << k << " " << i+1  << " " << 1 << "\n";
    for(int i = 1; i < y+1; i++)
        cout << u-i << " " << u << " " << 1 << "\n";
    cout.flush();
}

void flow_to_match() {
    int v, k, u, f, e;
    cin >> v >> k >> u >> f >> e;
    cout << x << " " << y << "\n" << f << "\n";

    for (int i = 0; i < e; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if(a != k && b != u) cout << a-1 << " " << b-1 << "\n";
    }
}

int main(int argc, char const *argv[]){
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    reduce_to_flow();
    flow_to_match();
    return 0;
}