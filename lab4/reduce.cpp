#include <iostream>

using std::cin;
using std::cout;

int main(int argc, char const *argv[]){
    int v,e,c;
    cin >> v >> e >> c;
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
    for(int i = 0; i < e; i++){
        int a,b;
        cin >> a >> b;
        cout << 2 << " " << a+3 << " " << b+3 << "\n";
    }
    return 0;
}