#include <iostream>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::vector;
using std::find;

void reduce_to_flow(){
    int x, y, e, k, u;
    cin >> x >> y >> e;
    k = 1;
    u = x + y + 2;
    cout << u << "\n" << k << " " << u << "\n" << x +y+2 << "\n";

    vector<int> x_vec;
    vector<int> y_vec;
    for(int i = 0; i < e; i++){
        int a, b;
        cin >> a >> b;
        cout << a+1 << " " << b+1 << " " << k << "\n";
        if(find(x_vec.begin(), x_vec.end(), a) == x_vec.end()) x_vec.push_back(a);
        if(find(y_vec.begin(), y_vec.end(), a) == y_vec.end()) y_vec.push_back(b);
    }
    while(!x_vec.empty()){
        int a = x_vec.back();
        x_vec.pop_back();
        cout << k << " " << a+1  << " " << 1 << "\n";
    }
    while(!y_vec.empty()){
        int b = y_vec.back();
        y_vec.pop_back();
        cout << b+1 << " " << u << " " << 1 << "\n";
    }
    cout.flush();
}

int main(int argc, char const *argv[]){
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    reduce_to_flow();
    return 0;
}
