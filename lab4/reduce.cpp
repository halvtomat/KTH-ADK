#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
using std::string;
using std::to_string;

int main(int argc, char const *argv[]){
    int v,e,c;
    cin >> v >> e >> c;
    vector<bool> role(v);
    string s;
    if(v < c) c = v;

    s.append("1 1\n1 2\n");
    for(int i = 0; i < v; i++){
        role[i] = false;
        s.append(to_string(c));
        for(int j = 0; j < c; j++)
            s.append(" " + to_string(j+3));
        s.append("\n");
    }

    s.append("2 1 3\n2 2 3\n");
    role[0] = true;
    for(int i = 0; i < e; i++){
        int a,b;
        cin >> a >> b;
        role[a] = true;
        role[b] = true;
        s.append("2 " + to_string(a+2) + " " + to_string(b+2) + "\n");
    }

    for(int i = 0; i < v; i++){
        if(role[i] == false){
            e++;
            s.append("2 1 " + to_string(i+3) + "\n");
        }
    }

    cout << v+2 << "\n" << e+2 << "\n" << c+2 << "\n";
    cout << s;
    
    return 0;
}