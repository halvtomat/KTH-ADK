#include <iostream>

using std::cin;
using std::cout;

int main(int argc, char const *argv[]){
    int n = 0;
    cin >> n;
    n = n+2;
    cout << n << "\n";

    int a = 0;
    for(int i = 0; i < n; i++){
        cin >> a;
        for(int j = 0; j < n; j++){
            if(i == j && (i != 0 && i != n-1))
                cout << a << " ";
            else
                cout << "0 ";
        }
        cout << "\n";
    }
    cin >> a;
    cout << a << "\n";
    
    return 0;
}